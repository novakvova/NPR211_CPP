#pragma once
#include<iostream>
#include<fstream>
using namespace std;

enum PersonType
{
	COOK=0, //повар
	WAITER=1 //офіціант
};

class Person
{
private:
	string name;
	//зарплата
	double salary;
	/// <summary>
	/// Розряд
	/// </summary>
	int category;
public:
	Person();
	Person(const string name, const double salary, int category);
	Person(const Person& person);
	void setName(const string name);
	string getName();
	void setSalary(const double salary);
	double getSalary();
	void setCategory(const int category);
	double getCategory();
};

