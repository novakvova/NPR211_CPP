#pragma once
#include<iostream>
#include<fstream>
using namespace std;
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
    //�������� ������ ��������
    void clearRecursive(TreeNode* node)
    {
        if (node != nullptr) {
            clearRecursive(node->left);
            clearRecursive(node->right);
            delete node;
        }
    }

    //�������� ������ � ����
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

    //�������� ������
    void clear() {
        clearRecursive(root);
        root = nullptr;
    }
    
    //���������� � ����
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
        this->clear(); //�������� ������ ������
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
