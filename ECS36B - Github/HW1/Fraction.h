//
//  Fraction.h
//  Fraction
//
//  Created by Devika Kumar on 1/20/21.
//  Copyright © 2021 devikakumar. All rights reserved.
//

#ifndef Fraction_h
#define Fraction_h
#include <iostream>
using namespace std;

class Fraction
{
  private:
    int num, den;
    
  public:
    Fraction();
    Fraction(int a, int b);
    int find_gcd(int a, int b);
    int getNum() const;
    int getDen() const;
    void setNum(int a);
    void setDen(int b);
    void reduceFraction(int num, int den);
    void sign(int num, int den);
    const Fraction operator+(Fraction& ft);
    const Fraction operator-(Fraction& ft);
    Fraction& operator=(const Fraction& ft);
    friend istream& operator>>(istream& input, Fraction& ft);
    friend ostream& operator<<(ostream& output, const Fraction& ft);
};

#endif /* Fraction_h */
