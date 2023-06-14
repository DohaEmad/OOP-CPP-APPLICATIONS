#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
void main_menu(){
    cout <<"Select one of the following choices : " <<endl;
    cout<<"1- Books Menu"<<endl;
    cout<<"2- Users Menu"<<endl;
    cout<<"3- Exit "<<endl;
}
void user_menu(){
    cout<<" USERS MENU"<<endl;
    cout<<"1- Create a USER and add it to the list "<<endl;
    cout<<"2- Search for a user " <<endl;
    cout<<"3- Display all users "<<endl;
    cout<<"4- Back to the main "<<endl;
}
void search_user_menu(){
    cout<<"SEARCH FOR A USER"<<endl;
    cout<<"1- Search by name"<<endl;
    cout<<"2- Search by id"<<endl;
    cout<<"3- Return to users Menu"<<endl;
}
void delete_user_menu(){
    cout<<"1- Delete user "<<endl;
    cout<<"2- Return to users Menu"<<endl;
}
void book_menu(){
    cout<<"BOOKS MENU"<<endl;
    cout<<"1- Create a book and add it to the list "<<endl;
    cout<<"2- Search for a book"<<endl;
    cout<<"3- Display all books (with book rating)"<<endl;
    cout<<"4- Get the highest rating"<<endl;
    cout<<"5- Get all books of a user "<<endl;
    cout<<"6- Delete Book"<<endl;
    cout<<"7- rate book"<<endl;
    cout<<"8- Back to the main menu"<<endl;
}
void search_book_menu(){
    cout<<"SEARCH FOR A BOOK"<<endl;
    cout<<"1- Search by name"<<endl;
    cout<<"2- Search by id"<<endl;
    cout<<"3- Return to Books Menu"<<endl;
}
int main()
{
    User* user;
    Book *book;
    int U_B;
    while (true)
    {
        main_menu();
        cin>>U_B;
        if(U_B==1)
        {
            user_menu();
        }
        else if(U_B==2)
        {
            book_menu();
        }
        else {return 0;}

    }


}