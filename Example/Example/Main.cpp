#include <iostream>
using namespace std;
#include <windows.h>

/// <summary>
/// Наш власний тип даних Студент
/// </summary>
struct StudentStruct
{
	/// <summary>
	/// Ім'я
	/// </summary>
	string name;
	/// <summary>
	/// Вік
	/// </summary>
	int age;
};
//Клас - механізм для створення об'єктів(екзамепля класу)
class MyStudent {
	//Зміні захищені самим класом, ящо специфікатор доступу не вказуємо, то буде private
private:        //інкапсуляція.
	string name; //зміни класу - називаються поля
	int age;     //зміни класу - поле age
public:
	//метод для зміни значення імені
	void setName(string name) {  //метод класу - функція в середині класу
		this->name = name; //зберігаємо для об'єкта ім'я
	}
	void setAge(int age) {  //метод класу
		if (age <= 0) {
			cerr << "Ви вказани не допстимен занчення для віку(має буть більше 0)\n";
			return;
		}
		this->age = age; 
	}
	string getName() { return name; } //метод класу
	int getAge() { return age; } //метод класу
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*StudentStruct np121[5];
	np121[0].name = "Mykyta";
	np121[0].age = -8;
	cout << "Mykyta = " << np121[0].name << "\t" << np121[0].age << "\n";*/
	//На основі класу MyStudent - створили екземпляр (об'єкт) класу test
	MyStudent test;
	test.setName("Kotel"); //викликаємо метод класу setName, я який передаємо значення імені для даного екзампляра
	test.setAge(-10); //викликаємо метод setAge - передаємо вік для даного об'єкта
	cout << test.getName() << "\t" << test.getAge() << "\n";
	return 0;
}