#include <iostream>
#include <ctime>
using namespace std;
#include <windows.h>
#include "Person.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//���� �������� ��� - ��� ���� �������������� � ������ �����
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int value = rand() % 10;
		cout << value<<"\t";
	}
	cout << endl;
	Person oksana;   //������������� ���������� �� ������������
	oksana.PrintInfo();
	Person andriy("�����", "�������", 19, true); //
	andriy.PrintInfo();
	Person peter;
	peter.PrintInfo();
	peter.setFirstName("�����");
	peter.setLastName("ϳ����������");
	peter.setAge(50);
	peter.setSex(true);
	cout << "-----------------Info-------------------\n";
	peter.PrintInfo();
	//cout << "�����!";
	return 0;
}