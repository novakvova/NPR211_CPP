#pragma once
#include<iostream>
using namespace std;

class Animal
{
private:
	string name;
	int age;
	bool sex;
	
public: 
	Animal()
	{
		name = "";
		age = 1;
		sex = true;
	}
	Animal(const string name, const int age, const bool sex)
	{
		this->name = name;
		this->age = age;
		this->sex = sex;
	}
	Animal(const Animal& animal)
	{
		this->name = animal.name;
		this->age = animal.age;
		this->sex = animal.sex;
	}

	static string getSexString(const Animal & animal) {
		return animal.sex == true ? "Самець" : "Самка";
	}

	friend ostream& operator<<(ostream& out, const Animal& animal)
	{
		out << animal.name << "\t" << animal.age << "\t" << Animal::getSexString(animal);
		return out;
	}

	bool operator>(const Animal& animal)
	{
		if (this->name > animal.name)
			return true;
		return false;
	}

	bool operator<(const Animal& animal)
	{
		return !this->operator>(animal);
	}

};

