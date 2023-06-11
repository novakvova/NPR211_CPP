#include <iostream>
using namespace std;
#include <windows.h>

/// <summary>
/// ��� ������� ��� ����� �������
/// </summary>
struct StudentStruct
{
	/// <summary>
	/// ��'�
	/// </summary>
	string name;
	/// <summary>
	/// ³�
	/// </summary>
	int age;
};
//���� - ������� ��� ��������� ��'����(��������� �����)
class MyStudent {
	//��� ������� ����� ������, ��� ������������ ������� �� �������, �� ���� private
private:        //������������.
	string name; //���� ����� - ����������� ����
	int age;     //���� ����� - ���� age
public:
	//����� ��� ���� �������� ����
	void setName(string name) {  //����� ����� - ������� � ������� �����
		this->name = name; //�������� ��� ��'���� ��'�
	}
	void setAge(int age) {  //����� �����
		if (age <= 0) {
			cerr << "�� ������� �� ��������� �������� ��� ���(�� ���� ����� 0)\n";
			return;
		}
		this->age = age; 
	}
	string getName() { return name; } //����� �����
	int getAge() { return age; } //����� �����
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*StudentStruct np121[5];
	np121[0].name = "Mykyta";
	np121[0].age = -8;
	cout << "Mykyta = " << np121[0].name << "\t" << np121[0].age << "\n";*/
	//�� ����� ����� MyStudent - �������� ��������� (��'���) ����� test
	MyStudent test;
	test.setName("Kotel"); //��������� ����� ����� setName, � ���� �������� �������� ���� ��� ������ ����������
	test.setAge(-10); //��������� ����� setAge - �������� �� ��� ������ ��'����
	cout << test.getName() << "\t" << test.getAge() << "\n";
	return 0;
}