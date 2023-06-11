#include <iostream>
#include <ctime>
using namespace std;
#include <windows.h>
#include "Person.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//бере поточний час - час може прдеставлятися у вигляді числа
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int value = rand() % 10;
		cout << value<<"\t";
	}
	cout << endl;
	Person oksana;   //використовуємо конструкто по замовчуванню
	oksana.PrintInfo();
	Person andriy("Андрій", "Мельник", 19, true); //
	andriy.PrintInfo();
	Person peter;
	peter.PrintInfo();
	peter.setFirstName("Петро");
	peter.setLastName("Підкаблучник");
	peter.setAge(50);
	peter.setSex(true);
	cout << "-----------------Info-------------------\n";
	peter.PrintInfo();
	//cout << "Привіт!";
	return 0;
}