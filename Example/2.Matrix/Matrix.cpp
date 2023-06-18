#include "Matrix.h"
Matrix::Matrix() {
	n = m = 2;
	mat = new int* [n]; //������� ������ �����
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m]; //�������� ������ �� �����
	}
}

Matrix::Matrix(int n, int m)
{
	this->n = n;
	this->m = m;
	mat = new int* [n]; //������� ������ �����
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m]; //�������� ������ �� �����
	}
}

Matrix::Matrix(const Matrix& matrix) //���� ������� �� private �������� �������� ��� ���������
{
	this->n = matrix.n;
	this->m = matrix.m;
	this->mat = new int* [n]; //������� ������ �����
	for (int i = 0; i < n; i++) {
		this->mat[i] = new int[m]; //�������� ������ �� �����
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->mat[i][j] = matrix.mat[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] mat[i]; //������� ��������� � �����
	}
	delete[] mat;
}

void Matrix::initRandom()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			mat[i][j] = rand() % 100;
	}
}

void Matrix::print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j] << "\t";
		}
		cout << "\n";
	}
}
