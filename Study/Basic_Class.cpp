//#include <iostream>
//using namespace std;
//
//class Car {
//protected:
//	int num;
//	double gas;
//public:
//	Car();
//	void setCar(int n, double g);
//	virtual void show();
//	
//};
//
//class RacingCar : public Car {
//private:
//	int course;
//public:
//	RacingCar();
//	void show();
//	void setCourse(int c);
//};
//
//Car::Car() {
//	num = 0;
//	gas = 0.0;
//	cout << "�ڵ����� ����������ϴ�\n";
//}
//
//void Car::setCar(int n, double g) {
//	num = n;
//	gas = g;
//	cout << "������ȣ: " << num << " ������: " << gas << " �� ������ ����������ϴ�.\n";
//}
//
//void Car::show() {
//	cout << "������ȣ: " << num << " ������: " << gas << " �Դϴ�.\n";
//}
//
//RacingCar::RacingCar()
//{
//	course = 0;
//	cout << "���̽�ī�� ����������ϴ�\n";
//}
//
//
//void RacingCar::show()
//{
//	cout << "������ȣ: " << num << " ������: " << gas << " �ڽ���ȣ : " << course << " �Դϴ�.\n";
//}
//
//void RacingCar::setCourse(int c) {
//	course = c;
//	cout << "�ڽ���ȣ: " << course << " �� ���߽��ϴ�.\n";
//}
//
//int main() {
//	
//	Car* pCars[2];
//	RacingCar* pRCars[2];
//
//	Car car1;
//	RacingCar rccar1,rccar2,rccar3;
//
//	pCars[0] = &car1;
//	pCars[0]->setCar(7777, 77.77);
//
//	pCars[1] = &rccar1;
//	pCars[1] -> setCar(3333, 77.77);
//
//	pRCars[0] = &rccar2;
//	pRCars[0]->setCar(3333, 33.33);
//	pRCars[0]->setCourse(3);
//
//	pRCars[1] = &rccar3;
//	pRCars[1]->setCar(7777, 77.77);
//	pRCars[1]->setCourse(7);
//
//	for (int i = 0; i < 2; i++)
//	{
//		pCars[i]->show();
//		pRCars[i]->show();
//	}
//
//	return 0;
//}