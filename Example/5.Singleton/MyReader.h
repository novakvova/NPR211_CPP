#include<iostream>
#include<windows.h>
using namespace std;
#pragma once
class MyReader
{
public:
	//��������� �� ��'���
	static MyReader& getInstance() {
		//��������� �� ���������� ������������ ��������� ����� ��������� � �������� �����
		static MyReader instance; //�������� ��'��� � ����� �����
		return instance;
	}

	void test();

private:
	MyReader() {}
};

