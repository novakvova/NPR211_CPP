#pragma once
#include<iostream>
using namespace std;
class Person
{
private: 
	char* name; //����� �������
	int name_buffer; //������� ����
	int age; //�� �������
public:
	Person();
	Person(const char* name);
	Person(const Person& student);
	~Person();

	void setAge(int age);
	int getAge();
	void setName(const char* name);
	void setName(const string name);
	string getName();
	virtual void showInfo();

};

