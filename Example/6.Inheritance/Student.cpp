#include "Student.h"

Student::Student() {
	mark = -1;
}

Student::Student(const char* name, double mark) : Person(name)
{
	this->mark = mark;
}

void Student::showInfo() {
	Person::showInfo();
	cout << "Îö³íêà: "<<mark<<"\n";
}