#include<iostream>
#include<windows.h>
using namespace std;
#include "Person.h"
#include "Waiter.h"



// Global operator<< that works with the Printable base class
std::ostream& operator<<(std::ostream& os, const Printable& obj) {
	return obj.print(os);
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//cout << "Привіт!\n";

	Person* p = new Waiter("Марко Олег", 8000, 3, 8, 18);
	cout << *p << "\n";

	

	return 0;
}