//// ���� ���
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
//	cout << "bs0�� " << bs0 << "�Դϴ�\n";
//}
//
//void Base1::showBs1()
//{
//	cout << "bs1�� " << bs1 << "�Դϴ�\n";
//}
//
//void Base2::showBs2()
//{
//	cout << "bs2�� " << bs2 << "�Դϴ�\n";
//}
//
//void Derived::showDr()
//{
//	cout << "dr�� " << dr << "�Դϴ�\n";
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