#include "SmartTeam.hpp"

using namespace std;
using namespace ariel;

SmartTeam::SmartTeam(Character *leader) : Team(leader), _attacked(false) {}

void SmartTeam::add(Character *player)
{
    if (player == nullptr)
        throw invalid_argument("Character is nullptr");
    if (!player->isAlive())
        throw runtime_error("Character is dead.");
    if (sizeOfFighters() == 10)
        throw runtime_error("Team is full.");
    if (player->getInTeam())
        throw runtime_error("Character already in game.");

    pushFighterBack(player);
    player->setInTeam();
}

void SmartTeam::attack(Team *enemyTeam)
{
    if (enemyTeam == nullptr)
        throw invalid_argument("Enemy is nullptr");
    if (enemyTeam->stillAlive() == 0 || this->stillAlive() == 0)
        throw runtime_error("Team members die.");

    Character *closeEnemy = nullptr;

    for (Character *attacker : getFighters())
    {
        if (!attacker->isAlive())
            continue;
        if (enemyTeam->stillAlive() == 0)
            break;
        
        closeEnemy = findClosestAliveFighter(*enemyTeam, attacker);

        attackTheEnemy(attacker, closeEnemy);
    }
}

