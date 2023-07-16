#include<iostream>
#include<windows.h>
using namespace std;
#pragma once
class MyReader
{
public:
	//Посилання на об'єкт
	static MyReader& getInstance() {
		//Доступаємо до приватного конструктора проводимо через статичний і публічний метод
		static MyReader instance; //створили об'єкт в методі класа
		return instance;
	}

	void test();

private:
	MyReader() {}
};

