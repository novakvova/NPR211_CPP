#pragma once
#include "Person.h";

class Student : Person
{
private:
	double mark;

public:
	Student();
	Student(const char* name, double mark);

	void showInfo();
};

