//
// Created by 20115 on 6/12/2023.
//

#ifndef LIBARAY_BOOKLIST_H
#define LIBARAY_BOOKLIST_H
#include "Book.h"

class BookList {
private:
    Book** books;
    int capacity;
    int booksCount;
public:
    BookList(const BookList& anotherList);
    BookList(int capacity);
    void addBook(Book &book); // at the end of the array.
    Book* searchBook(string name);
    Book* searchBook(int id);
    void deleteBook(int id); //delete a book
    Book getTheHighestRatedBook();
    void getBooksForUser(User&); // get all books of this author
    Book & operator[] (int position);
    friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books
    ~BookList();

};


#endif //LIBARAY_BOOKLIST_H
