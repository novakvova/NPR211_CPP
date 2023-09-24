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
	Animal шарик("Шарик", 2, true);
	Animal мурка("Мурка", 12, false);
	Animal кролик("Білик", 1, true);
	//cout << шарик << "\n";

	list<Animal> shelter;
	shelter.push_back(шарик);
	shelter.push_back(мурка);
	shelter.insert(shelter.end(), кролик);

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