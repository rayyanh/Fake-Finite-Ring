#include <iostream>
#include "FakeFiniteRing.h"

using namespace std;

int main() {


    FakeFiniteRing ffr3(5, 10);
    FakeFiniteRing ffr4(8, 10);
    FakeFiniteRing ffr5(15, 10);
    FakeFiniteRing ffr6(8, 15);

    try {
        FakeFiniteRing ffr7 = ffr3 + ffr6;
    }
    catch (...) {
        cout << "Caught bad addition" << endl;
    }
    try {
        FakeFiniteRing ffr7 = ffr3 - ffr6;
    }
    catch (...) {
        cout << "Caught bad subtraction" << endl;
    }
    try {
        FakeFiniteRing ffr7 = ffr3 * ffr6;
    }
    catch (...) {
        cout << "Caught bad multiplication" << endl;
    }
    try {
        if (ffr4 == ffr6);
    }
    catch (...) {
        cout << "Caught bad equivalence" << endl;
    }
    try {
        if (ffr4 != ffr6);
    }
    catch (...) {
        cout << "Caught bad non equivalence" << endl;
    }


    cout << "ffr3 = " << ffr3 << endl;
    cout << "ffr5 = " << ffr5 << endl;
    cout << "ffr3 + ffr4" << ffr3 + ffr4 << endl;
    cout << "ffr3 * ffr4" << ffr3 * ffr4 << endl;
    ffr3 += ffr4;
    cout << "ffr3 += ffr4" << ffr3 << endl;
    ffr3 *= ffr4;
    cout << "ffr3 *= ffr4" << ffr3 << endl;
    ffr3 -= ffr4;
    cout << "ffr3 -= ffr4" << ffr3 << endl;

    if (ffr3 == ffr5) {
        cout << "ffr3 == ffr5" << endl;
    }

    if (ffr3 != ffr4) {
        cout << "ffr3 != ffr4" << endl;
    }

    cout << "Value of ff4 is " << ffr4.getValue() << endl;
    cout << "Order of ff4 is " << ffr4.getOrder() << endl;


    cout << "type two ints for ffr3: ";
    cin >> ffr3;

    cout << "ffr3 = " << ffr3 << endl;

    return 0;


}

/**
 * Code Below for testing
 */

//    int value = 0;
//    int order = 0;
//    int ord = 3;
//    int val = -3;
//    if (ord < 3) {
//        cerr << "Error, Order val is less than 3";
//    }
//    if (val <= (ord - 1) && val >= 0) {
//        value = val % 10;
//        order = ord;
//    } else {
//        value = val; //Setting values for value variable and order variable
//        order = ord;
//        while (value < 0) {
//            value += order;
//        }
//        while (value >= order) {
//            value -= order;
//        }
//    }
//    int finiteArray[order];
//    for(int i = 0; i < order; i++){ //Population of the array
//        finiteArray[i] = i;
//    }
//    for(int i : finiteArray){ cout << finiteArray[i];}
//    cout << endl;
//    cout << finiteArray[value];
