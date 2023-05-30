//
// Created by 20115 on 5/30/2023.
//
#include "Item.h"
////// Item's Member Functions bodies//////
Item::Item() //Default constructor
{
    quantity=0;
    price=0;
    name="";
    ID=0;
}
Item::Item(string n, double q , double p) //Parameterized constructor
{
    name=n;
    quantity=q;
    price=p;

}
Item::Item(const Item &I) //Copy constructor
{
    name=I.name;
    quantity=I.quantity;
    price=I.price;

}
void Item:: Setname(string n)
{
    name=n;
}
void Item::SetQuantity(double q)
{
    quantity=q;
}
void Item::SetPrice(double p)
{
    price=p;
}
void Item::SetId(int i)
{
    ID=i;
}
string Item::Getname()
{
    return name;
}
double Item::GetQuantity()
{
    return quantity;
}
double Item::GetPrice()
{
    return price;
}
int Item::GetID()
{
    return ID;
}
bool Item::operator==(const Item &obj)
{
    if(name==obj.name )
        return true;
    else
        return false;
}
Item Item::operator+=(double q)
{
    quantity+=q;
    return  *this;
}
Item Item::operator-=(double q)
{
    quantity-=q;
    return  *this;

}