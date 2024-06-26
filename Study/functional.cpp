#include <iostream>
#include <functional>
#include <string>

class A {
	int c;

public:
	A(int c) : c(c) {}
	int some_func() {
		std::cout << "비상수 함수: " << ++c << std::endl;
		return c;
	}

	int some_const_function() const {
		std::cout << "상수 함수: " << c << std::endl;
		return c;
	}
	static void st() {}
};

int main() {
	A a(5);
	std::function<int(A&)> f1 = &A::some_func;
	std::function<int(const A&)> f2 = &A::some_const_function;

	f1(a);
	f2(a);
}