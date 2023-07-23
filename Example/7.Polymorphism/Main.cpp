#include<iostream>
#include<windows.h>
using namespace std;
#include "Person.h"
#include "Waiter.h"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//cout << "Привіт!\n";

	Person* p = new Waiter("Марко Олег", 8000, 3, 8, 18);
	cout << *p << "\n";

	

	return 0;
}