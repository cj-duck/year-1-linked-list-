/* 
 * File:   LinkedList.cpp
 * Author: Christopher Johnson
 * Matric: 40275286
 * Last modified 31/03/2017
 * Implements the LinkedList class.
 */

#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
#include "linked_list.h"
using namespace std;

//creates an empty list
LinkedList::LinkedList()
{
    head = nullptr;
	tail = nullptr;
}

//creates a list with an initial value to store
LinkedList::LinkedList(int value)
{
	head = new Node;
	head->next = nullptr;
	head->data = value;
}

//copy constructor (performs a deep copy)
LinkedList::LinkedList(const LinkedList& rhs)
{
   
}


//destroys (cleans up) the list
LinkedList::~LinkedList()
{

}

//adds a value to the head of the list
void LinkedList::push(int value)
{
    struct Node *newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

//gets the last element from the list, without removing it
//requires: list not empty
int LinkedList::peekTail()
{
	Node *temp = head;
	// While the next node isnt NULL, set the temp node to the next node
	while (temp->next !=nullptr)
	{
		temp=temp->next;
	}
	// When the temp node's next node isnt NULL, return its data
	return temp->data;
}

//prints the list in order from head to tail
string LinkedList::toString() const
{
	string str = string();
	Node *temp = new Node;
	temp = head;
	while (temp != nullptr)
	{
		str += to_string(temp->data);
		if (temp->next != nullptr)
		{
			str += " ";
		}
		temp = temp->next;
	}
    return str;
}

//removes and returns the value at the head of the list
//requires: list not empty
int LinkedList::pop()
{
	Node *temp = head;
	head = head->next;
	delete head;
	return temp->data;
}

//adds a value to the end of the list
void LinkedList::append(int value)
{
	struct Node *newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	
	if(!head){
		head = newNode;
	}else{
		Node* tail = head;
		while(tail->next) tail=tail->next;
		tail->next = newNode;
	}
}

//appends the deep copies of the nodes of rhs on to the end of this list
void LinkedList::appendList(const LinkedList& rhs)
{
   
}

//inserts a value immediately after the first occurrence of afterValue,
//if afterValue is not in the list then inserts at the tail
void LinkedList::insertAfter(int value, int afterValue)
{
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	Node *temp = head;
	while (temp != nullptr)
	{
		if (temp->data == afterValue)
		{
			newNode->next = temp->next;
			temp->next = newNode;
		}
		temp = temp->next;
	}
}

//removes all occurrences of value from the list
void LinkedList::removeAllOccurences(int value)
{
    Node *currentNode = head;
	Node *previousNode = head;
	while(currentNode != nullptr)
		{
			if (currentNode->data == value)
			{
				if (currentNode == head)
				{
					head = head->next;
					delete currentNode;
					previousNode = head;
					currentNode = head;
				}
				else
				{
					previousNode->next = currentNode->next;
					delete currentNode;
					currentNode = previousNode;
				}
			} 
			else 
			{
					previousNode = currentNode;
					currentNode = currentNode->next;
			}
	}
}

//reverses the list
void LinkedList::reverse()
{
 	if (head == nullptr)return;
	
	Node* prev = nullptr;
	Node* current = nullptr;
	Node* next = nullptr;
	current = head;
	
	while (current!= nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

//checks if two lists are equal in state (contain the same values in the same order)
bool LinkedList::operator ==(const LinkedList& other) const
{
  	if (this->toString() == other.toString())
	{
		return true;
	}
	return false; 
}

//checks if two lists are not equal in state
bool LinkedList::operator !=(const LinkedList& other) const
{
    if (this->toString() != other.toString())
	{
		return true;
	}
	return false;
}

//pushes a new value onto the head of the list
LinkedList& LinkedList::operator +(int value)
{
    this->push(value);
    return *this;
}

//copy assignment operator (performs a deep copy)
LinkedList& LinkedList::operator =(const LinkedList& rhs)
{
    
    return *this;
}

//pushes values from an input stream onto the front of the list
std::istream& operator>>(std::istream &in, LinkedList &value)
{
   
    return in;
}

//writes the values, in order, to an output stream
std::ostream& operator<<(std::ostream &out, const LinkedList &value)
{
    
    return out;
}
