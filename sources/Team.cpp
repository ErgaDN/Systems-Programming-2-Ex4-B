#include "Team.hpp"

using namespace std;
using namespace ariel;

Team::Team(Character *leader) : _leader(leader)
{
    if (!(leader->isAlive()))
        throw runtime_error(leader->getName() + " is dead.");
    if (leader->getInTeam())
        throw runtime_error(leader->getName() + " is already in team.");

    pushFighterBack(leader);
    leader->setInTeam();
}

Team::~Team()
{
    for (Character *fighter : _fighters)
        delete fighter;
}

void Team::add(Character *player)
{
    if (player == nullptr)
        throw invalid_argument("Character is nullptr");
    if (!player->isAlive())
        throw runtime_error("Character is dead.");
    if (_fighters.size() == 10)
        throw runtime_error("Team is full.");
    if (player->getInTeam())
        throw runtime_error("Character already in game.");

    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(player))
        pushFighterBegin(player);
    else
        pushFighterBack(player);

    player->setInTeam();
}

void Team::attack(Team *enemyTeam)
{
    if (enemyTeam == nullptr)
        throw invalid_argument("Enemy is nullptr");
    if (enemyTeam->stillAlive() == 0 || this->stillAlive() == 0)
        throw runtime_error("Team members die.");

    /* chose new leader for the team */
    if (!getLeader()->isAlive())
        setLeader(findClosestAliveFighter(*this, getLeader()));

    Character *closeEnemy = findClosestAliveFighter(*enemyTeam, getLeader());

    for (Character *attacker : getFighters())
    {
        if (!attacker->isAlive())
            continue;
        if (enemyTeam->stillAlive() == 0)
            break;
        if (!closeEnemy->isAlive())
            closeEnemy = findClosestAliveFighter(*enemyTeam, getLeader());

        attackTheEnemy(attacker, closeEnemy);
    }
}

void Team::attackTheEnemy(Character *attacker, Character *enemy)
{
    if (!attacker->isAlive() || !enemy->isAlive())
        return;
    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(attacker))
    {
        if (cowboy->hasboolets())
            cowboy->shoot(enemy);
        else
            cowboy->reload();
    }
    else if (Ninja *ninja = dynamic_cast<Ninja *>(attacker))
    {
        if (ninja->distance(enemy) < 1)
            ninja->slash(enemy);
        else
            ninja->move(enemy);
    }
}

Character *Team::findClosestAliveFighter(const Team &team, const Character *leader) const
{
    Character *closestCharacter = nullptr;
    double minDistance = numeric_limits<double>::max();

    for (Character *teamMember : team.getFighters())
    {
        if (teamMember->isAlive())
        {
            if (teamMember->distance(leader) < minDistance)
            {
                minDistance = teamMember->distance(leader);
                closestCharacter = teamMember;
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
    cout << endl;
}
