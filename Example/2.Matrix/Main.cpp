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
	//cout << "Вкажіть n: ";
	//cin >> n;
	//cout << "Вкажіть m: ";
	//cin >> m;
	//int** a = new int *[n];   //Виділяємо память під рядки
	//for (int i = 0; i < n; i++)
	//{
	//	a[i] = new int[m]; //під кожен рядок робимо стовпчики
	//}
	//for (int i = 0; i < n; i++) //ідемо по рядках
	//{
	//	for (int j = 0; j < m; j++) //ідемо по стовпчиках
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
	Matrix b(2,4);
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
	Matrix peter; //Розмір матриці стандартний 2x2
	peter = vova;
	vova.setValue(0, 0, -34);
	cout << "PETER = \n";
	peter.print();

	return 0;
}