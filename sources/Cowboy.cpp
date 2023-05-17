#include "Cowboy.hpp"

using namespace ariel;

// Cowboy::Cowboy(Point location, int hitTarget, std::string name, int ballsCount)
// : Character(location, hitTarget, name), _ballsCount(ballsCount) {}
Cowboy::Cowboy(const std::string &name, const Point &location)
    : Character(name, location, 110), _ballsCount(6) {}

void Cowboy::shoot(Character *enemy)
{
    if (isAlive() && hasboolets())
    {
        enemy->hit(10);
        // enemy->reduceHitPoint(10);
        // if (enemy->getHitPoint() >= 10)
        //     enemy->setHitPoint(enemy->getHitPoint() - 10);
        // else
        //     enemy->setHitPoint(0);
        _ballsCount--;
    }
}
bool Cowboy::hasboolets() const
{
    return getBallsCount();
}

void Cowboy::reload()
{
    _ballsCount += 6;
}

std::string Cowboy::print()
{
    return "C " + Character::print();
}

std::ostream &operator<<(std::ostream &os, const Cowboy &cowboy)
{
    return os;
}


