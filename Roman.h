//
// Created by Brian Walter on 10/30/2017.
//

#ifndef HOMEWORK5_ROMAN_H
#define HOMEWORK5_ROMAN_H

#include <iostream>
using namespace std;

//Function Prototypes
void testConstructor();
void testOperatorPlus();
void testOperatorPlusEqual();
void testOperatorIncrement();

//Class Definition
class Roman
{
private:
    unsigned int value;  //The roman numeral itself isn't stored.  Instead, we just store the integer that corresponds to it.
    string convertToRoman() const; //Takes an integer and turns it into a string of roman numerals
    void convertFromRoman(const string&); //Takes a string of roman numerals and converts it into an integer
public:
    Roman();  //The default constructor that allows us to make empty objects.
    Roman(int v);
    Roman(const string &str);  //The constructor which accepts a string and  converts it internally to an integer.  It actually just forwards it onto convertFromRoman()

    Roman operator+(const Roman&) const;  //The left and right operands are Roman objects
    Roman operator+(const int) const; //The left operand is a Roman object, the right is an int number.
    friend Roman operator+(const int, const Roman&); //The left operand is an int, the right is a Roman object.
    void operator +=(const Roman&);  //The left and right operands are Roman objects, but the left operand can change.
    void operator +=(const int);  //The left operand is a Roman object, the right is an int number.  The left operand can change.
    Roman operator++();  //The prefix ++ operator

    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Roman&);  //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members.
};


#endif //HOMEWORK5_ROMAN_H
