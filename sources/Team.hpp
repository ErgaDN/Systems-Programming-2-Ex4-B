#ifndef TEAN_HPP
#define TEAN_HPP

#include <vector>

#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"

namespace ariel
{
   class Team
   {
        private:
            std::vector <Character*> _fighters;
            Character* _leader;
        public:
            Team(Character* leader);
            // ~Team() = default;

            void add(Character* player);
            void attack(Team* enemies);
            int stillAlive();
            std::string print() const;
   };
}

#endif