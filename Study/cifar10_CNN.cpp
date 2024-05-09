// ChatGPT를 통해 구성해 두었던 Cifar10을 C++로 학습 코드를 변경

#include <torch/torch.h>
#include <torch/script.h>
#include <iostream>
#include <vector>
#include <string>

using namespace torch;
using namespace torch::nn;
using namespace torch::optim;
using namespace torchvision::datasets;
using namespace torchvision::transforms;
using namespace std;

// Define my CNN Model (2 conv layers)
class MyNNImpl : public nn::Module {
public:
	MyNNImpl() :
		conv1(nn::Conv2d(nn::Conv2dOptions(3, 32, 3).stride(1).padding(1))),
		relu1(nn::ReLU()),
		pool1(nn::MaxPool2d(nn::MaxPool2dOptions(2).stride(2))),
		conv2(nn::Conv2d(nn::Conv2dOptions(32, 64, 3).stride(1).padding(1))),
		relu2(nn::ReLU()),
		pool2(nn::MaxPool2d(nn::MaxPool2dOptions(2).stride(2))),
		fc(8 * 8 * 64, 10)
	{
		register_module("conv1", conv1);
		register_module("relu1", relu1);
		register_module("pool1", pool1);
		register_module("conv2", conv2);
		register_module("relu2", relu2);
		register_module("pool2", pool2);
		register_module("fc", fc);

		torch::nn::init::xavier_uniform_(fc->weight);
	}

	torch::Tensor forward(torch::Tensor x) {
		x = pool1->forward(relu1->forward(conv1->forward(x)));
		x = pool2->forward(relu2->forward(conv2->forward(x)));
		x = x.view({ x.size(0), -1 });
		x = fc->forward(x);
		return x;
	}

	torch::nn::Conv2d conv1, conv2;
	torch::nn::ReLU relu1, relu2;
	torch::nn::MaxPool2d pool1, pool2;
	torch::nn::Linear fc;
};

TORCH_MODULE(MyNN);

int main() {
	auto device = torch::cuda::is_available() ? torch::kCUDA : torch::kCPU;

	// CIFAR-10 dataset
	auto transform = transforms::Compose(
		transforms::ToTensor(),
		transforms::RandomHorizontalFlip(),
		transforms::Normalize({ 0.5, 0.5, 0.5 }, { 0.5, 0.5, 0.5 })
	);

	auto trainset = CIFAR10("./data", CIFAR10::Mode::kTrain)
		.map(transform)
		.map(torch::data::transforms::Stack<>());
	auto trainloader = torch::data::make_data_loader<torch::data::samplers::RandomSampler>(
		std::move(trainset), torch::data::DataLoaderOptions().batch_size(4).workers(2));

	auto testset = CIFAR10("./data", CIFAR10::Mode::kTest)
		.map(transform)
		.map(torch::data::transforms::Stack<>());
	auto testloader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(
		std::move(testset), torch::data::DataLoaderOptions().batch_size(4).workers(2));

	vector<string> classes = { "plane", "car", "bird", "cat", "deer", "dog", "frog", "horse", "ship", "truck" };

	cout << "total training samples : " << 4 * trainloader->size().value() << endl;
	cout << "total test samples : " << 4 * testloader->size().value() << endl;

	// instantiate CNN model
	auto model = std::make_shared<MyNN>();
	model->to(device);

	// hyperparameters
	double learning_rate = 0.001;
	int training_epochs = 2;

	// define cost/loss & optimizer
	auto criterion = nn::CrossEntropyLoss().to(device);
	auto optimizer = optim::Adam(model->parameters(), optim::AdamOptions(learning_rate));

	cout << "Training Start!" << endl;

	for (int epoch = 0; epoch < training_epochs; ++epoch) {
		double running_loss = 0.0;
		for (auto& batch : *trainloader) {
			auto inputs = batch.data.to(device);
			auto labels = batch.target.to(device);

			optimizer.zero_grad();
			auto outputs = model->forward(inputs);
			auto loss = criterion(outputs, labels);
			loss.backward();
			optimizer.step();

			running_loss += loss.item<double>() / trainloader->size().value();
		}
		cout << "[Epoch: " << (epoch + 1) << "] loss = " << running_loss << endl;
	}

	cout << "Training Finished !" << endl;

	// Testing
	auto dataiter = testloader->begin();
	auto images = dataiter->data.to(device);
	auto labels = dataiter->target;
	auto outputs = model->forward(images);

	cout << "GroundTruth: ";
	for (int j = 0; j < 4; ++j) {
		cout << classes[labels[j].item<int>()] << " ";
	}
	cout << endl;

	auto predicted = std::get<1>(torch::max(outputs, 1));
	cout << "predicted: ";
	for (int j = 0; j < 4; ++j) {
		cout << classes[predicted[j].item<int>()] << " ";
	}
	cout << endl;

	// Calculate accuracy
	int correct = 0;
	int total = 0;
	model->eval();
	for (const auto& batch : *testloader) {
		auto images = batch.data.to(device);
		auto labels = batch.target.to(device);
		auto outputs = model->forward(images);
		auto predicted = std::get<1>(torch::max(outputs, 1));
		total += labels.size(0);
		correct += (predicted == labels).sum().item<int>();
	}
	cout << "Accuracy of the network on the 10000 test images: " << (100 * correct / total) << " %" << endl;

	// Calculate class-wise accuracy
	vector<int> class_correct(10, 0);
	vector<int> class_total(10, 0);
	for (const auto& batch : *testloader) {
		auto images = batch.data.to(device);
		auto labels = batch.target.to(device);
		auto outputs = model->forward(images);
		auto predicted = std::get<1>(torch::max(outputs, 1));
		auto c = (predicted == labels).to(torch::kCPU);
		for (int i = 0; i < 4; ++i) {
			int label = labels[i].item<int>();
			class_correct[label] += c[i].item<int>();
			class_total[label]++;
		}
	}
	for (int i = 0; i < 10; ++i) {
		cout << "Accuracy of " << classes[i] << " : " << (100 * class_correct[i] / class_total[i]) << " %" << endl;
	}

	return 0;
}
