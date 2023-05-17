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
    protected:
        Point _location;
        int _hitPoint;
        bool _inTeam;

    public:
        // Character(int hitTarget);
        Character(const Point& location, int hitPoint, const std::string& name);
        Character(const Character& other);
        // virtual ~Character() = default;
        ~Character() = default;

        std::string getName() const { return _name; }
        int getHitPoint() const { return _hitPoint; }
        Point getLocation() const { return _location; }
        bool getInTeam() const { return _inTeam; }
        void setInTeam(bool temp) { _inTeam = temp; }
        void setHitPoint(const int num) { _hitPoint = num; }
        void setLocation(const Point& p) { _location = p; }
        // void reduceHitPoint(const int num);

        bool isAlive() const;
        double distance(const Character* other) const;
        void hit(const int num);
        virtual std::string print();
        // virtual void attack() {}
    };

}

#endif
