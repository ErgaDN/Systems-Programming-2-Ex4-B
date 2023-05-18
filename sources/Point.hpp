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
        /* Constructors */
        Point(double xxx, double yyy);

        /* Setter & Getter */
        double getX() const { return _x; }
        double getY() const { return _y; }
        void setX(const double num) { _x = num; }
        void setY(const double num) { _y = num; }

        double distance(const Point &other) const;
        std::string print();
        static Point moveTowards(const Point &source, const Point &dest, double dis);
    };
}

#endif