/*
AUTHOR  :   Parikshit Nadimpalli
NAME    :   Binary Search Tree
VERSION :   v1.0
*/
#include "binary-search-tree.h"

using namespace std;

int main()
{
    BinarySearchTree *bst = new (nothrow) BinarySearchTree();
    if (bst == nullptr)
    {
        cout << endl << "Failed to allocate memory for Binary Search Tree! Please restart the application!" << endl;
        return 0;
    }

    cout << "-------------------Program to implement Binary Search Tree-------------------" << endl << endl << endl;

    int op, val;
    string msg;
    Node *temp;

    while (1)
    {
        cout << endl;
        cout << "\t\t\t|  Enter any one of the options below:      |" << endl;
		cout << "\t\t\t|                                           |" << endl;
		cout << "\t\t\t| NOTE: The BST can only store integer      |" << endl;
		cout << "\t\t\t|       values. Duplicate values not        |" << endl;
		cout << "\t\t\t|                allowed.                   |" << endl;
        cout << "\t\t\t|                                           |" << endl;
		cout << "\t\t\t|             Press 0 to exit               |" << endl;
		cout << "\t\t\t|    1. Insert a value into the BST         |" << endl;
		cout << "\t\t\t|    2. Print the BST in Pre-Order          |" << endl;
		cout << "\t\t\t|    3. Print the BST in In-Order           |" << endl;
		cout << "\t\t\t|    4. Print the BST in Post-Order         |" << endl;
		cout << "\t\t\t|    5. Print the BST as a 2D Graph         |" << endl;
		cout << "\t\t\t|    6. Return height of the BST            |" << endl;
		cout << "\t\t\t|    7. Print the BST in Level-Order        |" << endl;
		cout << "\t\t\t|    8. Search for a value                  |" << endl;
		cout << "\t\t\t|    9. Delete a value from the BST         |" << endl;
		cout << "\t\t\t|   10. Clear screen                        |" << endl;
		cout << "\t\tEnter option: ";
		op = integerInput();

		switch (op) 
        {
		case 0:
            return 0;
			break;
		case 1:
			bst->insert(newNode());
			break;
		case 2:
            cout << endl;
			bst->preOrder(bst->getRoot());
            cout << endl;
			break;
		case 3:
            cout << endl;
			bst->inOrder(bst->getRoot());
            cout << endl;
			break;
		case 4:
            cout << endl;
			bst->postOrder(bst->getRoot());
            cout << endl;
			break;
		case 5:
            cout << endl;
			bst->print2D(bst->getRoot());
            cout << endl;
			break;
		case 6:
			cout << endl << "The height of the Tree is: " << bst->treeHeight(bst->getRoot()) << endl;
			break;
		case 7:
			bst->levelOrder();
			break;
		case 8:
            cout << endl << "Enter the value you want to search for: ";
            val = integerInput();
            temp = bst->search(val);
			if (temp == nullptr)
                cout << "";
            else
            {
                if (val == temp->getLeft()->getData())
                    temp = temp->getLeft();
                else
                    temp = temp->getRight();
                cout << "Located at address : " << temp << endl;
                temp = nullptr;
            }
            delete temp;
			break;
		case 9:
			cout << endl << "Enter the value you want to delete: ";
            temp = bst->del(integerInput());
            msg = temp == nullptr ? " " : "Node successfully deleted at address: ";
            cout << msg << temp << endl;
            temp = nullptr;
            delete temp;
			break;
		case 10:
			clearScreen();
			break;
		default:
			cout << endl << "Invalid option!";
			break;
		}
    }

    return 0;
}