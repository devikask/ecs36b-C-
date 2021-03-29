//
//  main.cpp
//  Angle
//
//  Created by Devika Kumar on 1/17/21.
//  Copyright © 2021 devikakumar. All rights reserved.
//

#include <iostream>
#include "Angle.h"
using namespace std;

void Angle::set(int t)
{
    theta = t;
}

Angle::Angle()
{
    theta = 30;
}

int Angle::get()
{
    return theta;
}

void Angle::change (int dt)
{
    int new_theta = get();
    new_theta += dt;
    if (new_theta < -60)
    {
        new_theta = -60;
    }
    if (new_theta > 120)
    {
        new_theta = 120;
    }
    set(new_theta);
}

void Angle::print()
{
    cout << "angle: " << get() << endl;
}
