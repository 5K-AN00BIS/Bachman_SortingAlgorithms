#ifndef LinkedList_h
#define LinkedList_h

#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream> // For file I/O
#include "Node.h"
#include "Iterator.h"

template <class T>
class LinkedList
{
public:
	Node<T>* head; // Pointer to the head.
	Node<T>* current; // Pointer to keep track of current node.
	Node<T>* tail; // Pointer to the end node.

	// Default Constructor
	LinkedList()
	{
		head = new Node<T>();
		tail = new Node<T>();
		current = new Node<T>();
	}

	// Deconstructor
	~LinkedList()
	{
		delete head;
		delete current;
		delete tail;
	}

	// Checks to see if the list is empty and returns true if it is.
	bool isEmpty()
	{
		return (head->next == NULL);
	}

	// Inserts a new node with the desired information at the tail of the linked list.
	void insertAtTail(T& e)
	{
		if (isEmpty()) // See if the linked list is empty by checking through the isEmpty function.
		{
			Node<T>* newNode = new Node<T>(e);
			head->next = newNode;
			tail->prev = newNode;
		}
		else
		{
			Node<T>* actualLastNode = tail->prev;
			Node<T>* newNode = new Node<T>(e, NULL, actualLastNode);
			actualLastNode->next = newNode;
			tail->prev = newNode;
		}
	}

	// Deletes the selected node and moves everything around so that the list comes back together correctly.
	bool removeNode(Node<T>* r)
	{
		if (isEmpty()) // See if the linked list is empty by checking through the isEmpty function.
		{
			return false;
		}

		Node<T>* remove = tail->prev;

		while (remove != NULL) // Checks to see that the remove pointer is not NULL
		{
			if (remove == r) // If remove is equal to the information put in by the user, stop the loop.
			{
				break;
			}

			remove = remove->prev; // Sets remove to previous pointer node.
		}

		if (remove == NULL)
		{
			return false;
		}
		else
		{
			Node<T>* afterRemoval = remove->next;
			Node<T>* beforeRemoval = remove->prev;

			if (afterRemoval == NULL)
			{
				tail->prev = beforeRemoval;
			}
			else
			{
				afterRemoval->prev = beforeRemoval;
			}

			if (beforeRemoval == NULL)
			{
				head->next = afterRemoval;
			}
			else
			{
				beforeRemoval->next = afterRemoval;
			}

			delete remove;
			return true;
		}
	}

	// Creates a search function to be used in the program.
	bool findNode(int x)
	{
		Node<T>* current = head; // Initializes the current pointer at the head of the list.
		// Loop to find if the data to search is in the list.
		while (current != NULL)
		{
			if (current->nodeData == x) // If nodeData is equal to current node.
			{
				cout << "This information has been found in the list!\n" << endl;
				return true; // End loop if found, meaning it will only remove the first integer in the list to match the user search currently.
			}

			current = current->next; // Set current to next and run it again.
		}

		cout << "This information has not been found in the list. Try adding it by using 2 in the menu!\n" << endl;
		return false;
	}

	// Returns an iterator to the head.
	Iterator<T>* iteratorHead()
	{
		Iterator<T>* i = new Iterator<T>(head);

		return i;
	}

	// Returns an iterator to the tail.
	Iterator<T> iteratorTail()
	{
		Iterator<T>* i = new Iterator<T>(tail);

		return i;
	}

	// SORT FUNCTIONS BELOW
	// Insertion Sort
	void insertionSort()
	{
		Node<T>* temp = head;
		Node<T>* currentNode = head->next; // Comparative node.
		Node<T>* previousNode = head; // Node before the comparative node.

		// Return if the linked list is empty.
		if (isEmpty())
		{
			return; // Do nothing
		}
		
		// While the current node is not empty (meaning the end).
		while (currentNode != nullptr)
		{
			// If current node is larger or equal to the largest element (in case already sorted)
			if (previousNode->nodeData <= currentNode->nodeData)
			{
				currentNode = currentNode->next; // Set the current node to next value.
				previousNode = previousNode->next; // Set previous node to what current node was.
			}
			else
			{
				// If the element is smaller than the head, then the head element needs to be moved.
				if (head->nodeData > currentNode->nodeData)
				{
					previousNode->next = currentNode->next;
					currentNode->next = head;
					head = currentNode;
				}
				else
				{
					temp = head;

					// While loop to run through and make sure everything is sorted.
					while (temp->next != NULL && temp->next->nodeData < currentNode->nodeData)
					{
						temp = temp->next;
					}

					previousNode->next = currentNode->next;
					currentNode->next = temp->next;
					temp->next = currentNode;
				}
			}

			currentNode = previousNode->next;
		}
	}

	// Bubble Sort
	void bubbleSort()
	{

	}

	// Quick Sort
	void quickSort()
	{

	}
};

#endif