//
// Created by 20115 on 5/30/2023.
//
#include "ColoredBox.h"
#include<windows.h>
#include "iostream"
using namespace std;
void SetColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int ColoredBox::mx = 0;

void ColoredBox::display() {
    SetColor(getColor());
    cout << endl;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < width; j++)
            cout << a[i][j];
        cout << endl;
    }
    SetColor(15);
}

void ColoredBox::displayTransposed() {
    SetColor(getColor());
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < len; j++)
            cout << a[j][i];
        cout << endl;
    }
    SetColor(15);
}

void ColoredBox::displayChess(int c) {
    bool next_colour = true;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < width; j++) {
            if (next_colour) {
                SetColor(getColor());
                next_colour = false;
                cout << a[i][j];
            } else {
                SetColor(c);
                next_colour = true;
                cout << a[i][j];
            }
        }
        cout << endl;
    }
    SetColor(15);
}

void ColoredBox::displayWider() {
    SetColor(getColor());
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < width; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    SetColor(15);
}

int ColoredBox::getColor() {
    return col;
}

void ColoredBox::setColor(int c) {
    col = c;
}

ColoredBox::ColoredBox(int l, int w, int c, char chr) {
    len = l;
    width = w;
    col = c;
    boxblot = chr;
    //stores a box of characters,Dynamic 2D array
    a = new char*[l];
    for (int i = 0; i < l; i++)
        a[i] = new char[w];
    for (int i = 0; i<l; i++)
    {
        for (int j = 0; j<w; j++)
            a[i][j] = chr;
    }
    // max area
    mx = max(mx, len *width);
}

int ColoredBox::getArea() {
    return len*width;
}

int ColoredBox::getMaxArea() {
    return mx;
}

ColoredBox::~ColoredBox() {
    for (int i = 0; i <len; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}
