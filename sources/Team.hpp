#ifndef TEAM_HPP
#define TEAM_HPP

#include <vector>
#include <stdexcept>

#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"

namespace ariel
{
   class Team
   {
        protected:
            std::vector <Character*> _fighters;
            Character* _leader;
        public:
            Team(Character* leader);
            virtual ~Team();
            Character* getLeader() const { return _leader; }
             std::vector <Character*> getFighters() const { return _fighters; }
            // void setLeader

            virtual void add(Character* player);
            void attack(Team* enemies);
            int stillAlive();
            void print() const;

            Character* findClosestAliveFighter(const Team& enemyTeam, const Character* leader) const;
            void attackTheEnemy(Character* attacker, Character* enemy);
   };
}

#endif