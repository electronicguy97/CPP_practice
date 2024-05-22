////#include <iostream>
////#include <thread>
////#include <vector>
////
////void worker(int& counter) {
////	for (int i = 0; i < 10000; i++) {
////		counter += 1;
////	}
////}
////
////int main() {
////	int counter = 0;
////
////	std::vector<std::thread> workers;
////	for (int i = 0; i < 4; i++) {
////		workers.push_back(std::thread(worker, std::ref(counter)));
////	}
////
////	for (int i = 0; i < 4; i++) {
////		workers[i].join();
////	}
////	std::cout << "Counter ���� ��: " << counter << std::endl;
////}
//
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <vector>
//
////void worker(int& result, std::mutex& m) {
////	for (int i = 0; i < 10000; i++) {
////		m.lock();
////		result += 1;
////		m.unlock();
////	}
////}
//// ------------- or ---------------
//void worker(int& result, std::mutex& m) {
//	for (int i = 0; i < 10000; i++) {
//		std::lock_guard<std::mutex> lock(m); // lock ������ m.lock ����
//		result += 1;
//		// scope�� ���� ������ lock �Ҹ� -> m.unlock() ����
//	}
//}
//
//int main() {
//	int counter = 0;
//	std::mutex m;
//
//	std::vector<std::thread> workers;
//	for (int i = 0; i < 4; i++) {
//		workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
//	}
//
//	for (int i = 0; i < 4; i++) {
//		workers[i].join();
//	}
//	std::cout << "Counter ���� ��: " << counter << std::endl;
//}

#include <chrono>              // std::chrono::miliseconds
#include <condition_variable>  // std::condition_variable
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m,
	int index, std::condition_variable* cv) {
	for (int i = 0; i < 5; i++) {
		// ������Ʈ�� �ٿ�ε� �ϴµ� �ɸ��� �ð��̶� �����ϸ� �ȴ�.
		// �� ������ ���� �ٿ�ε� �ϴµ� �ɸ��� �ð��� �ٸ���.
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "������Ʈ : " + std::to_string(i) + " from thread(" +
			std::to_string(index) + ")\n";

		// data �� ������ ���̿��� �����ǹǷ� critical section �� �־�� �Ѵ�.
		m->lock();
		downloaded_pages->push(content);
		m->unlock();

		// consumer ���� content �� �غ�Ǿ����� �˸���.
		cv->notify_one();
	}
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m,
	int* num_processed, std::condition_variable* cv) {
	while (*num_processed < 25) {
		std::unique_lock<std::mutex> lk(*m);

		cv->wait(
			lk, [&] { return !downloaded_pages->empty() || *num_processed == 25; });

		if (*num_processed == 25) {
			lk.unlock();
			return;
		}

		// �� ���� �������� �а� ��� ��Ͽ��� �����Ѵ�.
		std::string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		lk.unlock();

		// content �� ó���Ѵ�.
		std::cout << content;
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
}

int main() {
	// ���� �ٿ�ε��� �������� ����Ʈ��, ���� ó������ ���� �͵��̴�.
	std::queue<std::string> downloaded_pages;
	std::mutex m;
	std::condition_variable cv;

	std::vector<std::thread> producers;
	for (int i = 0; i < 5; i++) {
		producers.push_back(
			std::thread(producer, &downloaded_pages, &m, i + 1, &cv));
	}

	int num_processed = 0;
	std::vector<std::thread> consumers;
	for (int i = 0; i < 3; i++) {
		consumers.push_back(
			std::thread(consumer, &downloaded_pages, &m, &num_processed, &cv));
	}

	for (int i = 0; i < 5; i++) {
		producers[i].join();
	}

	// ������ �ڰ� �ִ� ��������� ��� �����.
	cv.notify_all();

	for (int i = 0; i < 3; i++) {
		consumers[i].join();
	}
}