#include<iostream>
#include<windows.h>
using namespace std;
#include "Person.h"
#include "Student.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	/*Person ivan("������ ����");
	ivan.showInfo();*/
	Student maksim("������ ������",4.7);
	maksim.showInfo();

	return 0;
}
