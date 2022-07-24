#include <iostream>
#include <string>
#include <new>
#include <limits>

class Node 
{
	int data;
	Node *left, *right;
public:
	Node(int);
	inline int getData() { return data; }
	inline Node* getLeft() { return left; }
	inline Node* getRight() { return right; }

    friend class BinarySearchTree;
};

int integerInput();
Node* newNode();
void clearScreen();