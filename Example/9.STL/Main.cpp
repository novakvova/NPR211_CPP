#include<iostream>
#include<fstream>
using namespace std;
#include<windows.h>
#include <vector>
#include <set>

void test_vector();
int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//test_vector();
	//�� ������ �������� ������������ � ������
	//������ ���������� ���� ��������
	set<string> days;
	days.insert("��������");
	days.insert("³������");
	days.insert("������");
	days.insert("������");
	days.insert("�������");
	days.insert("������");
	days.erase("������");
	/*for (auto i = days.begin(); i != days.end(); i++)
	{
		cout << *i << "\n";
	}*/
	// Iterate through the set and print its elements
	std::cout << "Elements in the set: ";
	//���� foreach - ����� ������ days - �� ���� ��� �� ������ � ����� �������� 
	//����� �������� day = days[i], �� � - �������� ����� 0, 1, ..., n
	for (auto day : days) {
		std::cout << day << " ";
	}
	std::cout << std::endl;
	return 0;
}
void test_vector() {
	//cout << "�����!";
	vector<int> list;
	try {
		ifstream in("myvector.txt");
		if (!in.is_open())
		{
			//��������� �������
			throw exception("������� �������� ����� myvector.txt");
		}
		int a;
		while (in >> a) {
			if (in.eof())
				break;
			if (a < 0)
				throw (a);
			list.push_back(a);
		}
		in.close();
	}
	catch (int item)
	{
		cerr << "\033[1;33m��������� �� ��������� ����� " << item << "\033[0m\n";
	}
	catch (exception ex)
	{
		cerr << "\033[1;31m������� � ����� " << ex.what() << "\033[0m\n";
	}
	list.push_back(23);
	list.push_back(12);
	list.push_back(56);
	list.insert(list.end(), 62);
	list.insert(list.begin(), 80);
	list.pop_back();
	list.erase(list.begin() + 2);
	//vector<int>::iterator i;
	cout << "Size : " << list.size();
	cout << "\nCapacity : " << list.capacity();
	cout << "\nMax_Size : " << list.max_size() << "\n";

	for (auto i = list.begin(); i != list.end(); i++)
	{
		cout << *i << "\n";
	}
}
