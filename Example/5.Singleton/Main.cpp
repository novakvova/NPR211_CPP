#include<iostream>
#include<windows.h>
#include "MyReader.h"
using namespace std;
int main() 
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "����� ������\n";
	//��������� �������� Signleton - ��������� ��'���� � ���������� ���������.
	//1. �� ����� �������� ��������� ����� �� �����.
	//MyReader reader; - �������� ������ �� �����.
	//���� ���������, ����� �� ����� �������� �� ����� ���������� ����������� ����
	//� �++ ��� �������� ������������ ����� �� ������ private �����������
	//2. ��������� ��������� ���������� ����� ���� � ������ ���������.
	// ���������, �� ��������� �� �� - ��������� �� ���� ������ ������ ���� ����.
	// ������ ����. - ���� ��� ����������� � ��������.
	//�������� ��������� �� ��'���
	if (true) {
		MyReader::getInstance().test();
		cout << "Object address reader: " << &MyReader::getInstance() << endl;
	}
	if (true) {
		cout << "Object address malvina: " << &MyReader::getInstance() << endl;
		MyReader::getInstance().test();
	}
	
	return 0;
}