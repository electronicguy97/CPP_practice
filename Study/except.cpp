//#include <iostream>
//#include <stdexcept>
///*
//일반적으로 예외 객체는 std::exception 을 상속 받는 것이 좋습니다. 왜냐하면 
//표준 라이브러리의 유용한 함수들(nested_exception 등) 을 사용할 수 있기 때문
//*/
//class Parent : public std::exception {
//public:
//	virtual const char* what() const noexcept override { return "Parent!\n"; }
//};
//
//class Child : public Parent{
//public:
//	const char* what() const noexcept override { return "Child!\n"; }
//};
//
//int func(int c) {
//	if (c == 1) {
//		throw Parent();
//	}
//	else if (c == 2) {
//		throw Child();
//	}
//	return 0;
//}
//
//int main() {
//	int c;
//	std::cin >> c;
//
//	try {
//		func(c);
//
//	///////////// catch 문을 사용할 때는 상속클래스를 먼저 작성 다음과 같이 작성시 무조건 부모클래스 출력
//	}
//	/*catch (Parent& p) {
//		std::cout << "Parent Catch!" << std::endl;
//		std::cout << p.what();
//	}
//	catch (Child& c) {
//		std::cout << "Child Catch!" << std::endl;
//		std::cout << c.what();
//	}*/
//	catch (Child& c) {
//		std::cout << "Child Catch!" << std::endl;
//		std::cout << c.what();
//	}
//	catch (Parent& p) {
//		std::cout << "Parent Catch!" << std::endl;
//		std::cout << p.what();
//	}
//}