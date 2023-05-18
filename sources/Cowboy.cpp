#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

// Cowboy::Cowboy(Point location, int hitTarget, std::string name, int ballsCount)
// : Character(location, hitTarget, name), _ballsCount(ballsCount) {}
Cowboy::Cowboy(const std::string &name, const Point &location)
    : Character(name, location, 110), _ballsCount(6) {}

void Cowboy::shoot(Character *enemy)
{
    if (this == enemy)
        throw runtime_error("Can't shoot himself");
    if (!isAlive())
        throw runtime_error("Attacker is dead");
    if (!enemy->isAlive())
        throw runtime_error("Enemy is already dead");
    
    // if (isAlive() && hasboolets())
    if (hasboolets())
    {
        enemy->hit(10);
        _ballsCount--;
    }
}

bool Cowboy::hasboolets() const
{
    return getBallsCount();
}

void Cowboy::reload()
{
    if (!isAlive())
    throw runtime_error("Dead cowboy can not reload");
    _ballsCount = 6;
}

std::string Cowboy::print()
{
    return "C " + Character::print();
}

std::ostream &operator<<(std::ostream &os, const Cowboy &cowboy)
{
    return os;
}


