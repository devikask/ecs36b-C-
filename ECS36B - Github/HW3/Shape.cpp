#include "Shape.h"
#include<iostream>
using namespace std;

/*--------------------Rectangle Class--------------------*/


bool Rectangle::overlaps (const Shape& s) const
{
    return s.overlaps(*this);
}

bool Rectangle::overlaps (const Circle& r) const
{
    Rectangle temp(position, width, height);
    if (r.overlaps(temp) == true)
    {
        return true;
    }
    cout << "overlap" << endl;
    return false;
}

Rectangle::~Rectangle(void) {}


bool Rectangle::overlaps (const Rectangle& r) const
{
    //Top left corner of old Rectangle
    int x1 = position.x;
    int y1 = position.y + height;
    
    //Bottom right corner of old Rectangle
    int x2 = x1 + width;
    int y2 = y1;
    
    //Top Left Corner of new Rectangle
    int x3 = r.position.x;
    int y3 = r.position.y + height;
    
    //Bottom right corner of new Rectangle
    int x4 = x3 + r.width;
    int y4 = y3;
    
    
    if ((x1 >= x4) || (x2 <= x3) || (y1 <= y4) || (y2 >= y3))
    {
        cout << "overlap" << endl;
        return false;
    }
    return true;
    
    
}

bool Rectangle::fits_in(const Rectangle &r) const
{
    int insideBottomLeftX = position.x;
    int insideBottomLeftY = position.y;
    int insideTopRightX = position.x + width;
    int insideTopRightY = position.y + height;
    
    int outsideBottomLeftX = r.position.x;
    int outsideBottomLeftY = r.position.y;
    int outsideTopRightX = r.position.x + r.width;
    int outsideTopRightY = r.position.y + r.height;
    
    if (insideBottomLeftX < outsideBottomLeftX)
    {
        return false;
    }
    if (insideBottomLeftY < outsideBottomLeftY)
    {
        return false;
    }
    if (insideTopRightX > outsideTopRightX)
    {
        return false;
    }
    if (insideTopRightY > outsideTopRightY)
    {
        return false;
    }
    cout << "ok" << endl;
    return true;
}

void Rectangle::draw() const
{
    cout << "<rect x=\"" << position.x << "\" y=\"" << position.y << "\" width=\"" << width << "\" height=\"" << height << "\"/>" << endl;
}

/*--------------------Circle Class--------------------*/

Circle::~Circle(void) {}

bool Circle::overlaps (const Shape& s) const
{
    return s.overlaps(*this);
}

bool Circle::overlaps (const Circle& r) const
{
    int xc = center.x;
    int yc = center.y;
    int xr = r.center.x;
    int yr = r.center.y;
    
    int centerDistance = ((xc-xr)*(xc-xr)) + ((yc-yr)*(yc-yr));
    int radSquare = (radius + r.radius) * (radius + r.radius);
    
    if (centerDistance < radSquare)
    {
        return true;
    }
    cout << "overlap" << endl;
    return false;
    
}

bool Circle::overlaps (const Rectangle& r) const
{
    int xc = center.x;
    int yc = center.y;
    int xr = r.position.x;
    int yr = r.position.y;
    int r2 = radius * radius;
    int xn = 0, yn = 0;
    
    xn = min(max(xc,xr), xr + r.width);
    yn = min(max(yc,yr), yr + r.height);
    Point temp(xn, yn);
    int d2 = temp.norm2();
    
    if (d2 < r2)
    {
        return true;
    }
    cout << "overlap" << endl;
    return false;
    
}

bool Circle::fits_in(const Rectangle& r) const
{
    int cx = center.x;
    int cy = center.y;
    
    int RectBottomLeftX = r.position.x;
    int RectBottomLeftY = r.position.y;
    int RectTopRightX = r.position.x + r.width;
    int RectTopRightY = r.position.y + r.height;
    
    if((cx+radius) > RectTopRightX)
    {
        return false;
    }
    if((cx-radius) < RectBottomLeftX)
    {
        return false;
    }
    if((cy + radius) > RectTopRightY)
    {
        return false;
    }
    if((cy - radius) < RectBottomLeftY)
    {
        return false;
    }
    cout << "ok" << endl;
    return true;
}

void Circle::draw() const
{
    cout << "<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << radius << "\"" <<"/>" <<endl;
}



/*
 class Circle : public Shape
 {
   public:
   Circle(void): center(Point(0,0)), radius(0) {}
   Circle(Point c, int r) : center(c),radius(r) {}
   virtual ~Circle(void);
   virtual bool overlaps(const Shape& s) const;
   virtual bool overlaps(const Circle& r) const;
   virtual bool overlaps(const Rectangle& r) const;
   virtual bool fits_in(const Rectangle& r) const;
   virtual void draw(void) const;

   Point center;
   int radius;
 };
 #endif

 */
