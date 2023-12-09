//	This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
 @file ArrayStack.h */

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackADT.h"

// Unless spesificed by the stack user, the default size is 100
template <typename T>
class ArrayStack : public StackADT<T>
{
private:
	T *items; // Array of stack items
	int top;  // Index to top of stack
	const int STACK_SIZE;

public:
	// Default constructor
	ArrayStack() : STACK_SIZE(100)
	{
		items = new T[STACK_SIZE];
		top = -1;
	} // end default constructor
	ArrayStack(int MaxSize) : STACK_SIZE(MaxSize)
	{
		items = new T[STACK_SIZE];
		top = -1;
	} // end default constructor

	bool isEmpty() const
	{
		return top == -1;
	} // end isEmpty

	bool push(const T &newEntry)
	{
		if (top == STACK_SIZE - 1)
			return false; // Stack is FULL

		top++;
		items[top] = newEntry;
		return true;
	} // end push

	bool pop(T &TopEntry)
	{
		if (isEmpty())
			return false;

		TopEntry = items[top];
		top--;
		return true;
	} // end pop

	bool peek(T &TopEntry) const
	{
		if (isEmpty())
			return false;

		TopEntry = items[top];
		return true;
	} // end peek

	void copy(const ArrayStack<T> &other)
	{
		items = other.items;
	}

}; // end ArrayStack

#endif
