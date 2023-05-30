//
// Created by 20115 on 5/30/2023.
//

#ifndef UNTITLED9_COLOREDBOX_H
#define UNTITLED9_COLOREDBOX_H
class ColoredBox
{
private:
    int len, width, col;
    static int mx;
    char boxblot;
    char** a;
public:
    //constructor
    ColoredBox(int l, int w, int c = 15, char chr = '#');
    //function set another color
    void setColor(int c);
    int getColor();
    void display();
    void displayTransposed();
    void displayWider();
    void displayChess(int c);
    int getArea();
    static int getMaxArea();
    //destructor that frees dynamic memory
    ~ColoredBox();

};


#endif //UNTITLED9_COLOREDBOX_H
