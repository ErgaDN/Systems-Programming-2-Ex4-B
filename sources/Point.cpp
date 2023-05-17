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
    // cout << "disPoints = " << disPoints << endl; 
    if (disPoints <= dis)
    {
        // cout << "-----\n";
        return dest;
    }
    else
    {
        // cout << "+++++\n";
        // Point res;
        double ratio = (disPoints <=0 ) ? 0 : dis / disPoints;
        double dx = dest.getX() - source.getX();
        double dy = dest.getY() - source.getY();
        // res.setX(source.getX() + ratio * dx);
        // res.setY(source.getY() + ratio * dy);
        // return res;
        return Point(source.getX() + ratio * dx, source.getY() + ratio * dy);
    }
    //  if (dist_src < 0)
    // {
    //     throw std::invalid_argument("Distance cannot be negative number");
    // }
    // if(src.distance(dst) < dist_src){
    //     return Point(dst.getX() , dst.getY());
    // }
    // double dist = src.distance(dst);
    // double ratio = (dist <= 0) ? 0 : dist_src / dist;

    // double new_x = src.getX() + (dst.getX() - src.getX()) * ratio;
    // double new_y = src.getY() + (dst.getY() - src.getY()) * ratio;

    // return Point(new_x, new_y);
}
