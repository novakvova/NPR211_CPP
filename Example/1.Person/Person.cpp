#include "Person.h"

void Person::setFirstName(string firstName) {
	this->firstName = firstName;
}

string Person::getFirstName() {
	return this->firstName;
}

void Person::setLastName(string lastName) {
	this->lastName = lastName;
}

string Person::getLastName() {
	return this->lastName;
}

void Person::setAge(int age) {
	this->age = age;
}

int Person::getAge() {
	return this->age;
}
void Person::setSex(bool sex) {
	this->sex = sex;
}
bool Person::getSex() {
	return sex;
}

void Person::PrintInfo() {
	string sexStr = sex ? "Чоловік" : "Дівчина";
	cout << this->lastName << " " << this->firstName << "\n";
	cout <<"Age: " << this->age << "\t" << "Sex: "<< sexStr << "\n";
}


