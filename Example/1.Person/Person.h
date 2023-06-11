#include<iostream>
#include<cstring>
using namespace std;
#pragma once
class Person
{
private: //приватний блок - доступ лише із методів класу.
	string firstName; //іи'я
	string lastName; //прізвище
	int age;		 //вік
	bool sex;		 //стать
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

