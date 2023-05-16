#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>

namespace ariel
{

    class Character
    {
    protected:
        Point _location;
        int _hitPoint;
        std::string _name;

    public:
        // Character(int hitTarget);
        Character(const Point& location, int hitPoint, const std::string& name);
        Character(const Character& other);
        // virtual ~Character() = default;
        ~Character() = default;

        std::string getName() const { return _name; }
        int getHitPoint() const { return _hitPoint; }
        Point getLocation() const { return _location; }
        void setHitPoint(const int num) { _hitPoint = num; }

        bool isAlive() const;
        double distance(const Character* other) const;
        void hit(const int num);
        virtual std::string print();
    };

}

#endif
