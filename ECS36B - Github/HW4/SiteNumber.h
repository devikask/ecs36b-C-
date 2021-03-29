#ifndef SITENUMBER_H
#define SITENUMBER_H
#include <string>
#include <iostream>
#include "Runway.h"
using namespace std;

template <typename T>
class SiteNumber {
    SiteNumber(string sn) : site_number(sn) {}
    bool operator() (Runway* r1)
    {
        return r1->site_number() == site_number;
    }

};

#endif