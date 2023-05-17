#include "Ninja.hpp"
// #include "Point.hpp"

using namespace ariel;

Ninja::Ninja(const Point &location, int hitTarget, const std::string &name, int speed)
    : Character(name, location, hitTarget), _speed(speed) {}

void Ninja::move(const Character *enemy) 
{
    Point temp = Point::moveTowards(getLocation(), enemy->getLocation(), getSpeed());
    setLocation(temp);
}

void Ninja::slash(Character *enemy) 
{
    if (isAlive() && getLocation().distance(enemy->getLocation()) < 1)
    {
        enemy->hit(40);
        // enemy->reduceHitPoint(40);
    }
}

std::string Ninja::print()
{
    return "N " + Character::print();
}

// void Ninja::attack()
// {

// }
