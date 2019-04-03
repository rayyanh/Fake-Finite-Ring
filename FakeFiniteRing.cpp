/**
 * @author Rayyan Hussain
 * @version 1
 *
 * This class implements a finite ring, which can be visually interpreted as a cyclical array. The class uses a
 * constructor which creates an algorithm. The algorithm uses a formula to mimic a finite ring.
 *
 * This class also overloads operators in order to achieve its tasks. We overload basic operators such as addition,
 * multiplication, etc. It also impliments <<, >>, +=, -=, and so on so that we may work with addition, subtraction,
 * etc. of these objects.
 */

#include "FakeFiniteRing.h"
#include <iostream>

using namespace std;

/**
 * Constructor for FFR. Takes in values and implements algorithms. Also checks to make sure the ffr fits into certain
 * parameters set by requirements.
 * @param val
 * @param ord
 */
FakeFiniteRing::FakeFiniteRing(int val, int ord) {
    if (ord < 3) {
        throw invalid_argument("Bad Order");
    }
    if (val <= (ord - 1) && val >= 0) {
        value = val % ord;
        order = ord;
    } else {
        value = val; //Setting values for value variable and order variable
        order = ord;
        while (value < 0) {
            //value += order;
            (value % order) % order; //EXTRA code i want to keep for testing
        }
        while (value >= order) {
            value -= order;
        }
    }

}

/**
 * Accessor for the variable order
 * @return order
 */
int FakeFiniteRing::getOrder() {
    return order;
}

/**
 * Accessor for the variable for value
 * @return value
 */
int FakeFiniteRing::getValue() {
    return value;
}

/**
 * This is the overload for the plus operator. It takes two values and essentially adds those values.
 * Once added, it returns a new FFR with the edited value.
 *
 * It also checks for false order values
 * @param rightSide
 * @return FFR that is modified with edited values
 */
FakeFiniteRing FakeFiniteRing::operator+(FakeFiniteRing rightSide) {
    FakeFiniteRing leftSide = *this;
    if (leftSide.getOrder() != rightSide.getOrder()) { //checking for order errors.
        throw invalid_argument("Bad Order");
    } else {
        return FakeFiniteRing((leftSide.getValue() + rightSide.getValue() % getOrder()), getOrder());
    }
}

/**
 * This is the overload for the minus operator. It takes two values and essentially subtracts those values.
 * Once subtracted, it returns a new FFR with the edited value.
 *
 * It also checks for false order values
 * @param rightSide
 * @return FFR that is modified with edited values
 */
FakeFiniteRing FakeFiniteRing::operator-(FakeFiniteRing rightSide) {
    FakeFiniteRing leftSide = *this;
    if (leftSide.getOrder() != rightSide.getOrder()) {//checking for order errors.
        throw invalid_argument("Bad Order");
    } else {
        return FakeFiniteRing((rightSide.getValue() - leftSide.getValue() % getOrder()), getOrder());
    }
}

/**
 * This is the overload for the * operator. It takes two values and essentially multiplies those values.
 * Once multiplied, it returns a new FFR with the edited value.
 *
 * It also checks for false order values
 * @param rightSide
 * @return FFR that is modified with edited values
 */
FakeFiniteRing FakeFiniteRing::operator*(FakeFiniteRing rightSide) {
    FakeFiniteRing leftSide = *this;
    if (leftSide.getOrder() != rightSide.getOrder()) {//checking for order errors.
        throw invalid_argument("Bad Order");
    } else {
        return FakeFiniteRing((leftSide.getValue() * rightSide.getValue() % getOrder()), getOrder());
    }
}

/**
 * This method overloads the == operator in order to check whether two objects are equal.
 * @param obj
 * @return true or false
 */
bool FakeFiniteRing::operator==(FakeFiniteRing obj) {
    FakeFiniteRing obj2 = *this;
    if (obj2.getOrder() != obj.getOrder()) {//checking for order errors.
        throw invalid_argument("Bad Order");
    } else {
        return obj2.getValue() == obj.getValue();
    }
}

/**
 * This method overloads the != operator. It reuses code from previously in order to check if object is NOT equal
 * @param obj
 * @return true or false
 */
bool FakeFiniteRing::operator!=(FakeFiniteRing obj) {
    FakeFiniteRing obj2 = *this;
    if (obj2.getOrder() != obj.getOrder()) {//checking for order errors.
        throw invalid_argument("Bad Order");
    }
    return !operator==(obj);
}

/**
 * This method overloads the += operator. It is so two objects can be added in this way.
 * @param obj
 * @return this
 */
FakeFiniteRing FakeFiniteRing::operator+=(FakeFiniteRing &obj) {
    value = (value + obj.value) % order;
    return *this;
}

/**
 * This method overloads the -= operator. It is so two objects can be subtracted in this way.
 * @param obj
 * @return this
 */
FakeFiniteRing FakeFiniteRing::operator-=(FakeFiniteRing obj) {
    value = order - (value % order) % order;
    return *this;

}

/**
 * This method overloads the *= operator. It is so two objects can be multiplied in this way.
 * @param obj
 * @return this
 */
FakeFiniteRing FakeFiniteRing::operator*=(FakeFiniteRing obj) {
    FakeFiniteRing obj2 = *this;
    if (obj2.getOrder() != obj.getOrder()) { // do i need it for this?
        throw invalid_argument("Bad Order");//checking for order errors.
    }
    value = (value * obj.value) % order;
    return *this;
}

/**
 * This method overlaods the istream operator. It allows for us to add into an object. It is done so by modifying the
 * FFR object. This allows for user to input a var for value and order and for the console to print out a properly
 * formatted FFR.
 * @param input
 * @param obj
 * @return input
 */
istream &operator>>(istream &input, FakeFiniteRing &obj) {
    int a = 0, b = 0;
    a = obj.value;
    b = obj.order;
    input >> a >> b;
    obj = FakeFiniteRing(a, b);
    return input;
}

/**
 * This method overloads the ostream operators. It allows for printing out output in a customized way
 * @param output
 * @param obj
 * @return (value,order)
 */
ostream &operator<<(ostream &output, FakeFiniteRing obj) {
    return output << "(" << obj.getValue() << "," << obj.getOrder() << ")";
}






