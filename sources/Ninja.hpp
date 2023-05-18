#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    private:
        const int _speed;

    public:
        /* Constructors */
        Ninja(const Point &location, int hitTarget, const std::string &name, int speed);

        int getSpeed() const { return _speed; }

        void move(const Character *enemy);
        void slash(Character *enemy);
        std::string print() override;
    };
}

#endif