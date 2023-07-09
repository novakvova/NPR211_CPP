#pragma once
template <typename T> class Doubly
{
private:
	struct Node {
		T data;  //����������, ��� ���������� � ����� ������
		Node* next; //�������� �� ��������� �������, ���� ��� ���
		Node* prev; //�������� �� �������� �������
	};
	Node* head; //�������� �� 1 ������� �����������
	Node* tail; //������ ������� � ������

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
		else { //����� � ����� ������
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			Node* node = new Node();
			node->data = data;
			node->prev = temp; //��� ������ ��������, �������� � ������ ������� ������
			node->next = nullptr;
			temp->next = node; //��� ��������� �������� �������� ��� ��� ����� �������
			tail = node; //������� �������� �� ������ �������
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
			// ���� �������, ���� �� ������ �������� ���������� � ������
			head = current->next; //������ ��������� �� ���� ������� � �����
			if (head != nullptr) //���� ������ �� ������� NULL
				head->prev = nullptr; //�������� � ������ ��� ������, �� ��� ����� ����
		}
		else { //���� ������� ���� �� ��������� �� ������
			previous->next = current->next; //��������� ������� ��������� ����� 1
			if (current->next != nullptr) //���� ���� ������� �� �����
			{
				//current->next = ���������, ���� ����, ���� �� ������ ��������
				//current->next->prev - �������� ��� ���������� ���� ����� 1 �������
				//Node* nextCurrent = current->next;
				//nextCurrent->prev = previous;
				current->next->prev = previous; //���, �� ��� ��������� ���� 
			}
		}

		if (current == tail) {
			// ���� �������, ���� ��������� � ������ - �� ������ ��� ���������
			tail = previous;
		}

		// ��������� �������� ������� �� ������, ���� ����� ��������
		delete current;
		return true;
	}

};