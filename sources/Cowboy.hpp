#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int _ballsCount;

    public:
        /* Constructor */
        Cowboy(const std::string &name, const Point &location);

        int getBallsCount() const { return _ballsCount; }

        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
        std::string print() override;
    };
}
#endif