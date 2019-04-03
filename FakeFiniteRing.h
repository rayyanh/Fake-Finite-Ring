/**
 * @author Rayyan Hussain
 *
 * This is the .h file for FakeFiniteRing. It contains method and variable definitions that will be used throughout the
 * FFR class.
 */

#ifndef ASSIGNMENT1_FAKEFINITERING_H
#define ASSIGNMENT1_FAKEFINITERING_H

#include <iostream> //for overloading ostream, instream, etc.
#include <fstream>

using namespace std;

class FakeFiniteRing { //CPP defined class in .h file
public:
    int value;  //general required value declaration
    int order;

    /**
     * constructor
     * @param val
     * @param ord
     */
    inline FakeFiniteRing(int val, int ord); //had to use inline or was getting errors (believe it was link errors.)
    /**
     * Accessor for order
     * @return order
     */
    int getOrder();

    /**
     * Accessor for value
     * @return  value
     */
    int getValue();

    //Overloading +, which allows to add objects
    FakeFiniteRing operator+(FakeFiniteRing rightSide);

    //overloading - to minus ffr objs
    FakeFiniteRing operator-(FakeFiniteRing rightSide);

    //overloading * to multiply ffr objs
    FakeFiniteRing operator*(FakeFiniteRing rightSide);

    //overloading == to check equality of objs (value congruency)
    bool operator==(FakeFiniteRing obj);

    //overloading != to check not equals
    bool operator!=(FakeFiniteRing obj);

    //overloading += , implementation for doing so to objs
    FakeFiniteRing operator+=(FakeFiniteRing &obj);

    //overloading -= implementation for doing so to objs
    FakeFiniteRing operator-=(FakeFiniteRing obj);

    //overloading *= implementation for doing so to objs
    FakeFiniteRing operator*=(FakeFiniteRing obj);

    /**
     * Overlaoding >>
     *
     * Used friend keyword to allow for referencing to locked values
     */
    friend istream &operator>>(istream &input, FakeFiniteRing &obj);

    /**
     * Overlaoding <<
     *
     * Used friend keyword to allow for referencing to locked values
     */
    friend ostream &operator<<(ostream &output, FakeFiniteRing obj);
};


#endif //ASSIGNMENT1_FAKEFINITERING_H
