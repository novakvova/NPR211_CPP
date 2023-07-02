#pragma once
#include<iostream>
using namespace std;

class Singly
{
private:
	struct Node {
		int data;  //����������, ��� ���������� � ����� ������
		Node* next; //�������� �� ��������� �������, ���� ��� ���
	};
	Node* head; //�������� �� 1 ������� �����������
public:
	Singly();
	void Add(int data); //������ ����� ������� � ������������
	int Size(); //����� ������� �������� � ������
	bool Remove(int data); //��������� ������� �� ������
	friend ostream& operator<<(ostream& os, const Singly& list);
};

