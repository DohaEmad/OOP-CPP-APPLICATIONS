//
// Created by 20115 on 6/12/2023.
//

#include "BookList.h"
BookList::BookList(int capacity) {
    books= new Book*[capacity];
    this->capacity=capacity;
    booksCount=0;
}

void BookList::addBook(Book &book)
{
    books[booksCount++]=&book;
}
Book* BookList::searchBook(string name)
{
    for (int i = 0; i <booksCount ; ++i) {
        if(books[i]->getTitle()==name)
            return books[i];
    }
    return NULL;
}

Book* BookList::searchBook(int id)
{
    for (int i = 0; i <booksCount ; ++i) {
        if(books[i]->getId()==id)
            return books[i];
    }
    return NULL;
}
void BookList::deleteBook(int id)
{
    for (int i = 0; i <booksCount ; ++i) {
        if(books[i]->getId()==id)
        {
            books[i]=NULL;
            for (int j = i; j <booksCount-1 ; ++j) {
                books[j]=books[j+1];
            }
            booksCount--;
        }
    }

}
Book BookList::getTheHighestRatedBook()
{
    double mx=-1;
    Book *ptr=NULL;
    for (int i = 0; i <booksCount ; ++i) {
        if(books[i]->getAverageRating()>mx)
        {
            mx=books[i]->getAverageRating();
            ptr=books[i];
        }
    }
    return *ptr;
}
void BookList::getBooksForUser(User& user)
{
    bool flag=false;
    for (int i = 0; i <booksCount ; ++i) {
        if(books[i]->findAuthor() && books[i]->getAuthor()==user)
        {
            flag=true;
            cout<<books[i];
        }
    }
    if(!flag)cout<<"not found any book to this user";
}
Book & BookList:: operator[] (int position)
{
    if(position<0||position>=booksCount)
    {
        cout<<"position Error"<<endl;
        exit(1);
    }
    return *books[position];
}

ostream &operator<<( ostream &os, BookList &bookList )
{
    for (int i = 0; i <bookList.booksCount ; ++i) {
        os<<*(bookList.books[i])<<endl;
    }
    return os;
}

BookList::~BookList() {
    delete[] books;  // Delete the array of User pointers
}
