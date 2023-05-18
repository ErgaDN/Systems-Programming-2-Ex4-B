#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <vector>
#include <stdexcept>
#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        /* constructor */
        Team2(Character *leader);
        void add(Character *player) override;
    };

}
#endif