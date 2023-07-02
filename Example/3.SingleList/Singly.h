#pragma once
#include<iostream>
using namespace std;

class Singly
{
private:
	struct Node {
		int data;  //інформація, яка зберігається у вузглі дерева
		Node* next; //вказівник на наступний елемент, який іде далі
	};
	Node* head; //вказівник на 1 елемент послідовності
public:
	Singly();
	void Add(int data); //додати новий елемент у послідовность
	int Size(); //Вертає кількість елементів у списку
	bool Remove(int data); //видаляємо елемент із списку
	friend ostream& operator<<(ostream& os, const Singly& list);
};

