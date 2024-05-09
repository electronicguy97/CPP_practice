#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
	// Load CIFAR-10 dataset
	cv::Mat dataset = cv::imread("cifar-10.png");

	if (dataset.empty()) {
		std::cerr << "Error: Failed to load CIFAR-10 dataset." << std::endl;
		return -1;
	}

	// Split dataset into train and test sets
	cv::Mat trainset, testset;
	float train_ratio = 0.8;  // Ratio of training data
	int num_samples = dataset.rows;
	int num_train_samples = static_cast<int>(train_ratio * num_samples);

	trainset = dataset.rowRange(0, num_train_samples);
	testset = dataset.rowRange(num_train_samples, num_samples);

	// Display the sizes of train and test sets
	std::cout << "Train set size: " << trainset.rows << " samples" << std::endl;
	std::cout << "Test set size: " << testset.rows << " samples" << std::endl;

	// Save train and test sets to files if needed
	cv::imwrite("trainset.png", trainset);
	cv::imwrite("testset.png", testset);

	return 0;
}
