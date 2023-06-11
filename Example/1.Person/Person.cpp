#include "Person.h"
//конструктор по замовчюуванню - визивається автоматично
Person::Person() {
	//cout << "Персону створено :)\n";
	this->firstName = "noName";
	this->lastName = "noLastName";
	this->sex = false;
	this->age = 0;
}
//Конструктор із параметрами
Person::Person(string firstName, string lastName, int age, bool sex) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->sex = sex;
	this->age = age;
}

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
	cout << this->lastName << " " << this->firstName << "\n";
	cout <<"Age: " << this->age << "\t" << "Sex: "<< this->getSexStr() << "\n";
}

string Person::getSexStr() {
	return sex ? "Чоловік" : "Дівчина";
}


