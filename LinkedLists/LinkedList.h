#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout<<"\nprinting list contents:\n\n";
		Node<T> *p = Head;

		while(p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}
	
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	* 
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
	}

	int itemCount() {
		int count = 0;
		Node<T>* curr = head;
		while (curr) {
			count++;
			curr = curr->getNext();
		}
		return count;
	}
	
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list

	Node<T>* getNodeAt(int position) const {

		assert((position >= 1) && (position <= itemCount));

		Node<T>* currPtr = headPtr;
		for (int skip = 1; skip < position; skip++) {
			currPtr = currPtr->getNext();
		}
		return currPtr;
	}

	bool insert(int newPosition, const T& item) {
		bool abletoInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
		if (abletoInsert) {
			Node<T>* newNodePtr = new Node<T>(item);

			if (newPosition == 1) {
				newNodePtr->setNext(headPtr);
				headPtr = newNodePtr;
			}
			else {
				Node<T>* prevPtr = getNodeAt(newPosition - 1);
				newNodePtr->setNext(prevPtr->getNext());
				prevPtr->setNext(newNodePtr);
			}
			count++;
		}
		return ableToInsert;	
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	
	bool find(const T& item) {
		Node<T>* newPtr = new Node<T>(item);
		newPtr->setNext(headPtr);
	}


	//[3]CountOccurance
	//returns how many times a certain value appeared in the list

	//[4] DeleteFirst
	//Deletes the first node in the list

	//[5] DeleteLast
	//Deletes the last node in the list

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
};

#endif	
