#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
        public:
            // OldNinja(Point location, int hitTarget, std::string name, int speed);
            OldNinja(const std::string& name, const Point& location);
            // ~OldNinja() = default;
    };    
}

#endif