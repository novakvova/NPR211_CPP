#include <iostream>
#include<windows.h>
#include "BinaryTree.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);
    tree.insert(12);
    tree.insert(-1);



    TreeNode * node = tree.search(2);
    if (node != nullptr)
    {
        std::cout << "Знайдено елемента - " << node->data << "\n";
        std::cout << "left - " << node->left << "\n";
        std::cout << "right - " << node->right << "\n";
    }
    /*if (node != nullptr)
    {
        std::cout << "Елемент знайдено: " << node->data << "\n";
    }*/
    std::cout << "Inorder traversal: ";
    tree.inorder();
    std::cout << std::endl;
	return 0;
}