#include "SmartTeam.hpp"

using namespace std;
using namespace ariel;

SmartTeam::SmartTeam(Character *leader) : Team(leader), _attacked(false) {}

void SmartTeam::attack(Team *enemyTeam)
{
    if (enemyTeam == nullptr)
        throw invalid_argument("Enemy is nullptr");
    if (enemyTeam->stillAlive() == 0 || this->stillAlive() == 0)
        throw runtime_error("Team members die.");

    /* chose new leader for the team */
    if (!getLeader()->isAlive())
        setLeader(Team::findClosestAliveFighter(*this, getLeader()));

    Character *enemyToAttack = nullptr;

    for (Character *attacker : getFighters())
    {
        if (!attacker->isAlive())
            continue;
        if (enemyTeam->stillAlive() == 0 || this->stillAlive() == 0)
            return;

        enemyToAttack = bestEnemyToAttack(attacker, enemyTeam);

        if (enemyToAttack == nullptr)
            continue;

        Team::attackTheEnemy(attacker, enemyToAttack);
    }
}

Character *SmartTeam::bestEnemyToAttack(Character *attacker, Team *enemyTeam)
{
    int priority = numeric_limits<int>::max();
    Character *bestEnemy = nullptr;

    for (Character *enemy : enemyTeam->getFighters())
    {
        if (!enemy->isAlive())
            continue;

        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(attacker))
        {
            if (enemy->getHitPoint() <= 10)
                return enemy;

            if (enemy->getHitPoint() / 10 < priority)
            {
                priority = enemy->getHitPoint() / 10;
                bestEnemy = enemy;
            }
        }
        else if (Ninja *ninja = dynamic_cast<Ninja *>(attacker))
        {
            double dis = attacker->distance(enemy);
            if (dis < 1 && enemy->getHitPoint() <= 40)
                return enemy;

            if (dis < priority)
            {
                priority = dis;
                bestEnemy = enemy;
            }
        }
    }
    return bestEnemy;
}
