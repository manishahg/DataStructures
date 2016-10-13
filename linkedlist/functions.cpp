/*
 * functions.cpp
 *
 *  Created on: Feb 21, 2016
 *      Author: manisha
 */
#include "linkedlist.h"

// Class constructor
Linked_List::Linked_List()
{
	head=NULL;
}

// Class destructor
Linked_List::~Linked_List()
{
	ListItem *ptr;
	for(ptr=head; head!=NULL; head=head->next)
		delete ptr;
}

bool Linked_List::isEmpty()					// Return true if list is empty
{
	if (head == NULL)
		return true;

	return false;
}

bool Linked_List::isFull()					// Return true if list is full
{
    if(ListLength()>=MAX)
    {
    	cout<<"The List is Full!!"<<endl;
    	return true;
    }

	return false;
}

//Creating Node
ListItem *Linked_List::create_node(float value)
{
    struct ListItem *temp;
    temp = new(struct ListItem);

    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }

	temp->theData = value;
	temp->next = NULL;
	return temp;
}

// Add an item to the list
bool Linked_List::Insert(int key, float value)
{
	//Check if the list is full
	if (isFull())
	    return false;

	struct ListItem *temp, *ptr, *start;
	int counter=0;
	temp = create_node(value);

	//Check if the list is empty
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;
        return true;
    }

    start = head;
    while (start != NULL)
    {
    	start = start->next;
        counter++;
    }

    //Inserting as 1st element
    if(key==1)
    {
        ptr = head;
        head = temp;
        head->next = ptr;
    }
    //Insert at the position requested by user
    else if (key > 1  && key <= counter)
    {
        start = head;
        for (int i = 1; i < key; i++)
        {
            ptr = start;
            start = start->next;
        }
        ptr->next = temp;
        temp->next = start;
    }
    else if (key == (counter+1)) //Insert at last
    {
        start = head;
        while (start->next != NULL)
        {
        	start = start->next;
        }
        temp->next = NULL;
        start->next = temp;
        return true;
    }
    else
    {
        cout<<"Position out of range"<<endl;
    	return false;
    }
	return true;
}

bool Linked_List::Delete(int key) 			// Delete an item from the list
{
    int i, counter = 0;
    struct ListItem *s, *ptr;

    if (isEmpty())
    {
		cout<<"The List is Empty!!"<<endl;
		return false;
    }

    s = head;
    if (key == 1)
        head = s->next;
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;
        }
        if (key > 0 && key <= counter)
        {
            s = head;
            for (i = 1;i < key;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
            free(s);
        }
        else
            cout<<"Position out of range"<<endl;

        //free(s);
    }
	return true;
}

bool Linked_List::Search(int *key, float value) // Search for an item in the list
{
	if (isEmpty())
    {
		cout<<"The List is Empty!!"<<endl;
		return false;
    }

	int pos=0;
	struct ListItem *s;
	s = head;

	while (s != NULL)
	{
		pos++;
		if (s->theData == value)
		{
			*key=pos;
			free(s);
			cout<<"Element found at position:"<<pos<<endl;
			return true;
		}
		s = s->next;
	}

	cout<<"Element  not found!!"<<endl;
	free(s);
	return false;
}

int  Linked_List::ListLength()				// Return number of items in list
{
    struct ListItem *temp;
    int len=0;

    if (isEmpty())
        return 0;
    temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

	return len;
}

void Linked_List::PrintList()				// Print all items in the list
{
    struct ListItem *temp;

    if (isEmpty())
    {
    	cout<<"The List is Empty!!"<<endl;
    	return;
    }

    temp = head;
    while (temp != NULL)
    {
        cout<<temp->theData<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

    return;
}

// Remove all the items from the list
void Linked_List::ClearList()
{
    struct ListItem *temp;

    if (isEmpty())
        return;

    while (head != NULL)
    {
    	temp = head;
        head = temp->next;
        free(temp);
    }
    return;

}
