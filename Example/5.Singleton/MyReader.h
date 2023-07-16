#include<iostream>
#include<windows.h>
using namespace std;
#pragma once
class MyReader
{
public:
	//Посилання на об'єкт
	static MyReader& getInstance() {
		
		static MyReader instance;
		instance.count++;
		//Доступаємо до приватного конструктора проводимо через статичний і публічний метод
		 //створили об'єкт в методі класа
		return instance;
	}

	void test();

private:
	int count;

	MyReader() { count = 0; }
	~MyReader() {}

	// Private copy constructor and assignment operator to prevent copies
	MyReader(const MyReader&) = delete;
	MyReader& operator=(const MyReader&) = delete;
};

