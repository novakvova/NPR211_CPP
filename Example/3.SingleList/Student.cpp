#include "Student.h"

Student::Student()
{
	this->name = "no name";
	this->phone = "+38";
	this->age = 18;
}

Student::Student(const char* name, const char* phone, int age)
{
	this->name = name;
	this->phone = phone;
	this->age = age;
}

Student::Student(const char* name, const char* phone, const char* image, int age)
{
	this->name = name;
	this->phone = phone;
	this->age = age;

	//copy image to directory images

}

Student::Student(const Student& student)
{
	this->name = student.name;
	this->age = student.age;
	this->phone = student.phone;
}

bool Student::operator>(const Student& student)
{
	if (this->name > student.name)
		return true;
	return false;
}

bool Student::operator==(const Student& student)
{
	if (this->name == student.name)
		return true;
	return false;
}

bool Student::operator!=(const Student& student)
{
	if (this->name != student.name)
		return true;
	return false;
}

ostream& operator<<(ostream& out, const Student& student)
{
	out << student.name << "\t" << student.phone << "\t" << student.age;
	return out;
}
