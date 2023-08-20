#include <iostream>
#include<windows.h>
#include "BinaryTree.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    BinaryTree tree;
   /* tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);
    tree.insert(12);
    tree.insert(-1);*/

    //tree.saveToFile("vova.txt");
    tree.readFromFile("vova.txt");
    
    tree.inorder();
    /*TreeNode * node = tree.search(2);
    if (node != nullptr)
    {
        std::cout << "Знайдено елемента - " << node->data << "\n";
        std::cout << "left - " << node->left << "\n";
        std::cout << "right - " << node->right << "\n";
    }
    std::cout << "Список елементів дерева: ";
    tree.inorder();
    std::cout << std::endl;

    tree.remove(5);

    tree.insert(6);

    std::cout << "Після видалення 2: ";
    tree.inorder();
    std::cout << std::endl;

    tree.clear();
    std::cout << "Clear: ";
    tree.inorder();
    std::cout << std::endl;*/
	return 0;
}