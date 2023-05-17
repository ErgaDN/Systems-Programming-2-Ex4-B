#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    protected:
        int _speed;
    
    public:
        Ninja(const Point& location, int hitTarget, const std::string& name, int speed);
        // ~Ninja() = default;
        int getSpeed() const { return _speed; }
        
        void move(const Character* enemy);
        void slash(Character* enemy);
        std::string print();
        // void attack();
    };    
}

#endif 