#include "Team.hpp"

using namespace ariel;

    Team::Team(Character* leader) : _leader(leader) {}

    void Team::add(Character* player){}
    void Team::attack(Team* enemies){}
    int Team::stillAlive()
    {
        return 0;
    }
    std::string Team::print() const
    {
        return "Team";
    }
