#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Matrix
{
private:
	int** mat; //���� �������
	int n; //������� ����� �������
	int m; //������� ���������� �������
public:
	//��� ������� ��'��� - ��������� �����
	Matrix(); //����������� �� �����������
	Matrix(int, int); //����������� �� �����������
	//const - ������� ��'��� �� ����� �����, & - ����� ������ ��'���� (�������� �� �����)
	Matrix(const Matrix&); //����������� ��������� (����� ���� ��'� � �����, ���� ����� �����������)
	~Matrix(); //��������� �������, ������� ����� �� ���'��
	void initRandom();
	void print();
	Matrix plus(const Matrix&); //��������� ���� ������� �� �����
	Matrix operator+(const Matrix&); //��������� ���� ������� �� ����� - ���������� ���������� ���������
	Matrix operator=(const Matrix&); //�������������� ��������� ��������.

	void setValue(int, int, int); //���� �������� � �������

	void save(string path); //�������� � ����
	void read(string path); //��������� �� �����
};

