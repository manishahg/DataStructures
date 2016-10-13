//============================================================================
// Name        : linkedlist.cpp
// Author      : manisha agrawal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "linkedlist.h"


int main()
{
    int choice, key, position, count;
    float value;
    Linked_List sl;

    count=0;
    key=0;

    while (1)
    {
    	cout<<BARS<<endl;
    	cout<<"Enter your choice : "<<endl;
        cout<<BARS<<endl;
        cout<<"1.Insert Node"<<endl;
        cout<<"2.Delete a Particular Node"<<endl;
        cout<<"3.Search Element"<<endl;
        cout<<"4.Print Linked List"<<endl;
        cout<<"5.Display length of Linked List "<<endl;
        cout<<"6.Clear the Linked List "<<endl;
        cout<<"7.Exit "<<endl;
        cout<<BARS<<endl;
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Enter the value to be inserted: ";
            cin>>value;
            if(count)
            {
            	cout<<"Enter the key: ";
            	cin>>key;
            }

            if(sl.Insert(key, value)==false)
            	cout<<"Error:Element could not be inserted!!";
            cout<<endl;
            count=1;
            break;

        case 2:
            cout<<"Enter the position of value to be deleted: ";
            cin>>position;
            sl.Delete(position);
            break;

        case 3:
            cout<<"Enter the value to be searched: ";
            cin>>value;
            sl.Search(&key, value);
            break;

        case 4:
            cout<<"Printing the list:"<<endl;
            sl.PrintList();
            cout<<endl;
            break;

        case 5:
            cout<<"Number of elements in the list: "<<endl;
            cout << sl.ListLength();
            cout<<endl;
            break;

        case 6:
        	cout<<"Clearing the Linked List "<<endl;
        	sl.ClearList();
			cout<<endl;
			break;

        case 7:
            cout<<"Exiting..."<<endl;
            goto EXIT_PROGRAM;

        default:
            cout<<"Wrong choice"<<endl;
            break;
        }
    }
EXIT_PROGRAM:
    return 0;
}
