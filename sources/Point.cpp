#include "Point.hpp"

using namespace std;
using namespace ariel;

Point::Point() : _x(0), _y(0) {}
Point::Point(double x, double y) : _x(x), _y(y) {}

double Point::distance(const Point &other) const
{
    double dx = getX() - other.getX();
    double dy = getY() - other.getY();
    return sqrt(dx * dx + dy * dy);
}

string Point::print()
{
    return "(" + to_string(getX()) + ", " + to_string(getY()) + ")";
}

Point Point::moveTowards(const Point &source, const Point &dest,  double dis)
{
    double disPoints = source.distance(dest);
    if (disPoints <= dis)
    {
        return dest;
    }
    else
    {
        Point res;
        double ratio = dis / disPoints;
        double dx = dest.getX() - source.getX();
        double dy = dest.getY() - source.getY();
        res.setX(source.getX() + ratio * dx);
        res.setY(source.getY() + ratio * dy);
        return res;
    }
}
