#pragma once
#include<iostream>
#include "TreeNode.h"

class BinaryTree {
private:
    TreeNode* root;

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

    TreeNode* searchRecursive(TreeNode* currentNode, int value) {
        //якщо поточний елемент постуий, ми стоврЇмо вузол
        if (currentNode == nullptr) {
            return nullptr; //якщо елеменn не знайдено 
        }

        if (value == currentNode->data) {
            return currentNode;
        }

        //виклик метода рекурс≥йно
        //якщо вх≥дн≥ дан≥ value < менше значенн€, €ке Ї поточним (знаходитьс€ у вузл≥ дерева
        if (value < currentNode->data) {
            return searchRecursive(currentNode->left, value); //ми ≥демо в л≥ву г≥лку
        }
        
        else {
            return searchRecursive(currentNode->right, value); //€кщо значенн€ б≥льше поточного - ≥демо в праву г≥лку
        }
        return currentNode; //вертаЇмо поточний елемент
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
};
