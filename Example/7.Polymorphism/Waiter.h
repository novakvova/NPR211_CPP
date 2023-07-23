#pragma once
#include "Person.h"
class Waiter : public Person
{
private:
	/// <summary>
	/// ��������
	/// </summary>
	int speed;
	/// <summary>
	/// ³�
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

	friend ostream& operator<<(ostream& out, const Waiter& waiter);
};

