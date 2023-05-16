#include "Ninja.hpp"

using namespace ariel;

Ninja::Ninja(const Point &location, int hitTarget, const std::string &name, int speed)
    : Character(location, hitTarget, name), _speed(speed) {}

void Ninja::move(const Character *enemy) 
{
    double dis = this->distance(enemy);
    if (dis <= _speed)
    {
        _location.setX(enemy->getLocation().getX());
        _location.setY(enemy->getLocation().getY());
    }
}

void Ninja::slash(Character *enemy) {}

std::string Ninja::print()
{
    return "N\n" + Character::print();
}
