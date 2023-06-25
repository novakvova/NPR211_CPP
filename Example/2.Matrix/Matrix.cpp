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
	//cout << "^^^^^^^DELETE object^^^^^^^^^^\n";
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

Matrix Matrix::plus(const Matrix& input)
{
	Matrix matrix(n, m); //������� ������� �������� ������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix.mat[i][j] = mat[i][j] + input.mat[i][j]; //������� ���� �������� �������
		}
	}

	return Matrix(matrix);
}

Matrix Matrix::operator+(const Matrix& input)
{
	Matrix matrix(n, m); //������� ������� �������� ������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix.mat[i][j] = mat[i][j] + input.mat[i][j]; //������� ���� �������� �������
		}
	}

	return Matrix(matrix);
}

void Matrix::setValue(int i, int j, int value)
{
	mat[i][j] = value;
}

//const int*& Matrix::operator[](int i) const
//{
//	return mat[i];
//}

void Matrix::save(string path)
{
	ofstream out(path);
	out << n << "\t" << m << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			out<<mat[i][j]<<'\t'; //������� ���� �������� �������
		}
		out << "\n";
	}
	out.close();
}

void Matrix::read(string path)
{
	for (int i = 0; i < n; i++)
	{
		delete[] mat[i]; //������� ��������� � �����
	}
	delete[] mat;

	ifstream in(path);
	in >> n >> m;

	mat = new int* [n]; //������� ������ �����
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m]; //�������� ������ �� �����
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			in>>mat[i][j]; //������� ���� �������� �������
		}
	}
	in.close();
}

Matrix Matrix::operator=(const Matrix&input)
{
	if (this == &input)
		return *this;  //������������ ����� (this - �������� �� �����) *this - ��� ��'���

	//�������, ��� �������� ���� �� ����� = ��������� ������
	for (int i = 0; i < n; i++)
	{
		delete[] mat[i]; //������� ��������� � �����
	}
	delete[] mat;

	//�������� ������ �� ���� �������
	this->n = input.n;
	this->m = input.m;
	mat = new int* [n]; //������� ������ �����
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m]; //�������� ������ �� �����
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = input.mat[i][j];
		}
	}

	return *this;
}

ostream& operator<<(ostream& os, const Matrix& matrix)
{
	for (int i = 0; i < matrix.n; i++)
	{
		for (int j = 0; j < matrix.m; j++)
		{
			os << matrix.mat[i][j] << "\t";
		}
		os << "\n";
	}
	return os;
}

istream& operator>>(istream& is, Matrix& matrix)
{
	//��������� ���������� ��� ����� �������
	for (int i = 0; i < matrix.n; i++)
	{
		delete[] matrix.mat[i]; //������� ��������� � �����
	}
	delete[] matrix.mat;

	cout << "������ ������� ����� ������� ->_";
	is >> matrix.n;

	cout << "������ ������� ��������� ������� ->_";
	is >> matrix.m;

	matrix.mat = new int* [matrix.n]; //������� ������ �����
	for (int i = 0; i < matrix.n; i++) {
		matrix.mat[i] = new int[matrix.m]; //�������� ������ �� �����
	}

	for (int i = 0; i < matrix.n; i++)
	{
		for (int j = 0; j < matrix.m; j++)
		{
			is>>matrix.mat[i][j];
		}
	}

	return is;
}

ofstream& operator<<(ofstream& os, const Matrix& matrix)
{
	os << matrix.n << "\n" << matrix.m << "\n";
	for (int i = 0; i < matrix.n; i++)
	{
		for (int j = 0; j < matrix.m; j++)
		{
			os << matrix.mat[i][j] << "\t";
		}
		os << "\n";
	}
	return os;
}

ifstream& operator>>(ifstream& is, Matrix& matrix)
{
	//��������� ���������� ��� ����� �������
	for (int i = 0; i < matrix.n; i++)
	{
		delete[] matrix.mat[i]; //������� ��������� � �����
	}
	delete[] matrix.mat;

	is >> matrix.n;
	is >> matrix.m;

	matrix.mat = new int* [matrix.n]; //������� ������ �����
	for (int i = 0; i < matrix.n; i++) {
		matrix.mat[i] = new int[matrix.m]; //�������� ������ �� �����
	}

	for (int i = 0; i < matrix.n; i++)
	{
		for (int j = 0; j < matrix.m; j++)
		{
			is >> matrix.mat[i][j];
		}
	}

	return is;
}
