#include<iostream>
#include<windows.h>
using namespace std;
#include "Doubly.h"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//cout << "�����\n";
	int mas[10]; //40 ����
	//������ ���� ��������� ������������ ����
	int* masDinamicaly = new int[10]; //�� �� ����� �������� ������� - ������� ���� � �������������
	Doubly<int> list;
	list.Add(23);
	list.Add(28);
	list.Add(45); //15 ����
	cout << list << "\n";

	//list.Delete(23);
	//cout << "_______Delete 23_________\n";
	//cout << list << "\n";
	
	list.Delete(45);
	cout << "_______Delete 45_________\n";
	cout << list << "\n";

	cout << "________Add 67________\n";
	list.Add(67);
	cout << list << "\n";

	return 0;
}