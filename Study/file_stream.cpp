//#include <fstream>
//#include <iostream>
//#include <iomanip>
//using namespace std;

//// ���� ����
//int main()
//{
//	ofstream fout("test0.txt");
//	if (!fout) {
//		cout << "������ �� �� �����ϴ�\n";
//		return -1;
//	}
//	else
//		cout << "������ �������ϴ�\n";
//
//	fout << "Hello!\n";
//	fout << "world";
//	cout << "������ ����մϴ�\n";
//
//	fout.close();
//	cout << "������ �ݾҽ��ϴ�\n";
//	
//	return 0;
//}

// ���� �б�
//int main()
//{
//	ifstream fin("test3.txt"); // �ش� �̸� ������ ���� �� ������ ���� e.g.) test3.txt <- 80 60 50 70 77 50 88 99
//	if (!fin)
//	{
//		cout << "������ �� �� �����ϴ�\n";
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
//	cout << "���� ���� ����: " << max << endl;
//	cout << "���� ���� ����: " << min << endl;
//
//	fin.close();
//
//	return 0;
//}