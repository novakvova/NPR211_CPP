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
	Person(); //Конструкто - це спеціальний метод, який автоматично визивається, коли створується об'єкт даного класу
	Person(string, string, int, bool); //конструктор із параметрами - швикда ініціалізація об'єкта при створені
	void setFirstName(string);
	string getFirstName();
	void setLastName(string);
	string getLastName();
	void setAge(int);
	int getAge();
	void setSex(bool);
	bool getSex();

	string getSexStr(); //вертає назву для статі (Чоловік або Дівчина)
	void PrintInfo();
};

