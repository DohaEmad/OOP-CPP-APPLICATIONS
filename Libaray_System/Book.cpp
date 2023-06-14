//
// Created by 20115 on 6/12/2023.
//

#include "Book.h"
int Book::count=0;
Book::Book()
{
    title = "";
    isbn = "";
    category ="";
    averageRating = 0.0;
    id=++count;
}
Book :: Book(string title, string isbn, string category){
    this->title = title ;
    this->isbn  = isbn ;
    this->category = category ;
    id=++count;
    averageRating = 0.0;

}
Book::Book(const Book& book){
    title = book.title;
    isbn = book.isbn;
    id = book.id;
    category = book.category;
    author = book.author;
    averageRating = book.averageRating ;
}
void Book::setTitle(string tit)
{
    title=tit ;
}
string Book::getTitle()const
{
    return title;
}
void Book::setIsbn(string isn)
{
    isbn= isn ;
}
string Book::getIsbn() const
{
    return isbn;
}

void Book::setId(int ID)
{
    id = ID;
}
int Book::getId() const
{
    return id;
}
void Book::setCategory(string cate)
{
    category=cate;
}
string Book::getCategory() const
{
    return category;
}
void Book :: setAuthor( User &user){
    author = &user ;
}
bool Book::findAuthor()
{
    return (author!=NULL);
}
User &Book :: getAuthor() {
    return *author ;
}

void Book :: rateBook(double rating){
    cntRates++;
    sumRates+=rating ;
    averageRating = sumRates/cntRates ;
}
double Book :: getAverageRating () const{
    return averageRating;
}

bool Book::operator==(const Book &book)
{
    return(title == book.title && isbn ==book.isbn && id == book.id && category == book.category && *author == *(book.author));
}

istream &operator>>( istream &is, Book &book ){
    cout<<"Enter the book information in this order "<<endl;
    cout<<"Title "<<"Isbn "<<"Category"<<endl;
    is>>book.title>>book.isbn>>book.category;
    book.averageRating = 0.0;
    return is;
}
ostream & operator<<(ostream & os,const Book & book)
{
    os<<"------------Book "<<book.id<<" info ------------"<<endl;
    os<<"Title : "<<book.title<<endl;
    os<<"Isbn : " <<book.isbn<<endl;
    os<<"Id : " <<book.id<<endl;
    os<<"Category : " <<book.category<<endl;
    os<<"Avg Rating : "<<book.averageRating<<endl;
    if (book.author!=NULL){
        cout<<"*****************author info **************** ";
        cout<<*(book.author);
    }
    return os;
}
Book::~Book() { delete author;}