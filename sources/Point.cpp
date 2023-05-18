#include "Point.hpp"

using namespace std;
using namespace ariel;

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

Point Point::moveTowards(const Point &source, const Point &dest, double dis)
{
    if (dis < 0)
        throw invalid_argument("Negative distance");
    double disPoints = source.distance(dest);
    if (disPoints <= dis)
    {
        return dest;
    }
    else
    {
        double ratio = (disPoints <= 0) ? 0 : dis / disPoints;
        double dx = dest.getX() - source.getX();
        double dy = dest.getY() - source.getY();
        return Point(source.getX() + ratio * dx, source.getY() + ratio * dy);
    }
}
