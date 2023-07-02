#include <iostream>
#include<windows.h>
#include "Singly.h"
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Singly myList;
	myList.Add(23);
	myList.Add(45);
	myList.Add(567);
	
	bool isDelete = myList.Remove(23);
	if (!isDelete) {
		cout << "Елемент у списку не знайдено!\n";
	}
	cout << myList;
	cout << "List size = " << myList.Size() << endl;
	return 0;
}