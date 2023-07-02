#include "Singly.h"
#include <cstddef>

Singly::Singly()
{
	head = NULL; //елемент≥в у списку немаЇ
}

void Singly::Add(int data)
{
	if (head == NULL) {
		//вид≥л€ю пам€ть п≥д вузол
		Node* node = new Node; 
		node->data = data; //збер≥гаЇмо дан≥, €к≥ нам прийшли
		node->next = NULL; //наступного елемента немаЇ, це к≥нець
		head = node; // цей новий елемент стаЇ першим
	}
	else { //€кщо у списку Ї елементи, тод≥ рухаЇмос€ у к≥нець
		Node* temp = head;
		while (temp->next != NULL) //≥демо до останього елемента, але не в самий к≥нець
		{
			temp = temp->next;
		}
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		temp->next = newNode; //приклеюю до останього елемента наш новий вузол
	}
}

int Singly::Size()
{
	int count=0;
	Node* temp=head;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

bool Singly::Remove(int data)
{
	Node* temp = head; //збер≥гаЇмо вказ≥вник на 1 елемент
	Node* prev = NULL; //попередн≥й елемент
	//видал€Їмо перший елемент
	if (temp != NULL && temp->data == data) {
		head = temp->next; //дл€ заголовка зм≥щаЇмо вказ≥вник дал≥
		delete temp; //видал€Їмо вузол ≥з пам'€т≥
		return true;
	}
	else {
		//≥демо по списку поки не знайдемо елемент, або не знайдемо, €кщо temp==NULL
		while (temp != NULL && temp->data != data) {
			prev = temp; //збег≥раю опередн≥й елемент
			temp = temp->next; //переходми на наступний елемент
		}
		if (temp == NULL) //€кщо не знайшли елемент ≥ зайшли в к≥нець
			return false;
		//якщо знайшли попескаЇ моточний елемент
		prev->next = temp->next; //попускаю поточний елемнет, €кий знайшов
		delete temp; //видал€ю поточний елемент
		return true;
	}
}

ostream& operator<<(ostream& os, const Singly& list)
{
	// робимо вказ≥вничок на 1 елемент ≥ тод≥ ≥демо у к≥нець посл≥довност≥
	Singly::Node* temp = list.head; 
	while (temp != NULL) {
		os << temp->data << "\n";
		temp = temp->next;
	}
	return os;
}
