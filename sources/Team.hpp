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
        std::vector<Character *> _fighters;
        Character *_leader;

    public:
        /* constructor & distructor */
        Team(Character *leader);
        virtual ~Team();
        Team(const Team &) = delete;
        Team &operator=(const Team &) = delete;
        Team(Team &&) = delete;
        Team &operator=(Team &&) = delete;

        Character *getLeader() const { return _leader; }
        void setLeader(Character* leader) { _leader = leader; }
        std::vector<Character *> getFighters() const { return _fighters; }
        unsigned int sizeOfFighters() const { return _fighters.size(); }
        void pushFighterBack(Character *fighter) { _fighters.push_back(fighter); }
        void pushFighterBegin(Character *fighter) { _fighters.insert(_fighters.begin(), fighter); }

        virtual void add(Character *player);
        virtual void attack(Team *enemies);
        int stillAlive();
        void print() const;

        Character *findClosestAliveFighter(const Team &enemyTeam, const Character *leader) const;
        void attackTheEnemy(Character *attacker, Character *enemy);
    };
}

#endif