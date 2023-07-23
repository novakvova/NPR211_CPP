#pragma once
#include"Person.h";

class Cook : public Person
{
private:
	//��� ������
	//���-�����
	//�����-��������
	//�����-��������
	string typeProfession;
public:
	Cook();
	Cook(const string name, const double salary, const int category, const string typeProfession);
	void setTypeProfession(string typeProfession);
	string getTypeProfession();
	virtual ostream& print(ostream& out) const override {
		out << "-----------�����-------------\n";
		Person::print(out);
		out << "\n";
		out << "�����������: " << typeProfession;
		return out;
	}
};

