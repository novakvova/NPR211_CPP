#include<iostream>
#include <ctime>
using namespace std;
#include<windows.h>
#include "Matrix.h"

int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
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

	Matrix b(a);
	cout << "------Matrix B------\n";
	b.print();
	//cout << "�����!";
	return 0;
}