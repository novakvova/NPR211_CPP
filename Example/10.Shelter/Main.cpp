#include<iostream>
#include<fstream>
using namespace std;
#include<windows.h>
#include "Animal.h"
#include <list>
#include <algorithm>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Animal �����("�����", 2, true);
	Animal �����("�����", 12, false);
	Animal ������("�����", 1, true);
	//cout << ����� << "\n";

	list<Animal> shelter;
	shelter.push_back(�����);
	shelter.push_back(�����);
	shelter.insert(shelter.end(), ������);

	for (Animal animal : shelter) 
	{
		cout << animal << "\n";
	}

	shelter.sort();
	cout << "------Sort items------" << "\n";
	for (Animal animal : shelter)
	{
		cout << animal << "\n";
	}
	cin.get();
	return 0;
}