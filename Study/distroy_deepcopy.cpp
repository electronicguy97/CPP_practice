//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Car {
//private:
//	int num;
//	double gas;
//	char* pName;
//public:
//	Car(const char* pN, int n, double g);
//	~Car();
//	Car(const Car& c);
//	Car& operator= (const Car& c);
//};
//
//Car::Car(const char* pN, int n, double g)
//{
//	pName = new char[strlen(pN) + 1];
//	strcpy(pName, pN);
//	num = n;
//	gas = g;
//	cout << pName << "을(를) 생성하였습니다.\n";
//}
//
//Car::~Car()
//{
//	cout << pName << "을(를) 소멸시킵니다.\n";
//	delete[] pName;
//}
//
//Car::Car(const Car& c)
//{
//	cout << c.pName << " 로 초기화합니다 \n";
//	pName = new char[strlen(c.pName) + strlen("의 복사본 1") + 1];
//	strcpy(pName, c.pName);
//	strcat(pName, " 의 복사본 1");
//	num = c.num;
//	gas = c.gas;
//}
//
//Car& Car::operator=(const Car& c)
//{
//	cout << pName << "에 " << c.pName << "를 대입합니다\n";
//	if (this != &c) {
//		delete[] pName;
//		pName = new char[strlen(c.pName) + strlen("의 복사본 2") + 1];
//		strcpy(pName, c.pName);
//		strcat(pName, "의 복사본2");
//		num = c.num;
//		gas = c.gas;
//	}
//	return *this;
//}
//
//int main()
//{
//	Car mycar("mycar", 7777, 77.77);
//	
//	Car car1 = mycar;
//
//	Car car2("car2", 0, 0);
//	car2 = mycar;
//
//	return 0;
//
//	return 0;
//}