#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include <vector>
#include <stdexcept>
#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
    private:
        bool _attacked;
    public:
        /* constructor */
        SmartTeam(Character *leader);
        void add(Character *player) override;
        void attack(Team *enemyTeam) override;
    };

}
#endif