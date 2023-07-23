#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include "Printable.h";

enum PersonType
{
	COOK=0, //�����
	WAITER=1 //��������
};

class Person : public Printable
{
private:
	string name;
	//��������
	double salary;
	/// <summary>
	/// ������
	/// </summary>
	int category;
public:
	Person();
	Person(const string name, const double salary, int category);
	Person(const Person& person);
	virtual ~Person() {}

	void setName(const string name);
	string getName();
	void setSalary(const double salary);
	double getSalary();
	void setCategory(const int category);
	double getCategory();

	virtual ostream& print(ostream& out) const override {
		out << name << "\t" << salary << "\t" << category;
		return out;
	}
};

