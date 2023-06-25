#include<iostream>
#include <ctime>
using namespace std;
#include<windows.h>
#include "Matrix.h"

void testMatrix();

void showMenu();

int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//1. C������� ������� ����������� ������ � ��������� �� ���������� ����������.
	//2. �������� ������� � ��������� ����� ������.
	//3. ������� ������� ������� �� �����.
	//4. ���������� ������� �� ����� (������� ��'� ����� ������)
	//5. �������� ������� � ���� (������� ����� ������)
	//6. ������ ������� � ������� ��������� (� ���� ��� �����)
	//7. �����

	int action = 0;
	Matrix current;
	do {
		showMenu();
		cin >> action;
		switch (action) {
		case 1: {
			cout << "������ ������ ����� �� ���������";
			int n, m;
			cin >> n >> m;
			Matrix a(n, m);
			a.initRandom();
			current = a;
			break;
		}
		case 3: {
			cout << current;
			break;
		}
		}

	} while (action != 7);

	return 0;
}
void showMenu() {
	cout << "1. C������� ������� ����������� ������ � ��������� �� ���������� ����������.\n";
	cout << "2. �������� ������� � ��������� ����� ������.\n";
	cout << "3. ������� ������� ������� �� �����.\n";
	cout << "4. ���������� ������� �� ����� (������� ��'� ����� ������).\n";
	cout << "5. �������� ������� � ���� (������� ����� ������).\n";
	cout << "6. ������ ������� � ������� ��������� (� ���� ��� �����)\n";
	cout << "7. �����.\n";
}

void testMatrix() {
	//int n, m;
//cout << "������ n: ";
//cin >> n;
//cout << "������ m: ";
//cin >> m;
//int** a = new int *[n];   //�������� ������ �� �����
//for (int i = 0; i < n; i++)
//{
//	a[i] = new int[m]; //�� ����� ����� ������ ���������
//}
//for (int i = 0; i < n; i++) //����� �� ������
//{
//	for (int j = 0; j < m; j++) //����� �� ����������
//	{
//		a[i][j] = rand() % 20;
//	}
//}
//for (int i = 0; i < n; i++)
//{
//	for (int j = 0; j < m; j++)
//	{
//		cout << a[i][j] << "\t";
//	}
//	cout << "\n";
//}

//Matrix a;
	Matrix a(2, 4);
	a.initRandom();
	cout << "-----Matrix A-----\n";
	a.print();
	/*if (1) {
		Matrix b(a);
		cout << "------Matrix B------\n";
		b.print();
	}*/
	Matrix b(2, 4);
	b.initRandom();
	cout << "---Matrix B---\n";
	b.print();

	//Matrix c = a.plus(b);
	Matrix c = a + b;

	cout << "+++++Matrix A result+++++\n";
	a.print();

	cout << "+++++Matrix B result+++++\n";
	b.print();

	cout << "+++++Matrix C result+++++\n";
	c.print();


	Matrix vova(3, 3);
	vova.initRandom();
	cout << "VOVA = \n";
	vova.print();
	Matrix peter; //����� ������� ����������� 2x2
	peter = vova;
	vova.setValue(0, 0, -34);
	cout << "PETER = \n";
	peter.print();
}