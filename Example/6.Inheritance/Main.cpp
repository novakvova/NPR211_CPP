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

	/*Person ivan("������ ����");
	ivan.showInfo();*/
	//Student maksim("������ ������",4.7);
	//maksim.showInfo();

	//Person* p = new Student("ϳ���������� �����", 4.2);
	//Person* p = new Teacher("��������� �����", 50, "ճ��");
	//p->showInfo();
	Person* p;
	cout << "���� ��������: 1 - �������, 2 - ��������\n";
	int action = 1;
	cin >> action;
	if (action == 1)
		p = new Student("����� ������", 4.9);
	else
		p = new Teacher("������� ������", 55, "Գ���������");
	
	p->showInfo();
	return 0;
}
