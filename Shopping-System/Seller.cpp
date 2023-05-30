//
// Created by 20115 on 5/30/2023.
//

#include "Seller.h"
int Seller:: counter=0; // Initialize Static Variable
Seller::Seller(string n,string e,int m)
{
    Name=n;
    email=e;
    maxItems=m;
    items=new Item[maxItems];
}
// First function Add An Item
bool Seller::AddAnItem( Item ob)
{
    for(int i=0;i<counter;i++) //check if item exist
    {
        if (ob == items[i]) {
            items[i] += ob.quantity;
            return true;
        }
    }
    if (counter < maxItems)  //add item
    {
        items[counter] = ob;
        items[counter].SetId(++counter); //Set ID for Item
        return true;
    }
    else
        return false; //There is no capacity to Add
}

// Second function Sell An Item
bool Seller::Sell_An_Item(string name ,double q )
{

    for (int i = 0; i <counter; ++i) //item exist and Quantity required is available
    {
        if (name == items[i].Getname() && q <= items[i].GetQuantity())
        {
            items[i] -= q;
            if(items[i].GetQuantity()==0)
            {
                for (int j = i ;j <counter-1 ; ++j) {
                    items[i]=items[i+1];
                }
                counter--;
            }
            return true;
        }
    }
    for (int i = 0; i <counter; ++i) //item exist but Quantity required is not available
    {
        if (name == items[i].Getname() && q>items[i].GetQuantity())
        {
            cout<<"There is only "<< items[i].GetQuantity() <<" left for this item"<<endl;
            return false;
        }
    }
    //item not exist
    cout<<"item not exist"<<endl;
    return false;
}
// Third function Print Items body
void Seller::Print_Items()
{
    if(counter==0) cout<<"NO items "<<endl;
    else
    {
        cout<<"-------------------------------------------------------"<<endl;
        for (int i = 0; i <counter ; ++i)
        {
            cout<<items[i]<<endl;
        }
        cout<<"-------------------------------------------------------"<<endl;
    }

}
// fourth function Find an Item by ID body
Item* Seller::Find_an_Item_by_ID(int id)
{
    for (int i = 0; i <counter ; ++i) {
        if(id==items[i].GetID())
            return &(items[i]);
    }
    return NULL;
}
Seller::~Seller()
{
    delete []items;
}