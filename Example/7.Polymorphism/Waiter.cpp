#include "Waiter.h"

Waiter::Waiter() : Person()
{
	speed = 5;
	age = 18;
}

Waiter::Waiter(const string name, const double salary, const int category, const int speed, const int age)
	: Person(name, salary, category)
{
	setSpeed(speed);
	setAge(age);
}

void Waiter::setSpeed(int speed)
{
	this->speed = speed;
}

int Waiter::getSpeed()
{
	return speed;
}

void Waiter::setAge(int age)
{
	this->age = age;
}

int Waiter::getAge()
{
	return age;
}
