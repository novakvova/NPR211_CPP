#include <iostream>
using namespace std;
#include <windows.h>
#include "Person.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person peter;
	peter.setFirstName("�����");
	peter.setLastName("ϳ����������");
	peter.setAge(50);
	peter.setSex(true);
	cout << "-----------------Info-------------------\n";
	peter.PrintInfo();
	//cout << "�����!";
	return 0;
}