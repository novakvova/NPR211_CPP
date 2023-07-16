#include<iostream>
#include<windows.h>
using namespace std;
#include "Person.h"
#include "Student.h"
#include "Teacher.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	/*Person ivan("Манько Іван");
	ivan.showInfo();*/
	//Student maksim("Шлунок Максим",4.7);
	//maksim.showInfo();

	//Person* p = new Student("Підкаблучник Марко", 4.2);
	//Person* p = new Teacher("Печольчик Жанна", 50, "Хімія");
	//p->showInfo();
	Person* p;
	cout << "Кого створить: 1 - студент, 2 - викладач\n";
	int action = 1;
	cin >> action;
	if (action == 1)
		p = new Student("Марко Іванка", 4.9);
	else
		p = new Teacher("Мельник Марина", 55, "Фізкультура");
	
	p->showInfo();
	return 0;
}
