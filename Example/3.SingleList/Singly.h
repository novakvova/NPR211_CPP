#pragma once
#include<iostream>
using namespace std;

template <typename T> class Singly
{
private:
	struct Node {
		T data;  //інформація, яка зберігається у вузглі списка
		Node* next; //вказівник на наступний елемент, який іде далі
	};
	Node* head; //вказівник на 1 елемент послідовності
public:
	Singly()
	{
		head = NULL; //елементів у списку немає
	}

	void Add(T data) //додати новий елемент у послідовность
	{
		if (head == NULL) {
			//виділяю память під вузол
			Node* node = new Node;
			node->data = data; //зберігаємо дані, які нам прийшли
			node->next = NULL; //наступного елемента немає, це кінець
			head = node; // цей новий елемент стає першим
		}
		else { //якщо у списку є елементи, тоді рухаємося у кінець
			Node* temp = head;
			while (temp->next != NULL) //ідемо до останього елемента, але не в самий кінець
			{
				temp = temp->next;
			}
			Node* newNode = new Node;
			newNode->data = data;
			newNode->next = NULL;
			temp->next = newNode; //приклеюю до останього елемента наш новий вузол
		}
	}
	int Size() //Вертає кількість елементів у списку
	{
		int count = 0;
		Node* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}
	bool Remove(T data) //видаляємо елемент із списку
	{
		Node* temp = head; //зберігаємо вказівник на 1 елемент
		Node* prev = NULL; //попередній елемент
		//видаляємо перший елемент
		if (temp != NULL && temp->data == data) {
			head = temp->next; //для заголовка зміщаємо вказівник далі
			delete temp; //видаляємо вузол із пам'яті
			return true;
		}
		else {
			//ідемо по списку поки не знайдемо елемент, або не знайдемо, якщо temp==NULL
			while (temp != NULL && temp->data != data) {
				prev = temp; //збегіраю опередній елемент
				temp = temp->next; //переходми на наступний елемент
			}
			if (temp == NULL) //якщо не знайшли елемент і зайшли в кінець
				return false;
			//Якщо знайшли попескає моточний елемент
			prev->next = temp->next; //попускаю поточний елемнет, який знайшов
			delete temp; //видаляю поточний елемент
			return true;
		}
	}

	friend ostream& operator<<(ostream& os, const Singly<T>& list)
	{
		// робимо вказівничок на 1 елемент і тоді ідемо у кінець послідовності
		Singly::Node* temp = list.head;
		while (temp != NULL) {
			os << temp->data << "\n";
			temp = temp->next;
		}
		return os;
	}

	void sort(bool revers = false) {
		int size = this->Size();
		Node* temp = head;
		for (int i = 0; i < size-1; i++)
		{
			Node* next = temp->next;
			for (int j = i+1; j < size; j++)
			{
				bool isSwap=false;
				if (revers) {
					isSwap = !(temp->data > next->data);
				}
				else {
					isSwap = temp->data > next->data;
				}
				if (isSwap) {
					T tempData = temp->data;
					temp->data = next->data;
					next->data = tempData;
				}
				next = next->next;
			}
			temp = temp->next;
		}
	}
};

