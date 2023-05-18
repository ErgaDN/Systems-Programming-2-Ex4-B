#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>

namespace ariel
{

    class Character
    {
    private:
        const std::string _name;
        Point _location;
        int _hitPoint;
        bool _inTeam;

    public:
        /* Constructors */
        Character(const std::string &name, const Point &location, int hitPoint);
        Character(const Character &other);

        virtual ~Character() = default;

        Character &operator=(const Character &) = delete;
        Character(Character &&) = delete;
        Character &operator=(Character &&) = delete;

        /* Getter & Setter */
        std::string getName() const { return _name; }
        int getHitPoint() const { return _hitPoint; }
        Point getLocation() const { return _location; }
        bool getInTeam() const { return _inTeam; }
        void setInTeam() { _inTeam = true; }
        void setHitPoint(const int num) { _hitPoint = num; }
        void setLocation(const Point &location) { _location = location; }

        bool isAlive() const;
        double distance(const Character *other) const;
        void hit(int num);
        virtual std::string print();
    };
}

#endif
