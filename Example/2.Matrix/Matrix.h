#pragma once
#include <iostream>
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
	Matrix(const Matrix &); //����������� ��������� (����� ���� ��'� � �����, ���� ����� �����������)
	void initRandom();
	void print();
};

