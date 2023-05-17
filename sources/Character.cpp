#include "Character.hpp"

using namespace std;
using namespace ariel;

// Character::Character(int hitTarget) : _hitTarget(hitTarget){}

Character::Character(const Point &location, int hitPoint, const std::string &name)
    : _location(location), _hitPoint(hitPoint), _name(name), _inTeam(false)
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
        return getName() + " " + to_string(getHitPoint()) + " " + getLocation().print() + "\n";
    }
    else
    {
        return "(" + getName() + ") " + getLocation().print();
    }
}
