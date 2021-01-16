//
// Created by Deepali Juneja on 01/07/2021.
//
// This library class demonstrates partially filles arrays. It allows books to be added or removed from the library and find books in the library.
// This file contains the definitions for library functions.


#include "library.h"
#include <iostream> 

using namespace std;

/*
* Preconditions:
* Postconditions:
* Param:
* 
*/
Library::Library(const string& Name) {
	Library::name = Name; //huh
	NumberOfBooks = 0; // huh
}

// destructor
// nothing on heap
Library::~Library() {
	// destructor
}

// true if book found in library
bool Library::isInLibrary(const string& BookName) const {
	if (NumberOfBooks == 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < NumberOfBooks; i++)
		{
			if (BooksLib[i] == BookName)
			{
				return true;
			}
		}
		return false;
	}
}



// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string& BookName) {
	if (NumberOfBooks == Library::MAX)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < NumberOfBooks; i++)
		{
			if (BooksLib[i] == BookName)
			{
				return false;
			}

		}
		BooksLib[NumberOfBooks] = BookName;
		NumberOfBooks++;
		return true;
	}
	return false;
}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string& BookName) {
	int Index = IndexOfBook(BookName);
	if (Index == -1 || NumberOfBooks == 0)
	{
		return false;
	}
	else {
		BooksLib[Index] = BooksLib[NumberOfBooks - 1];
		NumberOfBooks--;
		return true;
	}
}

// list all books


//@DEEPALI WORK ON THIS METHOD




void Library::listAllBooks() const {
	if (NumberOfBooks == 0)
	{
		cout << "Nothing" << endl;
	}
	else
	{
		for (int i = 0; i < NumberOfBooks; i++)
		{
			cout << BooksLib[i] << endl;
		}
	}
}
/* The main purpose of the method is to 

*/
int Library::IndexOfBook(const string& name) const {
	if (NumberOfBooks == 0)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < NumberOfBooks; i++)
		{
			if (BooksLib[i] == name)
			{
				return i;
			}
		}
		return -1;
	}
}



//@DEEPALI CHANGE THE OUTPUT FOR THIS TOOOO

/* The final method prints the message
*/
ostream& operator<<(ostream& Out, const Library& Lib) {
	Out << "Library: " << Library::name << endl;
	for (int i = 0; i < Lib.NumberOfBooks; i++)
	{
		Out << Lib.BooksLib[i] << ", ";
	}
	return Out;
}