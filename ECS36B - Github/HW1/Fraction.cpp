
//
//  Created by Devika Kumar on 1/20/21.
//  Copyright © 2021 devikakumar. All rights reserved.
//

#include <iostream>
#include "Fraction.h"
using namespace std;

//Default Constructor
Fraction::Fraction()
{
    num = 0;
    den = 1;
}

//Constructor for when some values for the variables are inserted.
Fraction::Fraction(int a, int b)
{
    if (b == 0)
    {
        throw invalid_argument("Error: zero denominator");
    }
    else
    {
        setNum(a);
        setDen(b);
    }
}

//Finding the greatest common denominator
int Fraction::find_gcd(int a, int b)
{
    int gcd, remainder;
    remainder = a % b;
    while (remainder != 0)
    {
        a = b;
        b = remainder;
        remainder = a % b;
    }
    gcd = b;
    return gcd;
}

//return the numerator
int Fraction::getNum() const
{
    return num;
}

//return the denominator
int Fraction::getDen() const
{
    return den;
}

//setting the numerator
void Fraction::setNum(int a)
{
    num = a;
}

//setting the denominator
void Fraction::setDen(int b)
{
    den = b;
}

// setting the reduced fraction
void Fraction::reduceFraction(int num, int den)
{

    int gcd;
    gcd  = find_gcd(num, den);
    num /= gcd;
    den /= gcd;
}

//negative signs
void Fraction::sign(int num, int den)
{
    if (num < 0 && den < 0)
    {
        num = -num;
        den = -den;
    }
    else if (num > 0 && den < 0) {
        num = -num;
        den = -den;
    }
}

//Operator overloading

//add
const Fraction Fraction::operator+(Fraction& f)
{
    int gcd = find_gcd(getDen(), f.getDen());
    int num1 = (getNum()*(gcd/getDen())) + (f.getNum()*(gcd/f.getNum()));
    reduceFraction(num1, gcd);
    Fraction newFract(num1, gcd);
    return newFract;
}

//subt
const Fraction Fraction::operator-(Fraction& f)
{
    int gcd = find_gcd(getDen(), f.getDen());
    int num1 = (getNum()*(gcd/getDen())) - (f.getNum()*(gcd/f.getNum()));
    reduceFraction(num1, gcd);
    Fraction newFract(num1, gcd);
    return newFract;
}

//equal
Fraction& Fraction::operator=(const Fraction& f)
{
    setNum(f.getNum());
    setDen(f.getDen());
    return *this;
}

//input
istream& operator>>(istream& input, Fraction& f)
{
    int n = 0;
    int d = 1;
    int w = 0;
    input >> n;
    if (input.peek() == '+')
    {
        w = n;
        input.ignore() >> n;
        input >> d;
    }
    else if (input.peek() == '/')
    {
        input.ignore() >> d;
    }
    else if (input.peek() == ' ')
    {
        input.ignore();
        d = 1;
    }
    n = (w * d) + n;
    f = Fraction(n, d);
    f.reduceFraction(n,d);
    return input;
}
    
//output
ostream& operator<<(ostream& output, const Fraction& f)
{
    output << f.getNum() << "/" << f.getDen();
    return output;
}
