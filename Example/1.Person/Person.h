#include<iostream>
#include<cstring>
using namespace std;
#pragma once
class Person
{
private: //��������� ���� - ������ ���� �� ������ �����.
	string firstName; //��'�
	string lastName; //�������
	int age;		 //��
	bool sex;		 //�����
public:
	Person(); //���������� - �� ����������� �����, ���� ����������� ����������, ���� ���������� ��'��� ������ �����
	Person(string, string, int, bool); //����������� �� ����������� - ������ ����������� ��'���� ��� �������
	void setFirstName(string);
	string getFirstName();
	void setLastName(string);
	string getLastName();
	void setAge(int);
	int getAge();
	void setSex(bool);
	bool getSex();

	string getSexStr(); //����� ����� ��� ���� (������ ��� ĳ�����)
	void PrintInfo();
};

