#include "binary-search-tree.h"

using namespace std;

void BinarySearchTree::insert(Node *n)
{
    if (isEmpty())
    {
        root = n;
        cout << endl << "Tree was empty. Node successfully inserted at Root!" << endl;
        return;
    }
    if (n == nullptr)
        return;
    
    Node* temp = root;

    while (1)
    {
        if (n->data == temp->data)
        {
            cout << endl << "Duplicate values not allowed!" << endl;
            temp = nullptr;
            delete temp;
            return;
        }

        if (n->data < temp->data)
        {
            if (temp->left == nullptr)
            {
                temp->left = n;
                temp = nullptr;
                delete temp;
                cout << endl << "Node successfully inserted!" << endl;
                return;
            }
            else
                temp = temp->left;
        }

        if (n->data > temp->data)
        {
            if (temp->right == nullptr)
            {
                temp->right = n;
                temp = nullptr;
                delete temp;
                cout << endl << "Node successfully inserted!" << endl;
                return;
            }
            else
                temp = temp->right;
        }   
    }
}

void BinarySearchTree::preOrder(Node *trav)
{   
    if (isEmpty())
    {
        cout << endl << "The tree is empty!" << endl;
        return;
    }
    if (trav == nullptr)
    {
        delete trav;
        return;
    }

    cout << trav->data << ", ";
    preOrder(trav->left);
    preOrder(trav->right);

    trav = nullptr;
    delete trav;
}

void BinarySearchTree::inOrder(Node *trav)
{
    if (isEmpty())
    {
        cout << endl << "The tree is empty!" << endl;
        return;
    }
    if (trav == nullptr)
    {
        delete trav;
        return;
    }

    inOrder(trav->left);
    cout << trav->data << ", ";
    inOrder(trav->right);

    trav = nullptr;
    delete trav;
}

void BinarySearchTree::postOrder(Node *trav)
{
    if (isEmpty())
    {
        cout << endl << "The tree is empty!" << endl;
        return;
    }
    if (trav == nullptr)
    {
        delete trav;
        return;
    }

    postOrder(trav->left);
    postOrder(trav->right);
    cout << trav->data << ", ";

    trav = nullptr;
    delete trav;
}

void BinarySearchTree::print2D(Node *trav, int space)
{
    if (isEmpty())
    {
        cout << endl << "The tree is empty!" << endl;
        return;
    }
    if (trav == nullptr)
    {
        delete trav;
        return;
    }

    space += 5;
    print2D(trav->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
    {
        cout << " ";
    }
    cout << trav->data << endl;

    print2D(trav->left, space);

    trav = nullptr;
    delete trav;
}

int BinarySearchTree::treeHeight(Node *trav)
{
    if (trav == nullptr)
    {
        delete trav;
        return -1;
    }

    int lHeight = treeHeight(trav->left);
    int rHeight = treeHeight(trav->right);
    trav = nullptr;
    delete trav;

    if (lHeight > rHeight)
        return lHeight + 1;
    else
        return rHeight + 1;
}

void BinarySearchTree::levelOrder()
{
    if (isEmpty())
    {
        cout << endl << "The Tree is empty!" << endl;
        return;
    }

    int height = treeHeight(root), level = 0;
    
    cout << endl;
    for (level; level <= height; level++)
    {
        printCurrentLevel(root, level);
    }
    cout << endl;
}

void BinarySearchTree::printCurrentLevel(Node *trav, int level)
{
    if (trav == nullptr)
    {
        delete trav;
        return;
    }

    if (level == 0)
        cout << trav->data << ", ";
    else
    {
        printCurrentLevel(trav->left, level - 1);
        printCurrentLevel(trav->right, level - 1);
    }

    trav = nullptr;
    delete trav;
}

Node* BinarySearchTree::search(int d)
{
    if (isEmpty())
    {
        cout << endl << "Tree is empty!" << endl;
        return nullptr;
    }
    
    Node* temp = root;

    while (1)
    {
        if (temp == nullptr)
        {
            cout << endl << "Data does not exist in the tree!" << endl;
            return nullptr;
        }
        
        if (d == temp->right->data || d == temp->left->data) // Return previous node
        {
            cout << endl << "Data found!" << endl;
            return temp;
        }

        if (d < temp->data)
            temp = temp->left;
        if (d > temp->data)
            temp = temp->right;   
    }
}

/* 
For the Delete operation, you need to test 3 special cases within 2 conditions.
Condition 1: Node to be deleted is in left subtree
Condition 2: Node to be deleted is in right subtree
Special case 1: Node to be deleted has empty left pointer
Special case 2: Node to be deleted has empty right pointer
Special case 3: Node to be deleted has empty left pointer of right pointer (delNode->right->left == nullptr)

If none of the special cases are satisfied you will get the previous node of the minimum value
from the right subtree and swap the node to be deleted with the minimum value node.

If special case 3 or no special case is executed, you will call the function recursively
*/

Node* BinarySearchTree::del(int d)
{
    Node *prevNode = search(d);
    Node *delNode, *min, *minPrev;
    if (prevNode == nullptr)
    {
        delete prevNode;
        delete delNode;
        return nullptr;
    }

    if (d == prevNode->left->data)          // If the Node to be deleted is left of its parent
    {
        delNode = prevNode->left;
        if (delNode->left == nullptr)
        {
            prevNode->left = delNode->right;
            delNode->right = nullptr;
        }
        else if (delNode->right == nullptr)
        {
            prevNode->left = delNode->left;
            delNode->left = nullptr;
        }
        else
        {
            if (delNode->right->left == nullptr)
            {
                min = delNode->right;
                prevNode->left = min; // Replacing delNode with min
                min->left = delNode->left;
                delNode->left = nullptr; // Replacing delNode with min
                delNode->right = min->right;
                min->right = delNode; // Connecting min and DelNode
            }
            else
            {
                minPrev = minValue(delNode->right);
                min = minPrev->left;
                prevNode->left = min; // Replacing delNode with min
                min->left = delNode->left;
                min->right = delNode->right;
                minPrev->left = delNode; // Replacing min with delNode
                delNode->left = delNode->right = nullptr;
            }
            del(d);
        }
    }
    if (d == prevNode->right->data)        // If the Node to be deleted is right of its parent
    {
        delNode = prevNode->right;
        if (delNode->left == nullptr)
        {
            prevNode->right = delNode->right;
            delNode->right = nullptr;
        }
        else if (delNode->right == nullptr)
        {
            prevNode->right = delNode->left;
            delNode->left = nullptr;
        }
        else
        {
            if (delNode->right->left == nullptr)
            {
                min = delNode->right;
                prevNode->right = min; // Replacing delNode with min
                min->left = delNode->left;
                delNode->left = nullptr; // Replacing delNode with min
                delNode->right = min->right;
                min->right = delNode; // Connecting min and DelNode
            }
            else
            {
                minPrev = minValue(delNode->right);
                min = minPrev->left;
                prevNode->right = min; // Replacing delNode with min
                min->left = delNode->left;
                min->right = delNode->right;
                minPrev->left = delNode; // Replacing min with delNode
                delNode->left = delNode->right = nullptr;
            }
            del(d);
        }
    }

    prevNode = min = minPrev = nullptr;
    delete prevNode;
    return delNode;
}

Node* BinarySearchTree::minValue(Node* trav)
{
    while (trav->left->left != nullptr)     // If next to next node is not empty
    {
        trav = trav->left;
    }

    return trav;
}