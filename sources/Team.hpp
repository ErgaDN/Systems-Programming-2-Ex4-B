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
    private:
        // protected:
            std::vector <Character*> _fighters;
            Character* _leader;
        public:
            Team(Character* leader);
            virtual ~Team();
            Team(const Team&) = delete;
            Team& operator=(const Team&) = delete;
            Team(Team&&) = delete;
            Team& operator=(Team&&) = delete;


            Character* getLeader() const { return _leader; }
             std::vector <Character*> getFighters() const { return _fighters; }
            unsigned int sizeOfFighters() const { return _fighters.size(); }
             void pushFighterBack(Character* fighter) { _fighters.push_back(fighter); }
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