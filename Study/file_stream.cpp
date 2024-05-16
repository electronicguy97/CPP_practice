//#include <fstream>
//#include <iostream>
//#include <iomanip>
//using namespace std;

//// 파일 쓰기
//int main()
//{
//	ofstream fout("test0.txt");
//	if (!fout) {
//		cout << "파일을 열 수 없습니다\n";
//		return -1;
//	}
//	else
//		cout << "파일을 열었습니다\n";
//
//	fout << "Hello!\n";
//	fout << "world";
//	cout << "파일을 기록합니다\n";
//
//	fout.close();
//	cout << "파일을 닫았습니다\n";
//	
//	return 0;
//}

// 파일 읽기
//int main()
//{
//	ifstream fin("test3.txt"); // 해당 이름 파일을 생성 후 데이터 삽입 e.g.) test3.txt <- 80 60 50 70 77 50 88 99
//	if (!fin)
//	{
//		cout << "파일을 열 수 없습니다\n";
//		return 1;
//	}
//
//	const int num = 8;
//	int test[num];
//	for (int i = 0; i < num; i++)
//		fin >> test[i];
//
//	int max = test[0];
//	int min = test[0];
//	for (int j = 0; j < num; j++) {
//		if (max < test[j])
//			max = test[j];
//		if (min > test[j])
//			min = test[j];
//		cout << "No." << j + 1 << setw(5) << test[j] << endl;
//	}
//	cout << "가장 높은 점수: " << max << endl;
//	cout << "가장 낮은 점수: " << min << endl;
//
//	fin.close();
//
//	return 0;
//}