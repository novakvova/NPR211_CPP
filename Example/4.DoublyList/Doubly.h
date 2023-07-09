#pragma once
template <typename T> class Doubly
{
private:
	struct Node {
		T data;  //≥нформац≥€, €ка збер≥гаЇтьс€ у вузгл≥ списка
		Node* next; //вказ≥вник на наступний елемент, €кий ≥де дал≥
		Node* prev; //вказ≥вник на попердн≥й елемент
	};
	Node* head; //вказ≥вник на 1 елемент посл≥довност≥
	Node* tail; //остан≥й елемент у списку

public: 
	Doubly() {
		head = tail = nullptr;
	}
	void Add(T data) {
		if (head == nullptr) {
			Node* node = new Node;
			node->data = data;
			node->prev = node->next = nullptr;
			head = tail = node;
			
		}
		else { //≥демо в к≥нець списку
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			Node* node = new Node();
			node->data = data;
			node->prev = temp; //ƒл€ нового елемента, попердн≥м Ї остан≥й елемент списку
			node->next = nullptr;
			temp->next = node; //ƒл€ останього елемента настуний стаЇ наш новий елемент
			tail = node; //збер≥гаю вказ≥вник на остан≥й елемент
		}
	}

	friend ostream& operator<<(ostream& os, const Doubly<T>& list) {
		Doubly::Node* temp = list.head;
		while (temp != nullptr) {
			os << temp->data << "\n";
			temp = temp->next;
		}
		return os;
	}
	bool Delete(T value) {
		if (head == nullptr) {
			cout << "List is empty. Nothing to delete.\n";
			return false;
		}
		Node* current = head;
		Node* previous = nullptr;
		// Traverse the list to find the element to be deleted
		while (current != nullptr && current->data != value) {
			previous = current;
			current = current->next;
		}
		if (current == nullptr) {
			std::cout << "Element " << value << " not found in the list.\n";
			return false;
		}

		// Adjust the previous and next pointers of the neighboring nodes
		if (previous == nullptr) {
			// якщо елемент, €кий ми хочемо видалить получаЇтьс€ Ї першим
			head = current->next; //√олову перем≥щаЇмо на одну позиц≥ю в перед
			if (head != nullptr) //якщо голова не дор≥внюЇ NULL
				head->prev = nullptr; //ѕопердн≥й у голови стаЇ пустим, бо там н≥кого немаЇ
		}
		else { //якщо елемент €кий ми видал€Їмо не перший
			previous->next = current->next; //попередн≥й елемент перепригуЇ через 1
			if (current->next != nullptr) //якщо п≥сл€ поточно не к≥нець
			{
				//current->next = наступний, п≥сл€ того, €кий ми хочемо видалить
				//current->next->prev - попердн≥й дл€ наступного думаЇ через 1 елемент
				//Node* nextCurrent = current->next;
				//nextCurrent->prev = previous;
				current->next->prev = previous; //“ой, що був наступний п≥сл€ 
			}
		}

		if (current == tail) {
			// якщо елемнет, €кий видал€Їмо Ї остан≥й - то остан≥й стаЇ опереедн≥м
			tail = previous;
		}

		// ¬идал€Їмо поточний елемент ≥з списку, €кий треба видалить
		delete current;
		return true;
	}

};