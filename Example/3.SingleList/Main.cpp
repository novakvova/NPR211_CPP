#include <iostream>
#include<windows.h>
#include "Singly.h"
#include "Student.h"
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	/*Singly<int> myList;
	myList.Add(23);
	myList.Add(45);
	myList.Add(567);
	
	bool isDelete = myList.Remove(23);
	if (!isDelete) {
		cout << "������� � ������ �� ��������!\n";
	}
	cout << myList;
	cout << "List size = " << myList.Size() << endl;*/

	Singly<Student> students;
	Student vova("����� ���������", "096 765 89 76", 36);
	students.Add(vova);
	Student ilon("���� ����", "096 987 89 76", 36);
	students.Add(ilon);
	Student ilona("����� �����", "098 765 89 76", 30);
	students.Add(ilona);
	Student uhym("���� ������", "095 765 89 76", 65);
	students.Add(uhym);

	//cout << (vova>uhym) << "\n";

	cout << "---------Students---------\n";
	cout << students << "\n";
	cout << "----Remove ���� ����--------\n";
	students.Remove(ilon);
	cout << students << "\n";
	return 0;
}