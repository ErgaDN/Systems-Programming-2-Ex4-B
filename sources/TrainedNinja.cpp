#include "TrainedNinja.hpp"

using namespace ariel;

    // TrainedNinja::TrainedNinja(Point location, int hitTarget, std::string name, int speed)
    // : Ninja(location, 120, name, 12) {}

    TrainedNinja::TrainedNinja(const std::string& name, const Point& location)
        : Ninja(location, 120, name, 12) {}


