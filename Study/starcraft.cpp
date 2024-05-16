//#include <iostream>
//using namespace std;
//
//class Marine {
//private:
//	int hp;
//	int coord_x, coord_y;
//	int damage;
//	bool is_dead;
//public:
//	Marine();
//	Marine(int x, int y);
//
//	int attack() { return damage; }
//	void be_attacked(int damage_earn);
//	void move(int x, int y);
//	void show_status();
//};
//
//Marine::Marine() {
//	hp = 50;
//	coord_x = coord_y = 0;
//	damage = 5;
//	is_dead = false;
//}
//
//Marine::Marine(int x, int y) {
//	hp = 50;
//	coord_x = x;
//	coord_y = y;
//	damage = 5;
//	is_dead = false;
//}
//
//void Marine::move(int x, int y)
//{
//	coord_x = x;
//	coord_y = y;
//}
//
//void Marine::be_attacked(int damage_earn) {
//	hp -= damage_earn;
//	if (hp <= 0)
//		is_dead = true;
//}
//
//void Marine::show_status() {
//	cout << " *** Marine *** " << endl;
//	cout << " Location : ( " << coord_x << " , " << coord_y << " ) "<< endl;
//	cout << " HP : " << hp << endl;
//}
//
//int main()
//{
//	Marine marine1(2, 3);
//	Marine marine2(3, 5);
//
//	marine1.show_status();
//	marine2.show_status();
//
//	cout << endl << "마린 1이 마린 2 공격! " << endl;
//	marine2.be_attacked(marine1.attack());
//
//	marine1.show_status();
//	marine2.show_status();
//	return 0;
//}
//
