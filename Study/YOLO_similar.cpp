//#include <torch/torch.h>
//#include <torch/script.h>
//#include <iostream>
//#include <vector>
//#include <string>
//
//// 모델구조
//struct YOLOImpl : public torch::nn::Module {
//	YOLOImpl() {
//		conv1 = register_module("conv1", torch::nn::Conv2d(3, 16, 3).stride(1).padding(1));
//		bn1 = register_module("bn1", torch::nn::BatchNorm2d(16));
//		conv2 = register_module("conv2", torch::nn::Conv2d(16, 32, 3).stride(1).padding(1));
//		bn2 = register_module("bn2", torch::nn::BatchNorm2d(32));
//		conv3 = register_module("conv3", torch::nn::Conv2d(32, 64, 3).stride(1).padding(1));
//		bn3 = register_module("bn3", torch::nn::BatchNorm2d(64));
//		fc1 = register_module("fc1", torch::nn::Linear(8 * 8 * 64, 256));
//		fc2 = register_module("fc2", torch::nn::Linear(256, 10)); // For CIFAR-10, 10 classes
//	}
//
//	torch::Tensor forward(torch::Tensor x) {
//		x = torch::relu(bn1(conv1(x)));
//		x = torch::max_pool2d(x, 2);
//		x = torch::relu(bn2(conv2(x)));
//		x = torch::max_pool2d(x, 2);
//		x = torch::relu(bn3(conv3(x)));
//		x = torch::max_pool2d(x, 2);
//		x = x.view({ -1, 8 * 8 * 64 });
//		x = torch::relu(fc1(x));
//		x = fc2(x);
//		return x;
//	}
//
//	torch::nn::Conv2d conv1{ nullptr }, conv2{ nullptr }, conv3{ nullptr };
//	torch::nn::BatchNorm2d bn1{ nullptr }, bn2{ nullptr }, bn3{ nullptr };
//	torch::nn::Linear fc1{ nullptr }, fc2{ nullptr };
//};
//
//TORCH_MODULE(YOLO);
//
//
//
//
//
//
//
////데이터셋 및 데이터 로더
//#include <torch/torch.h>
//#include <torch/data/datasets/base.h>
//#include <torch/data/example.h>
//#include <torch/data/samplers/random.h>
//#include <torch/data/transforms/tensor.h>
//#include <torch/data/transforms/stack.h>
//#include <torch/optim/adam.h>
//#include <torch/optim/optimizer.h>
//#include <torch/types.h>
//#include <torch/serialize/tensor.h>
//
//auto device = torch::cuda::is_available() ? torch::kCUDA : torch::kCPU;
//
//auto train_dataset = torch::data::datasets::CIFAR10("./data", torch::data::datasets::CIFAR10::Mode::kTrain)
//.map(torch::data::transforms::Normalize<>(0.5, 0.5))
//.map(torch::data::transforms::Stack<>());
//
//auto train_loader = torch::data::make_data_loader<torch::data::samplers::RandomSampler>(
//	std::move(train_dataset), torch::data::DataLoaderOptions().batch_size(32).workers(2));
//
//auto test_dataset = torch::data::datasets::CIFAR10("./data", torch::data::datasets::CIFAR10::Mode::kTest)
//.map(torch::data::transforms::Normalize<>(0.5, 0.5))
//.map(torch::data::transforms::Stack<>());
//
//auto test_loader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(
//	std::move(test_dataset), torch::data::DataLoaderOptions().batch_size(32).workers(2));
//
//
//
//
//
//
//
//// 모델학습
//int main() {
//	YOLO model;
//	model->to(device);
//
//	torch::optim::Adam optimizer(model->parameters(), torch::optim::AdamOptions(0.001));
//
//	for (size_t epoch = 0; epoch < 10; ++epoch) {
//		model->train();
//		size_t batch_index = 0;
//		for (auto& batch : *train_loader) {
//			auto data = batch.data.to(device);
//			auto targets = batch.target.to(device);
//
//			optimizer.zero_grad();
//			auto output = model->forward(data);
//			auto loss = torch::nn::functional::cross_entropy(output, targets);
//			loss.backward();
//			optimizer.step();
//
//			if (batch_index++ % 100 == 0) {
//				std::cout << "Train Epoch: " << epoch << " [" << batch_index * batch.data.size(0)
//					<< "/" << train_loader->size().value() << "]\tLoss: " << loss.item<float>() << std::endl;
//			}
//		}
//	}
//
//	// 모델 평가
//	model->eval();
//	torch::NoGradGuard no_grad;
//	double test_loss = 0;
//	int correct = 0;
//	for (const auto& batch : *test_loader) {
//		auto data = batch.data.to(device);
//		auto targets = batch.target.to(device);
//		auto output = model->forward(data);
//		test_loss += torch::nn::functional::cross_entropy(output, targets, torch::nn::functional::CrossEntropyFuncOptions().reduction(torch::kSum)).item<double>();
//		auto pred = output.argmax(1);
//		correct += pred.eq(targets).sum().item<int>();
//	}
//
//	test_loss /= test_loader->size().value();
//	std::cout << "\nTest set: Average loss: " << test_loss << ", Accuracy: " << correct << "/" << test_loader->size().value()
//		<< " (" << static_cast<double>(correct) / test_loader->size().value() * 100.0 << "%)\n";
//	return 0;
//}
