/*
 -----------------------------------------------------------
 Author:  Doha Abdelbasset Ahmed
 Program: Online Shopping System
 -----------------------------------------------------------
 */
#include <iostream>
#include "Item.h"
#include "Seller.h"
using namespace std;

int main()
{
    // Get the details from seller
    string name,email;
    int max;
    cout<<"please Enter your details"<<endl;
    cout<<"Name: ";
    cin>>name;
    cout<<"Email: ";
    cin>>email;
    cout<<"MaxItems: ";
    cin>>max;
    Seller s(name,email,max);
    //Show him a menu to choose from the following options
    while(true)
    {
        cout<<endl;
        cout<<"1.Print My Info"<<endl;
        cout<<"2.Add An Item"<<endl;
        cout<<"3.Sell An Item"<<endl;
        cout<<"4.Print Items"<<endl;
        cout<<"5.Find an Item by ID"<<endl;
        cout<<"6.Exit"<<endl<<endl;
        int choose; cin>>choose;
        if(choose==1) // option no. 1(print Seller's info.)
        {
            cout<<"Your details"<<endl;
            cout<<s;
        }

        else if(choose==2) // option no. 2(Add an Item)
        {
            cout<<"Add Item"<<endl;
            Item objj;
            cin>>objj;
            cout<<"--------------------------"<<endl;
            if(s.AddAnItem(objj))
                cout<<"Successful addition"<<endl;
            else
                cout<<"There is no capacity to Add "<<endl;
            cout<<"--------------------------"<<endl;
        }

        else if(choose==3) // option no. 3(Sell an Item)
        {
            cout<<"Sell Item"<<endl;
            string n;
            int qu;
            cout<<"The Item's name you want to sell : ";
            cin>>n;
            cout<<"The Item's Quantity you want to sell : ";
            cin>>qu;
            cout<<"--------------------------"<<endl;
            if(s.Sell_An_Item(n,qu))
                cout<<"successful Selling"<<endl;
            else
                cout<<"unsuccessful Selling "<<endl;
            cout<<"--------------------------"<<endl;
        }
        else if (choose==4) // option no. 4(print Items)
        {
            cout<<"Current Items"<<endl;
            s.Print_Items();
        }
        else if (choose==5) // option no. 5(Find an Item by Id)
        {
            int i;
            cout<<"please Enter ID ";
            cin>>i;
            Item *found=s.Find_an_Item_by_ID(i);
            cout<<"----------------------------------------------------"<<endl;
            if(found==NULL)
                cout<<"this ID not founded"<<endl;
            else
                cout<<*(found)<<endl;
            cout<<"----------------------------------------------------"<<endl;
        }
        else if(choose==6) // option no. 6(Exit)
        {
            cout<<"The program is closed"<<endl;
            return 0;
        }
        else
            cout<<"not found this choose"<<endl;
    }
}
