#include "Student.h"

Student::Student() : Person() {
	mark = -1;
}

Student::Student(const char* name, double mark) : Person(name)
{
	this->mark = mark;
}

Student::Student(const char* name, int age, double mark) : Person(name)
{
	this->setAge(age);
	this->mark = mark;
}

void Student::showInfo() {
	Person::showInfo();
	cout << "Îö³íêà: "<<mark<<"\n";
}