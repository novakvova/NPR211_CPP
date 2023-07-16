#include<iostream>
#include<windows.h>
#include "MyReader.h"
using namespace std;
int main() 
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Привіт козаки\n";
	//Реалізація паттерна Signleton - створення об'єкта в одиночному екземплярі.
	//1. Не можна створити екземпляр класу на пряму.
	//MyReader reader; - сворення обєекта на пряму.
	//Клас екземпляр, якого не можна створить на пряму називається Абстрактний клас
	//В С++ для творення абстраткного класу ми робимо private Конструктор
	//2. Можливість створення екземпляру класа лише в одному екземплярі.
	// Наприклад, ми підлкючили до БД - підлючення на весь процес роболи лише одне.
	// Читаємо файл. - один раз підключидися і лупашимо.
	//Отримали посилання на об'єкт
	MyReader &raketa = MyReader::getInstance();
	if (true) {
		MyReader::getInstance().test();
		cout << "Object address reader: " << &MyReader::getInstance() << endl;
		MyReader& bomba = raketa;
		cout << "Address bomba " << &bomba << endl;
	}
	if (true) {
		cout << "Object address malvina: " << &MyReader::getInstance() << endl;
		MyReader::getInstance().test();
	}
	
	return 0;
}