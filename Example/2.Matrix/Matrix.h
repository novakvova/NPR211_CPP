#pragma once
#include <iostream>
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
	Matrix(const Matrix &); //конструктор копіювання (копіює одни об'є в інший, який зарза стоврюється)
	void initRandom();
	void print();
};

