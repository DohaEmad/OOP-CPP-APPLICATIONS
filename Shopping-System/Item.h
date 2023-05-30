#ifndef UNTITLED9_ITEM_H
#define UNTITLED9_ITEM_H
#include <iostream>
using namespace std;
class Item
{
private:
    // Private attributes
    int ID;
    double quantity,price;
    string name;
public:
////Item's Member functions prototypes////
    Item();
    Item(string n, double q , double p);
    Item(const Item &I); //copy constructor
    // Setters and Getters
    void Setname(string n);
    void SetQuantity(double q);
    void SetPrice(double p);
    void SetId(int i);
    string Getname();
    double GetQuantity();
    double GetPrice();
    int GetID();
    // Find if an item and another are equal in name
    bool operator==(const Item &obj);
    // Operator Overloading To increase the item’s quantity
    Item operator+=(double q);
    // Operator Overloading to decrease the item’s quantity
    Item operator-=(double q);
    // Operator Overloading To Enter Item's Attributes
    friend istream& operator>>(istream &is ,Item &i)
    {
        cout<<"Item's Name: ";     is>>i.name;
        cout<<"Item's Quantity: "; is>>i.quantity;
        cout<<"Item's Price: ";    is>>i.price;
        return is;
    }
    // Operator Overloading To display Item's Data
    friend ostream& operator<<(ostream &os ,const Item &i)
    {
        os<<"Name:"<<i.name<<"     "<<"Quantity: "<<i.quantity<<"     "<<"price: "<<i.price<<"      "<<"ID: "<<i.ID;
        return os;
    }
    friend class Seller;
};


#endif //UNTITLED9_ITEM_H
