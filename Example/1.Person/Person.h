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
	void setFirstName(string);
	string getFirstName();
	void setLastName(string);
	string getLastName();
	void setAge(int);
	int getAge();
	void setSex(bool);
	bool getSex();

	void PrintInfo();
};

