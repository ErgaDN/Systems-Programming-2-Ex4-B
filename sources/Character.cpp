#include "Character.hpp"

using namespace std;
using namespace ariel;

    // Character::Character(int hitTarget) : _hitTarget(hitTarget){}

    Character::Character (const Point& location, int hitPoint, const std::string& name)
        : _location(location), _hitPoint(hitPoint), _name(name)
    {
    }

    Character::Character(const Character& other)
        : _location(other._location), _hitPoint(other._hitPoint), _name(other._name)
    {
    }

    
    bool Character::isAlive() const
    {
        return _hitPoint > 0;
    }

    double Character::distance(const Character* other) const
    {
        return getLocation().distance(other->getLocation());
    }

    void Character::hit(const int num) 
    {
        _hitPoint -= num;
    }

    std::string Character::print()  
    {
        if (isAlive())
        { 
            return "Name: " + getName() + "\n"
            + "Hit Points: " + to_string(getHitPoint()) + "\n"
            + "Location: " + getLocation().print() + "\n";
        }
        else 
        {
            return "(Name: " + getName() + ")\n"
            + "Location: " + getLocation().print() + "\n";
        }
    }
