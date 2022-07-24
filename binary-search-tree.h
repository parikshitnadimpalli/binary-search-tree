#include "node.h"

class BinarySearchTree
{
    Node *root;
    public:
    inline BinarySearchTree() { root = nullptr; }
    inline bool isEmpty() { return root == nullptr; }
    inline Node* getRoot() { return root; }
    void insert(Node*);

    void preOrder(Node*);
    void inOrder(Node*);
    void postOrder(Node*);
    void print2D(Node*, int space = 0);

    int treeHeight(Node*);
    void levelOrder();
    void printCurrentLevel(Node*, int);

    Node* search(int);
    Node* del(int);
    Node* minValue(Node*);
};