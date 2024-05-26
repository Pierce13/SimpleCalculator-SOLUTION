#include <iostream>
#include <iomanip>
#include <sstream>
#include "SimpleCalculator.h"
using namespace std;

//Calculator 1: Area of a circle
double calculateCircleArea() {
    //TODO: create a variable of type double named "r"
    //      create a constant double variable named pi and set it equal to 3.1415926535
    double r;
    const double pi = 3.1415926535;

    //TODO: prompt the user to enter the radius, r
    cout << "Enter the radius: \n";
    cin >> r;
    //TODO: calculate the area. PI * R^2
    double area = pi*pow(r,2);
    //TODO: display the area. Use setprecision() to set the output to 10 digits
    //      Be sure to use fixed to ensure the same number of digits following the
    //      decimal point
    cout << setprecision(10) << fixed << area << endl;

    return area;
}

//Calculator 2: Fraction addition
string addFractions() {
    //TODO: create variables for each numerator, denominator, and slash (to represent /)
    int num1;
    int denom1;
    int num2;
    int denom2;
    char slash;
    cout << "First fraction (a/b): ";

    //TODO: prompt the user to enter the first fraction
    cin >> num1 >> slash >> denom1;
    cout << "Second fraction (c/d): ";

    //TODO: prompt the user to enter the second fraction
    cin >> num2 >> slash >> denom2;

    //TODO: add the fractions by using the formula defined in the pdf
    int finalNum = (num1 * denom2) + (denom1 * num2);
    int finalDenom = denom1*denom2;
    
    //TODO: display the the solution. Remember to include the slash!
    cout << finalNum << '/' << finalDenom << endl;

    return to_string(finalNum) + "/" + to_string(finalDenom);
}

//Calculator 3: Quadratic formula
string solveQuadraticFormula() {
    //TODO: Set variables for a, b, and c
    int a;
    int b;
    int c;

    cout << "Enter coefficient 1: ";
    cin >> a;
    cout << "Enter coefficient 2: ";
    cin >> b;
    cout << "Enter coefficient 3: ";
    cin >> c;

    //TODO: Calculate the quadratic formula. Remember to
    //      include both the positive and negative values. Make the variables doubles
    double PositiveSolution = ((-1*b) + sqrt(pow(b,2) - (4*a*c))) / (2*a);
    double negativeSolution = ((-1*b) - sqrt(pow(b,2) - (4*a*c))) / (2*a);

    //TODO: display the results
    cout << setprecision(2) << fixed << "x-intercept 1: " << PositiveSolution << endl;
    cout << setprecision(2) << fixed << "x-intercept 2: " << negativeSolution << endl;

    return to_string(PositiveSolution) + ", " + to_string(negativeSolution);
}

#ifndef TESTING
int main() {
    calculateCircleArea();
    addFractions();
    solveQuadraticFormula();
    return 0;
}
#endif
