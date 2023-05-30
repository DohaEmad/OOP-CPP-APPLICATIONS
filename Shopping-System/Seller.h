//
// Created by 20115 on 5/30/2023.
//

#ifndef UNTITLED9_SELLER_H
#define UNTITLED9_SELLER_H
#include "Item.h"
class Seller
{
private:
    // private attributes
    string Name,email;
    int maxItems;
    Item *items;
    static int counter;

public:
//// Seller's Member Functions prototypes////
    Seller(string n,string e,int m);
    // Operator Overloading to Display Seller's info.
    friend ostream& operator<<(ostream& os,const Seller &obj)
    {
        os<<"Name : "<<obj.Name<<endl<<"E-mail : "<<obj.email<<endl<<"maxItems : "<<obj.maxItems<<endl;
    }
    // First function Add An Item
    bool AddAnItem( Item ob);
    // Second function Sell An Item
    bool Sell_An_Item(string name ,double q );
    // Third function Print Items
    void Print_Items();
    // fourth function Find an Item by ID
    Item* Find_an_Item_by_ID(int id);
    // Destructor
    ~Seller();
};

#endif //UNTITLED9_SELLER_H
