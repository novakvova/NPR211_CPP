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
	
	//1. Cтворити матрицю визанченого розміру і заповнити її рандомними значеннями.
	//2. Створити матрицю і заповнити данми вручну.
	//3. Вивести поточну матрицю на екран.
	//4. Прочатиати матрицю із файлу (вказуємо ім'я файлу вручну)
	//5. Записати матрицю у файл (вказуємо назву вручну)
	//6. Додати матриці і вивести результат (у файл або екран)
	//7. Вихід

	int action = 0;
	Matrix current;
	do {
		showMenu();
		cin >> action;
		switch (action) {
		case 1: {
			cout << "Вкажіть кількіть рядків та стовпчиків";
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
	cout << "1. Cтворити матрицю визанченого розміру і заповнити її рандомними значеннями.\n";
	cout << "2. Створити матрицю і заповнити данми вручну.\n";
	cout << "3. Вивести поточну матрицю на екран.\n";
	cout << "4. Прочатиати матрицю із файлу (вказуємо ім'я файлу вручну).\n";
	cout << "5. Записати матрицю у файл (вказуємо назву вручну).\n";
	cout << "6. Додати матриці і вивести результат (у файл або екран)\n";
	cout << "7. Вихід.\n";
}

void testMatrix() {
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
	Matrix peter; //Розмір матриці стандартний 2x2
	peter = vova;
	vova.setValue(0, 0, -34);
	cout << "PETER = \n";
	peter.print();
}