#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <iostream>
namespace ariel
{
    class Point
    {
    private:
        double _x;
        double _y;
    public:
        // Point();
        Point(double x, double y);
        // ~Point() = default;

        double getX() const { return _x; }
        double getY() const { return _y; }
        void setX(const double num) { _x = num; }
        void setY(const double num) { _y = num; }

        double distance(const Point& other) const;
        string print();
        Point moveTowards(const Point& source, const Point& dest, const double dis);
    };

}

#endif
// Point::Point(/* args */)
// {
// }

// Point::~Point()
// {
// }
