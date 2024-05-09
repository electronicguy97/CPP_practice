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
//	cout << "자동차가 만들어졌습니다\n";
//}
//
//void Car::setCar(int n, double g) {
//	num = n;
//	gas = g;
//	cout << "차량번호: " << num << " 가스량: " << gas << " 인 차량이 만들어졌습니다.\n";
//}
//
//void Car::show() {
//	cout << "차량번호: " << num << " 가스량: " << gas << " 입니다.\n";
//}
//
//RacingCar::RacingCar()
//{
//	course = 0;
//	cout << "레이싱카가 만들어졌습니다\n";
//}
//
//
//void RacingCar::show()
//{
//	cout << "차량번호: " << num << " 가스량: " << gas << " 코스번호 : " << course << " 입니다.\n";
//}
//
//void RacingCar::setCourse(int c) {
//	course = c;
//	cout << "코스번호: " << course << " 로 정했습니다.\n";
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