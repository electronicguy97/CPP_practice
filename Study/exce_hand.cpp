////예외처리
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int num;
//	cout << "1~9까지 숫자를 입력하십시오\n";
//	cin >> num;
//	try {
//		if (num <= 0)
//			throw "0 이하의 수가 입력되었습니다\n";
//		if (num >= 10)
//			throw "10 이상의 수가 입력되었습니다\n";
//
//		cout << num << "입니다\n";
//	}
//
//	catch (char* err) {
//		cout << "에러: " << err << endl;
//		return 1;
//	}
//
//	return 0;
//}