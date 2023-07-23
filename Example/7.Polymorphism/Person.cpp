#include "Person.h"

Person::Person() {
	setName("no name");
	setSalary(6500);
	setCategory(3);
}

Person::Person(const string name, const double salary, const int category)
{
	setName(name);
	setSalary(salary);
	setCategory(category);
}

Person::Person(const Person& person) {
	this->setName(person.name);
	this->setSalary(person.salary);
	this->setCategory(person.category);
}

void Person::setName(const string name) {
	this->name = name;
}

string Person::getName() {
	return name;
}

void Person::setSalary(const double salary) {
	this->salary = salary;
}

double Person::getSalary() {
	return salary;
}

void Person::setCategory(const int category) {
	this->category = category;
}

double Person::getCategory() {
	return category;
}

ostream& operator<<(ostream& out, const Person& person)
{
	out << person.name << "\t" << person.salary << "\t" << person.category;
	return out;
}
