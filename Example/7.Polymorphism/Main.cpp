#include<iostream>
#include<windows.h>
using namespace std;
#include "Person.h"
#include "Waiter.h"
#include "Cook.h"
#include "../3.SingleList/Singly.h"

// Global operator<< that works with the Printable base class
std::ostream& operator<<(std::ostream& os, const Printable& obj) {
	return obj.print(os);
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Singly<Person*> persons;

	persons.Add(new Cook("Марко Олег", 12000, 3, "Кухар-технолог"));
	persons.Add(new Waiter("Мельник Вікторія", 8000, 3, 8, 18));
	persons.Add(new Waiter("Салько Штундер", 9000, 4, 9, 20));
	cout << persons;

	

	return 0;
}