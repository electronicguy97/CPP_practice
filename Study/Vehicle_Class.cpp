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
//	cout << "�ӵ� ����: " << speed << endl;
//}
//
//Car::Car(int n, double g)
//{
//	num = n;
//	gas = g;
//	cout << "������ȣ: " << num << " ������: " << gas << " ����\n";
//}
//
//void Car::show()
//{
//	cout << "������ȣ: " << num << " ������:" << gas << " �ӵ�: " << speed << endl;
//}
//
//Plane::Plane(int f)
//{
//	flight = f;
//	cout << "�����ȣ: " << flight << "����\n";
//}
//
//void Plane::show()
//{
//	cout << "�����ȣ: " << flight << " �ӵ�: " << speed << endl;
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
//			cout << (i + 1) << "��° ��ü�� " << typeid(Car).name() << "�� ��ü�Դϴ�\n";
//		else
//			cout << (i + 1) << "��° ��ü�� " << typeid(Car).name() << "�� ��ü�� �ƴմϴ�\n" << typeid(*pVc[i]).name() << "�� ��ü�Դϴ�.\n";;
//	}
//}