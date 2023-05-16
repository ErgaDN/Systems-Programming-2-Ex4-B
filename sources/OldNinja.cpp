#include "OldNinja.hpp"
using namespace ariel;
    // OldNinja::OldNinja(Point location, int hitTarget, std::string name, int speed)
    //     : Ninja(location, 150, name, 8) {}

    OldNinja::OldNinja(const std::string& name, const Point& location)
        :Ninja(location, 150, name, 8) {}
