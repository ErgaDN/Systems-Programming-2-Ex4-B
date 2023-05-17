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
        // Cowboy(Point location, int hitTarget, std::string name, int ballsCount);
        Cowboy(const std::string& name, const Point& location);
        // ~Cowboy() = default;
        int getBallsCount() const { return _ballsCount; }

        void shoot(Character* enemy);
        bool hasboolets() const;
        void reload();
        std::string print();

        // void attack();
        

        friend std::ostream& operator<<(std::ostream& os, const Cowboy& cowboy);

    };

}
#endif