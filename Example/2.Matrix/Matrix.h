#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Matrix
{
private:
	int** mat; //сама матриця
	int n; //кікльсть рядків матриці
	int m; //кількість ствовпчиків матриці
public:
	//При створені об'єкт - екзампляр класу
	Matrix(); //конструктор по замовчуванні
	Matrix(int, int); //конструктор із параметрами
	//const - вхідний об'єкт не можна мінять, & - взятя адреси об'єкта (передача по силці)
	Matrix(const Matrix&); //конструктор копіювання (копіює одни об'є в інший, який зарза стоврюється)
	~Matrix(); //деструкто матриці, видаляє масив із пам'яті
	void initRandom();
	void print();
	Matrix plus(const Matrix&); //додавання двох матриць між собою
	Matrix operator+(const Matrix&); //додавання двох матриць між собою - перегрузка операктора додавання
	Matrix operator=(const Matrix&); //перевантаження оператора присвоїти.

	void setValue(int, int, int); //зміна значення в матриці

	//const int* & operator[](int i) const;

	void save(string path); //зберегти у файл
	void read(string path); //прочитати із файлу

	//вивід матриці на екран через cout<<
	friend ostream& operator<<(ostream& os, const Matrix&);
	//ввід даних про матрицю через cin>>
	friend istream& operator>>(istream& is, Matrix&);

	//вивід матриці на екран через ofstream<<
	friend ofstream& operator<<(ofstream& os, const Matrix&);
	//вивід матриці на екран через ifstream<>>
	friend ifstream& operator>>(ifstream& is, Matrix&);
};

