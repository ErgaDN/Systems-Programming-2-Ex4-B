#include "YoungNinja.hpp"

using namespace ariel;
    // YoungNinja::YoungNinja(Point location, int hitTarget, std::string name, int speed)
    // : Ninja(location, 100, name, 14) {}

    YoungNinja::YoungNinja(const std::string& name, const Point& location)
        :Ninja(location, 100, name, 14) {}
