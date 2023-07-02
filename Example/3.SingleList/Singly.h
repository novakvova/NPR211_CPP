#pragma once
#include<iostream>
using namespace std;

template <typename T> class Singly
{
private:
	struct Node {
		T data;  //����������, ��� ���������� � ����� ������
		Node* next; //�������� �� ��������� �������, ���� ��� ���
	};
	Node* head; //�������� �� 1 ������� �����������
public:
	Singly()
	{
		head = NULL; //�������� � ������ ����
	}

	void Add(T data) //������ ����� ������� � ������������
	{
		if (head == NULL) {
			//������ ������ �� �����
			Node* node = new Node;
			node->data = data; //�������� ����, �� ��� �������
			node->next = NULL; //���������� �������� ����, �� �����
			head = node; // ��� ����� ������� ��� ������
		}
		else { //���� � ������ � ��������, ��� �������� � �����
			Node* temp = head;
			while (temp->next != NULL) //����� �� ��������� ��������, ��� �� � ����� �����
			{
				temp = temp->next;
			}
			Node* newNode = new Node;
			newNode->data = data;
			newNode->next = NULL;
			temp->next = newNode; //�������� �� ��������� �������� ��� ����� �����
		}
	}
	int Size() //����� ������� �������� � ������
	{
		int count = 0;
		Node* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}
	bool Remove(T data) //��������� ������� �� ������
	{
		Node* temp = head; //�������� �������� �� 1 �������
		Node* prev = NULL; //���������� �������
		//��������� ������ �������
		if (temp != NULL && temp->data == data) {
			head = temp->next; //��� ��������� ������ �������� ���
			delete temp; //��������� ����� �� ���'��
			return true;
		}
		else {
			//����� �� ������ ���� �� �������� �������, ��� �� ��������, ���� temp==NULL
			while (temp != NULL && temp->data != data) {
				prev = temp; //������� ��������� �������
				temp = temp->next; //��������� �� ��������� �������
			}
			if (temp == NULL) //���� �� ������� ������� � ������ � �����
				return false;
			//���� ������� ������� �������� �������
			prev->next = temp->next; //�������� �������� �������, ���� �������
			delete temp; //������� �������� �������
			return true;
		}
	}

	friend ostream& operator<<(ostream& os, const Singly<T>& list)
	{
		// ������ ���������� �� 1 ������� � ��� ����� � ����� �����������
		Singly::Node* temp = list.head;
		while (temp != NULL) {
			os << temp->data << "\n";
			temp = temp->next;
		}
		return os;
	}
};

