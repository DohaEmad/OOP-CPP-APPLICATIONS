//
// Created by 20115 on 6/12/2023.
//
#include "User.h"
#include "iostream"
#include "string"
using namespace std;
#ifndef LIBARAY_BOOK_H
#define LIBARAY_BOOK_H
class Book
{
private:
    string title;
    string isbn;
    int id;
    string category;
    double averageRating;
    User *author=NULL;
    int cntRates=0;
    double sumRates=0;
public:
    static int count;
    Book();
    Book(string , string , string );
    Book(const Book& );
    void setTitle(string );
    string getTitle() const ;
    void setIsbn(string );
    string getIsbn() const;
    void setId(int);
    int getId() const;
    void setCategory(string );
    string getCategory()const;
    void setAuthor( User & );
    bool findAuthor();
    User &getAuthor();
    void rateBook(double );
    double getAverageRating () const;
    bool operator==(const Book&);
    friend ostream &operator<<(ostream &, const Book &);
    friend istream &operator>>( istream &, Book &);
    ~Book();
};

#endif //LIBARAY_BOOK_H
