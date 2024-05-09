#include <iostream>
using namespace std;

template <class T>
class Array {
private:
	T data[5];
public:
	void setData(int num, T d);
	T getData(int num);
};

template <class T>
void Array<T>::setData(int num, T d)
{
	if (num < 0 || num > 4)
		cout << "�迭 ���̸� �Ѿ���ϴ�\n";
	else
		data[num] = d;
}

template <class T>
T Array<T>::getData(int num)
{
	if (num < 0 || num > 4)
	{
		cout << "�迭 ���̸� �Ѿ���ϴ�\n";
		return data[0];
	}
	else
		return data[num];
}

int main()
{
	cout << "int�� �迭�� �����մϴ�\n";
	Array<int> i_array;
	i_array.setData(0, 80);
	i_array.setData(1, 60);
	i_array.setData(2, 58);
	i_array.setData(3, 77);
	i_array.setData(4, 57);
	i_array.setData(5, 97);

	for (int i = 0; i < 5; i++)
		cout << i_array.getData(i) << endl;

	cout << "double�� �迭�� �����մϴ�\n";
	Array<double> d_array;
	d_array.setData(0, 35.5);
	d_array.setData(1, 55.5);
	d_array.setData(2, 65.5);
	d_array.setData(3, 75.5);
	d_array.setData(4, 85.5);
	d_array.setData(5, 95.5);

	for (int j = 0; j < 5; j++)
		cout << d_array.getData(j) << endl;

	return 0;
}

