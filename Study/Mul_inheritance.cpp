//// 다중 상속
//#include <iostream>
//using namespace std;
//
//class Base0 {
//protected:
//	int bs0;
//public:
//	Base0(int b0 = 0) { bs0 = b0; }
//	void showBs0();
//};
//
//class Base1 : public virtual Base0 {
//protected:
//	int bs1;
//public:
//	Base1(int b1 = 1) { bs1 = b1; }
//	void showBs1();
//};
//
//class Base2 : public virtual Base0 {
//protected:
//	int bs2;
//public:
//	Base2(int b2 = 2) { bs2 = b2; }
//	void showBs2();
//};
//
//class Derived : public Base1, public Base2 {
//protected:
//	int dr;
//public:
//	Derived(int d = 3) { dr = d; }
//	void showDr();
//};
//
//void Base0::showBs0()
//{
//	cout << "bs0은 " << bs0 << "입니다\n";
//}
//
//void Base1::showBs1()
//{
//	cout << "bs1은 " << bs1 << "입니다\n";
//}
//
//void Base2::showBs2()
//{
//	cout << "bs2은 " << bs2 << "입니다\n";
//}
//
//void Derived::showDr()
//{
//	cout << "dr은 " << dr << "입니다\n";
//}
//
//int main()
//{
//	Derived drv;
//	drv.showBs0();
//	drv.showBs1();
//	drv.showBs2();
//	drv.showDr();
//
//	return 0;
//}