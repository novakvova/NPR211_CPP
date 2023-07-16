#include<iostream>
#include<windows.h>
using namespace std;
#pragma once
class MyReader
{
public:
	//��������� �� ��'���
	static MyReader& getInstance() {
		
		static MyReader instance;
		instance.count++;
		//��������� �� ���������� ������������ ��������� ����� ��������� � �������� �����
		 //�������� ��'��� � ����� �����
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

