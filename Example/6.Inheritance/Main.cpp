#include<iostream>
#include<windows.h>
using namespace std;
#include "Person.h"
#include "Student.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	/*Person ivan("Манько Іван");
	ivan.showInfo();*/
	Student maksim("Шлунок Максим",4.7);
	maksim.showInfo();

	return 0;
}
