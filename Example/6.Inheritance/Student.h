#pragma once
#include "Person.h";

class Student : public Person
{
private:
	double mark;

public:
	Student();
	Student(const char* name, double mark);
	Student(const char* name, int age, double mark);

	void showInfo();
};

