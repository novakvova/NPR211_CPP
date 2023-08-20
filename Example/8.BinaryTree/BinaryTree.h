#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include "TreeNode.h"

class BinaryTree {
private:
    TreeNode* root;

    //додаванн€ елемента
    TreeNode* insertRecursive(TreeNode* currentNode, int value) {
        //якщо поточний елемент постуий, ми стоврЇмо вузол
        if (currentNode == nullptr) {
            return new TreeNode(value); //Cтворили вузол ≥з значенн€м, при цьому left and right = nullptr
        }
        //виклик метода рекурс≥йно
        //якщо вх≥дн≥ дан≥ value < менше значенн€, €ке Ї поточним (знаходитьс€ у вузл≥ дерева
        if (value < currentNode->data) {
            currentNode->left = insertRecursive(currentNode->left, value); //ми ≥демо в л≥ву г≥лку
        }
        else {
            currentNode->right = insertRecursive(currentNode->right, value); //€кщо значенн€ б≥льше поточного - ≥демо в праву г≥лку
        }

        return currentNode; //вертаЇмо поточний елемент
    }
    //пошук елемента
    TreeNode* searchRecursive(TreeNode* currentNode, int value) {
        //якщо поточний елемент постуий, ми стоврЇмо вузол
        if (currentNode == nullptr || currentNode->data == value) {
            return currentNode; //якщо елеменn не знайдено 
        }

        //виклик метода рекурс≥йно
        //якщо вх≥дн≥ дан≥ value < менше значенн€, €ке Ї поточним (знаходитьс€ у вузл≥ дерева
        if (value < currentNode->data) {
            return searchRecursive(currentNode->left, value); //ми ≥демо в л≥ву г≥лку
        }
        
        else {
            return searchRecursive(currentNode->right, value); //€кщо значенн€ б≥льше поточного - ≥демо в праву г≥лку
        }
    }

    //пошук м≥н≥мального елемента
    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    //видаленн€ елемнета ≥з дерева
    TreeNode* removeRecursive(TreeNode* currentNode, int value) {
        if (currentNode == nullptr) {
            return nullptr;
        }
        //≥демо в л≥во
        if (value < currentNode->data) {
            currentNode->left = removeRecursive(currentNode->left, value);
        }
        //≥демо в право
        else if (value > currentNode->data) {
            currentNode->right = removeRecursive(currentNode->right, value);
        }
        //€кщо знайшли елемент
        else {
            //якщо зл≥ва н≥кого немаЇ
            if (currentNode->left == nullptr) {
                TreeNode* temp = currentNode->right; //запам€товуЇмо праву г≥лку
                delete currentNode; //поточну г≥лку видал€Їмо, бо ми њњ знайшли
                return temp;
            }
            else if (currentNode->right == nullptr) { //«апам€товуЇмо л≥ву г≥лку
                TreeNode* temp = currentNode->left;
                delete currentNode; //видал€Їмо поточн≥ г≥лку
                return temp;
            }

            TreeNode* minValueNode = findMinNode(currentNode->right); //шукаЇмо м≥н≥мальне значенн€ по прав≥й г≥лц≥
            currentNode->data = minValueNode->data; //«м≥нуЇмо значенн€ 
            currentNode->right = removeRecursive(currentNode->right, minValueNode->data); //≥демо в право
        }

        return currentNode;
    }
    //очистить дерево елемент≥в
    void clearRecursive(TreeNode* node)
    {
        if (node != nullptr) {
            clearRecursive(node->left);
            clearRecursive(node->right);
            delete node;
        }
    }

    //«берегти дерево у файл
    void savePreorder(TreeNode* currentNode, ofstream& outFile) {
        if (currentNode != nullptr) {
            outFile << currentNode->data << " ";
            savePreorder(currentNode->left, outFile);
            savePreorder(currentNode->right, outFile);
        }
    }


public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value); //≥нсерт в дерево
    }

	void inorderTraversal(TreeNode* currentNode) {
		if (currentNode == nullptr) {
            //std::cout << "Current Value = " << "-----NULL-----\n";
			return;
		}
        //std::cout << "----Go to left branch---\n";
        inorderTraversal(currentNode->left);
		std::cout << currentNode->data << "\n";
        //std::cout << "----Go to right branch---\n";
        inorderTraversal(currentNode->right);
	}

    void inorder() {
        inorderTraversal(root);
    }

    TreeNode * search(int data)
    {
        TreeNode * item = searchRecursive(root, data);
        return item;
    }

    void remove(int value) {
        root = removeRecursive(root, value);
    }

    //очистить дерево
    void clear() {
        clearRecursive(root);
        root = nullptr;
    }
    
    //«береженн€ у файл
    void saveToFile(const std::string& filename) {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            savePreorder(root, outFile);
            outFile.close();
            std::cout << "Tree saved to " << filename << std::endl;
        }
        else {
            std::cerr << "Error opening file for writing." << std::endl;
        }
    }

    

    void readFromFile(const std::string& filename) {
        this->clear(); //очисчаЇмо старий список
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            int data = 0;
            while (inFile >> data) {
                this->insert(data);
            }
            inFile.close();
            std::cout << "Tree read from " << filename << std::endl;
        }
        else {
            std::cerr << "Error opening file for reading." << std::endl;
        }
    }
};
