//#include <iostream>
//using namespace std;
//
//class Vehicle {
//protected:
//	int speed;
//public:
//	void setSpeed(int s);
//	virtual void show() = 0;
//};
//
//class Car : public Vehicle {
//private:
//	int num;
//	double gas;
//public:
//	Car(int n, double g);
//	void show();
//};
//class Plane : public Vehicle {
//private:
//	int flight;
//public:
//	Plane(int f);
//	void show();
//};
//
//void Vehicle::setSpeed(int s)
//{
//	speed = s;
//	cout << "속도 변경: " << speed << endl;
//}
//
//Car::Car(int n, double g)
//{
//	num = n;
//	gas = g;
//	cout << "차량번호: " << num << " 가스량: " << gas << " 생성\n";
//}
//
//void Car::show()
//{
//	cout << "차량번호: " << num << " 가스량:" << gas << " 속도: " << speed << endl;
//}
//
//Plane::Plane(int f)
//{
//	flight = f;
//	cout << "비행번호: " << flight << "생성\n";
//}
//
//void Plane::show()
//{
//	cout << "비행번호: " << flight << " 속도: " << speed << endl;
//}
//
//int main(void)
//{
//	Vehicle* pVc[2];
//	Car car1(7777, 77.77);
//	Plane pln1(747);
//
//	pVc[0] = &car1;
//	pVc[1] = &pln1;
//
//	for (int i = 0; i < 2; i++)
//	{
//		if (typeid(*pVc[i]) == typeid(Car))
//			cout << (i + 1) << "번째 객체는 " << typeid(Car).name() << "의 객체입니다\n";
//		else
//			cout << (i + 1) << "번째 객체는 " << typeid(Car).name() << "의 객체가 아닙니다\n" << typeid(*pVc[i]).name() << "의 객체입니다.\n";;
//	}
//}