#include "Character.hpp"

using namespace std;
using namespace ariel;

// Character::Character(int hitTarget) : _hitTarget(hitTarget){}

Character::Character(const std::string& name, const Point& location, int hitPoint)
    :  _name(name), _location(location), _hitPoint(hitPoint), _inTeam(false)
{
}

Character::Character(const Character &other)
    : _location(other._location), _hitPoint(other._hitPoint), _name(other._name), _inTeam(false)
{
}

// void Character::reduceHitPoint(const int num)
// {
//     if (getHitPoint() <= num)
//         setHitPoint(0);
//     else
//         setHitPoint(getHitPoint() - num);
// }

bool Character::isAlive() const
{
    return _hitPoint > 0;
}

double Character::distance(const Character *other) const
{
    // cout << "This point: " << getLocation().print() << "\nOther Point: " << other->getLocation().print() << "\nDistance: " << getLocation().distance(other->getLocation()) << endl;
    return getLocation().distance(other->getLocation());
}

void Character::hit(const int num)
{
    if (num >= getHitPoint())
        setHitPoint(0);
    else
        setHitPoint(getHitPoint() - num);
}

std::string Character::print()
{
    if (isAlive())
    {
        return "Name: " + getName() + " HitPoint: " + to_string(getHitPoint()) + " Location:" + getLocation().print();
    }
    else
    {
        return "(Name: " + getName() + ") Location:" + getLocation().print();
    }
}
