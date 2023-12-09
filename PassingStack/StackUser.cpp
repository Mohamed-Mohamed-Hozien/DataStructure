#include "ArrayStack.h"

#include <iostream>
using namespace std;
#define n 10

// A function to print stack contents
// as the function should operate on a class template, the function itself should be a function template as well
template <typename T>
void PrintStack(ArrayStack<T> S)
{
	cout << endl
		 << "Printing stack contents: ";

	T x;
	while (S.pop(x))
		cout << x << " ";

	cout << endl;
}

// A function that takes a ArrayStack<T> S and returns its reverse (without affecting the orignal stack)
template <typename T>
ArrayStack<T> Reverse(ArrayStack<T> S)
{
	ArrayStack<T> Rev(n); // First creat a stack
	T Item;
	while (S.pop(Item)) // pop from S
		Rev.push(Item); // push into Rev

	return Rev;
}

template <typename T>
void ReverseMe(ArrayStack<T> &S)
{
	ArrayStack<T> Rev(n); // First creat a stack
	T Item;
	while (S.pop(Item)) // pop from S
		Rev.push(Item); // push into Rev
	S.copy(Rev);
}
// template <typename T>

int main()
{
	ArrayStack<int> stack1(n);

	int i, x;

	// Test the 1st stack by pushing 1, 2, 3, 4 and 5 then popping them.
	cout << "Testing stack 1:" << endl;
	cout << "Pushing 5 values into stack 1:" << endl;

	// Reading From the user 5 integer values
	cout << "Please Enter the 5 values to push in stack1 :";
	for (i = 0; i < 5; i++)
	{
		cin >> x;
		stack1.push(x); // pushing x to stack1
	}

	cout << "\nstack1 contents\n";
	PrintStack(stack1);

	ArrayStack<int> stack2 = Reverse(stack1);

	ReverseMe(stack1);

	PrintStack(stack1);
	// cout << "\nAfter Reverse...\nstack1 contents\n";
	// PrintStack(stack1);
	cout << "\nstack2 contents\n";
	PrintStack(stack2);

	cout << endl;
	return 0;
}
