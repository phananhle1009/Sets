//========================================================
// Phan Anh Le
// set.cpp
// January 2024
// This file contains the class methods for the
// Set class.
//========================================================


#include <iostream>
#include "set.h"
#include <string>
#include <chrono>
#include <sstream> 
using namespace std;

//=============================================
// default function
// The function creates a new empty Set
// Pre-condition: None.
// Post-condition: Creates an empty set.
// Parameter: void
// Return value: None
//=============================================
template <typename T>
Set<T>	::Set(void)
{
	head = NULL; 
}

//=============================================
// copy function 
// The function creates a new Set from an 
// existing one.
// Pre-condition: properly initialized Set
// Post-condition: Creates a new Set which is a deep copy of the input myset.
// Parameter: Set (myset)
// Return value: None
//=============================================

template <typename T>
Set<T>	::Set(const Set<T> &myset) 
{

    Node *otherPtr = myset.head;
    Node *last = NULL;

    while (otherPtr != NULL)
    {
        Node *newNode = new Node;
        newNode -> item = otherPtr -> item; 
        newNode -> next = NULL;

        if (last == NULL)
        {
            head = newNode;
        }
        else
        {
            last->next = newNode;
        }

        last = newNode;
        otherPtr = otherPtr->next;
    }
}

//=============================================
// destructor function
// The function cleans up the memory of the Set
// Pre-condition: None
// Post-condition: Deallocates all memory used by the Set, leaving it in an empty state.
// Parameter: void
// Return value: None
//=============================================

template <typename T>
Set<T>	::~Set(void)
{

    Node *ptr = head;
    while (ptr != NULL)
    {
        Node *nextNode = ptr->next;
        delete ptr;
        ptr = nextNode;
    }
}

//=============================================
// insert function 
// The function inserts variable into the Set
// Pre-condition: properly initialized Set
// Post-condition: Inserts the element into the Set if it's not already present
// Parameter: value
// Return value: None
//=============================================

template <typename T>
void		Set<T>::insert		( const T &value )
{
	Node *current = head;
	while ( current != NULL )
	{
		if (current->item == value)
		{
			return;
		}
		current = current->next;
	}
	Node *newNode = new Node;
	newNode->item = value;
	newNode->next = head;
	head = newNode;
}

//=============================================
// remove function 
// The function remove variable out of the Set
// Pre-condition: properly initialized Set
// Post-condition: If the element is found, it is removed from the Set
// Parameter: value
// Return value: None
//=============================================
template <typename T>
void 	Set<T>::remove(const T& value) 
{
        Node* current = head;
        Node* previous = NULL;

        while (current != NULL && current->item != value) 
        {
            previous = current;
            current = current->next;
        }

        if (current != NULL) 
        {
            if (previous != NULL) 
            {
                previous->next = current->next;
            } 
            else 
            {
                head = current->next;
            }
            delete current;
        }
}

//=============================================
// cardinality function 
// The function show the number of elements in the Set.
// Pre-condition: properly initialized Set
// Post-condition: Returns the number of elements in the Set.
// Parameter: void
// Return value: count
//=============================================
template <typename T>
int 	Set<T>::cardinality(void) const 
{
        int count = 0;
        Node* current = head;

        while (current != NULL) 
        {
            count++;
            current = current->next;
        }

        return count;
}


//=============================================
// empty function 
// The function indicate whether set is the empty set
// Pre-condition: properly initialized Set
// Post-condition: Returns true if the Set is empty, false otherwise.
// Parameter: void
// Return value: None
//=============================================
template <typename T>
bool 	Set<T>::empty(void) const 
{
        return head == NULL;
}

//=============================================
// contains function 
// The function indicate whether a specific element 
// is contained in the Set
// Pre-condition: properly initialized Set
// Post-condition: Returns true if the element is in the Set, false otherwise.
// Parameter: value
// Return value: true if the element is in the Set
// false otherwise. 
//=============================================
template <typename T>
bool Set<T>::contains(const T& value) const 
{
    Node* current = head;
    while (current != NULL) {
        if (current->item == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

//=============================================
// equality function
// Pre-condition: Both Sets should be properly initialized
// Post-condition: Returns true if both Sets contain exactly the same elements.
//=============================================
template <typename T>    
bool 	Set<T>::operator==(const Set<T>& myset) const 
{
        if (cardinality() != myset.cardinality()) 
        {
            return false;
        }

        Node* current = head;
        while (current != NULL) 
        {
            if (!myset.contains(current->item)) 
            {
                return false;
            }
            current = current->next;
        }

        return true;
}

//=============================================
// subset function 
// The function indicate whether first Set 
// is the subset of the second Set
// Pre-condition: Both Sets should be properly initialized
// Post-condition: Returns true if every element of the first Set is in the second Set.
// Parameter: myset
// Return value: true if the first Set is the subset 
// of the second Set, false otherwise 
//=============================================
template <typename T>
bool 	Set<T>::operator<=(const Set<T>& myset) const 
{
        Node* current = head;
        while (current != NULL) 
        {
            if (!myset.contains(current->item)) 
            {
                return false;
            }
            current = current->next;
        }

        return true;
    }

//=============================================
// union function 
// The function return the union of two sets 
// Pre-condition: Both Sets should be properly initialized
// Post-condition: Returns a new Set which is the union of the two Sets (containing all elements from both).
// Parameter: myset
// Return value: new union set 
//=============================================
template <typename T>
Set<T> Set<T>::operator+(const Set<T>& myset) const {
    Set<T> result;

    Node* current = myset.head;
    while (current != NULL) {
        result.insert(current->item);
        current = current->next;
    }
    current = head;
    while (current != NULL) {
        result.insert(current->item);
        current = current->next;
    }

    return result;
}


//=============================================
// intersection function 
// The function return the intersection set of 
// two sets 
// Pre-condition: Both Sets should be properly initialized
// Post-condition: Returns a new Set which is the union of the two Sets (containing all elements from both).
// Parameter: myset
// Return value: new intersection set
//=============================================
template <typename T>
Set<T> 	Set<T>::operator&(const Set<T>& myset) const 
{
        Set<T> result;
        Node* current = head;
        while (current != NULL) 
        {
            if (myset.contains(current->item)) 
            {
                result.insert(current->item);
            }
            current = current->next;
        }

        return result;
}

//=============================================
// difference function 
// The function returns the differences of the 
// first Set and the second Set. 
// Pre-condition: Both Sets should be properly initialized
// Post-condition: Returns a new Set which is the intersection of the two Sets (only elements common to both).
// Parameter: myset
// Return value: true if the first Set is the subset 
// of the second Set, false otherwise 
//=============================================
template <typename T>
Set<T> 	Set<T>::operator-(const Set<T>& myset) const 
{
        Set<T> result;
        Node* current = head;
        while (current != NULL) 
        {
            if (!myset.contains(current->item)) 
            {
                result.insert(current->item);
            }
            current = current->next;
        }

        return result;
}

//=============================================
// to_string function 
// The function returns a string with the elements
// in the set separated by a single space and starting at the head
// Pre-condition: properly initialized Set
// Post-condition: Returns a string representation of the Set's elements.
// Parameter: void
// Return value: new set.
//=============================================

template <typename T>
string Set<T>::to_string(void) const 
{
    std::stringstream output; 
    Node *current = head;
    while (current != NULL)
    {
        output << current->item;
        if (current->next != NULL)
        {
            output << " ";
        }
        current = current->next;
    }
    return output.str();
}
