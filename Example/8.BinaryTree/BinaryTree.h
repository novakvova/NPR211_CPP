#pragma once
#include<iostream>
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
};
