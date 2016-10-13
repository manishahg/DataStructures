/*
 * linkedlist.h
 *
 *  Created on: Feb 21, 2016
 *      Author: manisha
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

#define MAX 10
# define BARS  	"=========================================================="

// Define a structure to use as the list item
struct ListItem
{
	int key;
	float theData;
	ListItem *next;
};

class Linked_List {
	private:
			ListItem *head;					//Pointer to head of the list
	public:
			Linked_List();				// Class constructor
			~Linked_List();					// Class destructor
			ListItem *create_node(float value);	//Creating Node
			void ClearList();				// Remove all the items from the list
			bool Insert(int key, float f);	// Add an item to the list
			bool Delete(int key); 			// Delete an item from the list
			bool Search(int *key, float Val); // Search for an item in the list
			int ListLength();				// Return number of items in list
			bool isEmpty();					// Return true if list is empty
			bool isFull();					// Return true if list is full
			void PrintList();				// Print all items in the list
};




#endif /* LINKEDLIST_H_ */
