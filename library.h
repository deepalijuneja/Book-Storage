//
// Created by Yusuf Pisan on 3/26/18. 
// Modifications added by Deepali Juneja on 01/07/2021.
//
// This file functions as a header file for library, and it contains the class definitions and functions, which are then implemented in the library.cpp file to execute the library program.
//

#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include <ostream>
#include <cassert>
#include <string>
#include <iostream>

// Only for class code, OK to use namespace
using namespace std;

/* The purpose of the Library class is to holds books and provide the ability for the 
books to be added, removed and be listed.
*/
class Library {

public:
	/*The constructor helps initilize the Library object
	*/
	Library(const string& Name);

	// destructor
	virtual ~Library();

	/* The addBook method enables for a new book to be added to the library.
	 *  Return: true if a book is added; false if the book is already in the library.
	 */
	bool addBook(const string& BookName); 

	/* The removeBook method enables for a book to be removed from the library.
	 * Return: true if a book is removed; false if the book is not in the library.
	 */
	bool removeBook(const string& BookName);

	// list all books
	void listAllBooks() const;

	// true if book found in library
	bool isInLibrary(const string& BookName) const;

	// display all books in library
	friend ostream& operator<<(ostream& Out, const Library& Lib);

private:
	// maximum no. of books possible to add to the library
	static const int MAX = 100;

	// library name
	static string name;

	// no. of books in the library
	int NumberOfBooks;

	// stores the library books
	string BooksLib[MAX];

	//provides valid index of library books
	int IndexOfBook(const string& name) const;
};

#endif  // ASS1_LIBRARY_H