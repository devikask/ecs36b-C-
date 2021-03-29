#include <iostream>
#include "Runway.h"
#include <stdio.h>

using namespace std;

Runway::Runway(string s) : site_number_(s.substr(0, 10)), name_(s.substr(13,7)), length_(convert_length(s.substr(20,5)))
{}

string Runway::site_number() const
{
	return site_number_;
}

string Runway::name() const
{
	return name_;
}

int Runway::length() const
{
	return length_;
}

int Runway::convert_length(string s) const
{
	return stoi(s);
}


