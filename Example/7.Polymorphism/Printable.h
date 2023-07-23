#pragma once
#include <iostream>
using namespace std;

//Інтерфейс - описує методи, які мають буть в інших класах
class Printable {
public:
	virtual ~Printable() {}
	virtual ostream& print(ostream& os) const = 0;
};

