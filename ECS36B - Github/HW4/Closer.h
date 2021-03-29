#ifndef CLOSER_H
#define CLOSER_H
#include <string>
#include <iostream>
#include "Facility.h"
using namespace std;

class Closer {
public:
    Closer(double latitude, double longitude) : lat(latitude), lon(longitude){}
    bool operator() (Facility* fac1, Facility* fac2)
    {
        return fac1->distance(lat, lon) < fac2->distance(lat, lon); 
    }

private:
    double lat;
    double lon;
};

#endif