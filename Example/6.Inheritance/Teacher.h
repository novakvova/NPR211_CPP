#pragma once
#include "Person.h";

class Teacher: public Person
{
private:
	string subject;

public:

	Teacher() {}
	Teacher(const char* name, int age, const char* subject) : Person(name) {
		this->setAge(age);
		this->subject = subject;
	}
	void setSubject(string subject) { this->subject = subject; }
	string getSubject() { return this->subject; }

	void showInfo() {
		Person::showInfo();
		cout << "Предмет: " << subject << "\n";
	}
};

