#include "Team.hpp"

using namespace std;
using namespace ariel;

Team::Team(Character *leader) : _leader(leader)
{
    if (!(leader->isAlive()))
    {
        throw runtime_error( leader->getName() + " is dead.");
    }
    if (leader->getInTeam())
    {
        throw runtime_error( leader->getName() + " is already in team.");
    }

    _fighters.push_back(leader);
    leader->setInTeam(true);
}

void Team::add(Character *player)
{
    if (!player->isAlive())
        throw runtime_error("Player is dead.");
    if (_fighters.size() == 10)
        throw runtime_error("Team is full.");
    _fighters.push_back(player);
    player->setInTeam(true);
}

void Team::attack(Team *enemyTeam)
{
    if (enemyTeam == nullptr)
    {
        throw invalid_argument("Enemy nullptr");
    }
    if (enemyTeam->stillAlive() == 0 || this->stillAlive() == 0)
    {
        throw runtime_error("Team members die.");
    }
    
    if (!enemyTeam->getLeader()->isAlive())
    {
        
        // chose new leader
        _leader = findClosestAliveFighter(*this, getLeader());
    }
     
    Character *closeEnemy = nullptr;
    // while (enemyTeam->stillAlive() > 0)
    // {
        ////// CONTINUE FROM HERE ///////////
        closeEnemy = findClosestAliveFighter(*enemyTeam, getLeader());
        cout << "closeEnemy: " << closeEnemy->getName() << endl;
        for (Character *attacker : _fighters)
        {
            attackTheEnemy(attacker, closeEnemy);
        }
    // }
}

void Team::attackTheEnemy(Character *attacker, Character *enemy)
{
    if (!attacker->isAlive())
        return;
    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(enemy))
    {
        if (cowboy->hasboolets())
            cowboy->shoot(enemy);
        else
            cowboy->reload();
    }
    else if (Ninja *ninja = dynamic_cast<Ninja *>(enemy))
    {
        if (ninja->distance(enemy) < 1)
            ninja->slash(enemy);
        else
            ninja->move(enemy);
    }
}

Character *Team::findClosestAliveFighter(const Team &enemyTeam, const Character *leader) const
{
    // Point leaderLoc = getLeader()->getLocation();
    Character *closestCharacter = nullptr;
    double minDistance = numeric_limits<double>::max();
    for (Character *fighter : _fighters)
    {
        if (fighter->isAlive())
        {
            if (fighter->distance(leader) < minDistance)
            {
                minDistance = fighter->distance(getLeader());
                closestCharacter = fighter;
            }
        }
    }
    return closestCharacter;
}

int Team::stillAlive()
{
    int isAlive = 0;
    for (Character *fighter : _fighters)
    {
        if (fighter->isAlive())
            ++isAlive;
    }
    return isAlive;
}

void Team::print() const
{
    cout << "Team members:" << endl;
    for (Character *fighter : _fighters)
    {
        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter))
            cout << cowboy->print() << endl;
        else if (Ninja *ninja = dynamic_cast<Ninja *>(fighter))
            cout << ninja->print() << endl;
            
    }
}
