#include <iostream>
#include "Facility.h"
#include "gcdistance.h"
#include <stdio.h>
#include <math.h>

using namespace std;

Facility::Facility(string s) : site_number_(s.substr(0, 10)), type_(s.substr(11, 12)),
code_(s.substr(24, 3)), name_(s.substr(130, 49)),
latitude_(convert_latitude(s.substr(535, 11))), longitude_(convert_longitude(s.substr(562, 11)))
{}

string Facility::site_number() const
{
	return site_number_;
}

string Facility::type() const
{
	return type_;
}

string Facility::code() const
{
	return code_;
}

string Facility::name() const
{
	return name_;
}

double Facility::latitude() const
{
	return latitude_;
}

double Facility::longitude() const
{
	return longitude_;
}

double Facility::distance(double lat, double lon) const
{
	return gcdistance(latitude_, longitude_, lat, lon);
}

double Facility::convert_latitude(string s) const
{
	
	string direction = s.substr(s.size() - 1);
	string tempStr = s.substr(0, s.size()-1);
	double temp = stod(tempStr);
	if (direction == "S")
	{
		temp *= -1;
	}
	temp /= 3600;
	return temp;
}
double Facility::convert_longitude(string s) const
{
	string direction = s.substr(s.size() - 1);
	string tempStr = s.substr(0, s.size() - 1);
	double temp = stod(tempStr);
	if (direction == "W")
	{
		temp *= -1;
	}
	temp /= 3600;
	return temp;
}

