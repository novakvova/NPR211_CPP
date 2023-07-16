#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"

Person::Person() {
	int size = strlen("no name");
	name = new char[size + 1];
	strcpy(name, "no name");
	name[size] = '\0';
	setAge(18);
}

Person::Person(const char* name) {
	setAge(18);
	setName(name);
}

Person::Person(const Person& student) {
	int size = strlen(student.name);
	this->name = new char[size + 1];
	strcpy(this->name, student.name);
	this->age = student.age;
}

Person::~Person() {
	delete[] name;
}

void Person::setAge(int age) {
	if (age < 0) {
		cout << "------Вік не може буть меншим 0------";
		return;
	}
	this->age = age;
}

void Person::setName(const char* name)
{
	delete[] this->name;
	int size = strlen(name);
	this->name = new char[size + 1];
	strcpy(this->name, name);
}

void Person::setName(const string name)
{
	delete[] this->name;
	int size = name.length();
	this->name = new char[size + 1];
	strcpy(this->name, name.c_str());
}

int Person::getAge() { return age; }
string Person::getName() { return name; }

void Person::showInfo() {
	cout << "Name: " << name << "\t" << "Age: "<<this->age << "\n";
}