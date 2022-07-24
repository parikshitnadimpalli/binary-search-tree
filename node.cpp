#include "node.h"

using namespace std;

Node::Node(int d) 
{
	data = d;
	left = right = nullptr;
}

int integerInput()
{
	int n;

	while (!(cin >> n)) 
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid integer input! Please try again with correct input: ";
	}

	return n;
}

Node* newNode()
{
	cout << endl << "Enter the data to be added to the new Node: ";

	Node* n = new (nothrow) Node(integerInput());

	if (n == nullptr)
	{
		cout << endl << "Failed to allocate memory to the node! Please try again." << endl;
		delete n;
		return nullptr;
	}

	return n;
}

void clearScreen()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}