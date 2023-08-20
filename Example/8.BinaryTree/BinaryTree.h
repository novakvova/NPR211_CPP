#pragma once
#include<iostream>
#include "TreeNode.h"

class BinaryTree {
private:
    TreeNode* root;

    //��������� ��������
    TreeNode* insertRecursive(TreeNode* currentNode, int value) {
        //���� �������� ������� �������, �� ������� �����
        if (currentNode == nullptr) {
            return new TreeNode(value); //C������� ����� �� ���������, ��� ����� left and right = nullptr
        }
        //������ ������ ���������
        //���� ����� ��� value < ����� ��������, ��� � �������� (����������� � ���� ������
        if (value < currentNode->data) {
            currentNode->left = insertRecursive(currentNode->left, value); //�� ����� � ��� ����
        }
        else {
            currentNode->right = insertRecursive(currentNode->right, value); //���� �������� ����� ��������� - ����� � ����� ����
        }

        return currentNode; //������� �������� �������
    }
    //����� ��������
    TreeNode* searchRecursive(TreeNode* currentNode, int value) {
        //���� �������� ������� �������, �� ������� �����
        if (currentNode == nullptr || currentNode->data == value) {
            return currentNode; //���� ������n �� �������� 
        }

        //������ ������ ���������
        //���� ����� ��� value < ����� ��������, ��� � �������� (����������� � ���� ������
        if (value < currentNode->data) {
            return searchRecursive(currentNode->left, value); //�� ����� � ��� ����
        }
        
        else {
            return searchRecursive(currentNode->right, value); //���� �������� ����� ��������� - ����� � ����� ����
        }
    }

    //����� ���������� ��������
    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    //��������� �������� �� ������
    TreeNode* removeRecursive(TreeNode* currentNode, int value) {
        if (currentNode == nullptr) {
            return nullptr;
        }
        //����� � ���
        if (value < currentNode->data) {
            currentNode->left = removeRecursive(currentNode->left, value);
        }
        //����� � �����
        else if (value > currentNode->data) {
            currentNode->right = removeRecursive(currentNode->right, value);
        }
        //���� ������� �������
        else {
            //���� ���� ����� ����
            if (currentNode->left == nullptr) {
                TreeNode* temp = currentNode->right; //������������ ����� ����
                delete currentNode; //������� ���� ���������, �� �� �� �������
                return temp;
            }
            else if (currentNode->right == nullptr) { //������������ ��� ����
                TreeNode* temp = currentNode->left;
                delete currentNode; //��������� ������ ����
                return temp;
            }

            TreeNode* minValueNode = findMinNode(currentNode->right); //������ �������� �������� �� ����� ����
            currentNode->data = minValueNode->data; //������ �������� 
            currentNode->right = removeRecursive(currentNode->right, minValueNode->data); //����� � �����
        }

        return currentNode;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value); //������ � ������
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
