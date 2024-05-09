//#include <iostream>
//using namespace std;
//
//class Point {
//private:
//	int x;
//	int y;
//public:
//	Point(int a = 0, int b = 0) { x = a; y = b; }
//	void show() { cout << "x: " << x << ", y: " << y << endl; }
//	void setX(int a) { x = a; }
//	void setY(int b) { y = b; }
//	Point operator++();
//	Point operator++(int d);
//	friend Point operator+(Point p1, Point p2);
//	friend Point operator+(Point p, int a);
//	friend Point operator+(int a, Point p);
//};
//
//Point operator+ (Point p1, Point p2)
//{
//	Point temp;
//	temp.x = p1.x + p2.x;
//	temp.y = p1.y + p2.y;
//	return temp;
//}
//
//Point operator+(int a,  Point p)
//{
//	Point temp;
//	temp.x = a + p.x;
//	temp.y = a + p.y;
//	return temp;
//}
//
//Point operator+(Point p,  int a)
//{
//	Point temp;
//	temp.x = p.x + a;
//	temp.y = p.y + a;
//	return temp;
//}
//
//
//
//Point Point::operator++()
//{
//	x++;
//	y++;
//	return *this;
//}
//
//Point Point::operator++(int d)
//{
//	Point p = *this;
//	x++;
//	y++;
//	return p;
//}
//
//int main()
//{
//	Point p1(1,2);
//	Point p2(3, 6);
//	p1 = p1 + p2;
//	p1++;
//	p1 = p1 + 3;
//	p2 = 3 + p2;
//	printf("d");
//	p1.show();
//	p2.show();
//	
//}
