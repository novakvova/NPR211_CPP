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
		cout << "Елемент у списку не знайдено!\n";
	}
	cout << myList;
	cout << "List size = " << myList.Size() << endl;*/

	Singly<Student> students;
	Student vova("Novak", "096 765 89 76", 36);
	students.Add(vova);
	Student ilon("Ilon", "096 987 89 76", 36);
	students.Add(ilon);
	Student ilona("Kaban", "098 765 89 76", 30);
	students.Add(ilona);
	Student uhym("Kotel", "095 765 89 76", 65);
	students.Add(uhym);
	Student anton("Ananas", "068 765 89 76", 23);
	students.Add(anton);

	//cout << (vova>uhym) << "\n";

	cout << "---------Students---------\n";
	cout << students << "\n";
	cout << "----------Student sort-----------\n";
	students.sort();
	cout << students << "\n";
	cout << "--------Student sort revers--------\n";
	students.sort(true);
	cout << students << "\n";
	//cout << "----Remove Ілон Маск--------\n";
	//students.Remove(ilon);
	//cout << students << "\n";
	return 0;
}