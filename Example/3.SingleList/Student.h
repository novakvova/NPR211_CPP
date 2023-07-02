#pragma once

#include<iostream>
#include <cstdio>
using namespace std;
class Student
{
private:
	string name;
	string phone;
	string image;
	int age;

public:
	Student(); 
	Student(const char* name, const char* phone, int age);
	Student(const char* name, const char* phone, const char* image, int age);
	Student(const Student& student);

	bool operator>(const Student& student);
	bool operator==(const Student& student);
	bool operator!=(const Student& student);
	friend ostream& operator<<(ostream& out, const Student& student);
};