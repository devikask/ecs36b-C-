#include "Domain.h"
#include <iostream>
using namespace std;

Domain::Domain()
{
    sizex = 600;
    sizey = 500;
}

Domain::~Domain() {}

void Domain::draw()
{
    cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>" << endl;
    cout << "<svg width=\"700\" height=\"600\"" << endl;
    cout << "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    cout << "<g transform=\"matrix(1,0,0,-1,50,550)\"" << endl;
    cout << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << endl;
    cout << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"" << sizex <<"\" height=\"" << sizey <<"\"/>" << endl;
    Rectangle p(Point(0,0),sizex, sizey);
    for (auto& it : s) {
        if (it->fits_in(p) == true)
        {
            it->draw();
            cout << "ok" << endl;
        }
        else
        {
            cout << "does not fit" << endl;
            continue;
        }
    cout << "</g>"<< endl;
    cout << "</svg>"<< endl;
    }
}

void Domain::addShape(const Shape *p)
{
    s.push_back(p);
}
