#include "Point.hpp"

using namespace std;
using namespace ariel;
    
    Point::Point(double x, double y) : _x(x), _y(y) {}

    double Point::distance(const Point& other) const
    {
        double dx = getX() - other.getX();
        double dy = getY() - other.getY();
        return sqrt(dx * dx + dy * dy);
    }

    string Point::print() 
    {
        return "(" + to_string(getX()) + ", " + to_string(getY()) + ")";        
    }

    Point Point::moveTowards(const Point& source, const Point& dest, const double dis)
    {
        return Point(1,1);
    }

