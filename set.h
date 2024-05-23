/*=======================================================
 Phan Anh Le
 Set.h
 January 2024

 This file contains the class definition for the Set class.
 
 ------------------------------------------------------------
 DESCRIPTION:
 The Set class is a collection of unique items, without a specified order. 
 The items are of the same datatype specified by a template.

 The number of items in the set is given by the cardinality of the set. 
 Items in the set do not have a specific index, as sets are not ordered. 
 However, you can check if an item exists in the set, insert new items, 
 or remove existing ones. The set dynamically adjusts its size to accommodate 
 the items, ensuring it never reaches a "full" state.

 ------------------------------------------------------------
 CONSTRUCTORS:
 There is a default constructor creating an empty set.
 There is a copy constructor to create a new set from an existing one.

 ------------------------------------------------------------
 ACCESS:
 empty: returns true if the set is empty, false otherwise.
 cardinality: returns the number of items in the set.
 contains: checks if the set contains a specific item.
 to_string: returns a string containing the set items formatted in a list.
            example: "1 2 3"
 operator<<: overloads the output stream operator for printing the set.

 ------------------------------------------------------------
 MODIFIERS:
 insert: adds a new item to the set if it does not already exist.
 remove: removes the specified item from the set.
 operator=: allows for the assignment of one set to another.
 operator+: creates a new set that is the union of two sets.
 operator&: creates a new set that is the intersection of two sets.
 operator-: creates a new set that is the difference between two sets.
 clear: removes all items from the set.
 destructor: deallocates memory used by the set.

 =======================================================*/


#include <iostream> 
#include <string> 
#include <chrono>
using namespace std; 

#ifndef SET_H
#define SET_H

template <typename T> 
class Set
{
private:
	// struct for Node for linked list
	struct Node
	{
		T		item;
		Node 	*next;
	};
	
	Node	*head;		// pointer for linked list
	
public: 
			Set				( void ); 
			Set				( const Set<T> &myset );
			~Set			( void );
void		insert			( const T& value ); 
void 		remove 			( const T& value ); 
int			cardinality 	( void ) const; 
bool 		empty			( void ) const; 
bool 		contains		(const T& value) const; 

bool		operator==		(const Set<T> &myset) const;
bool 		operator<=		(const Set<T> &myset) const;
Set<T> 		operator+		(const Set<T> &myset) const; 
Set<T> 		operator&		(const Set<T> &myset) const;
Set<T> 		operator-		(const Set<T> &myset) const;
string 		to_string		( void ) const; 

friend ostream & operator<< ( ostream &os, Set<T> &myset )
{
	Node *ptr = myset.head;
	os << "[ ";
	while ( ptr != NULL )
	{
		if ( ptr->next != NULL )
			os << ptr->item << ", ";
		else
			os << ptr->item << " ";
		ptr = ptr->next;
	}
	os << "]";
	return os;	
}
};

#endif
