#pragma once
#include <iostream>
using namespace std;

//��������� - ����� ������, �� ����� ���� � ����� ������
class Printable {
public:
	virtual ~Printable() {}
	virtual ostream& print(ostream& os) const = 0;
};

