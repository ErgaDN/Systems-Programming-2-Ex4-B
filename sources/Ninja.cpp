#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(const Point &location, int hitTarget, const std::string &name, int speed)
    : Character(name, location, hitTarget), _speed(speed) {}

void Ninja::move(const Character *enemy)
{
    if (this == enemy)
        throw std::runtime_error("The Same Character");

    Point temp = Point::moveTowards(getLocation(), enemy->getLocation(), getSpeed());
    setLocation(temp);
}

void Ninja::slash(Character *enemy)
{
    if (this == enemy)
        throw runtime_error("Can't slash himself");
    if (!isAlive())
        throw runtime_error("Attacker is dead");
    if (!enemy->isAlive())
        throw runtime_error("Enemy is already dead");

    if (isAlive() && getLocation().distance(enemy->getLocation()) < 1)
    {
        enemy->hit(40);
    }
}

std::string Ninja::print()
{
    return "[N] " + Character::print();
}