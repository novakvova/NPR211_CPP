#pragma once
#include "Person.h"
class Waiter : public Person
{
private:
	/// <summary>
	/// Øâèäê³ñòü
	/// </summary>
	int speed;
	/// <summary>
	/// Â³ê
	/// </summary>
	int age;
public:
public:
	Waiter();
	Waiter(const string name, const double salary, const int category, 
		const int speed, const int age);
	void setSpeed(int speed);
	int getSpeed();
	void setAge(int age);
	int getAge();

	virtual ostream& print(ostream& out) const override {
		out << "-----------Îô³ö³àíò-------------\n";
		Person::print(out);
		out << "\n";
		out << "Speed: " << speed << "\t" << "Age: " << age;
		return out;
	}
};

