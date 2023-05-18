#include "Team2.hpp"

using namespace std;
using namespace ariel;

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::add(Character *player)
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