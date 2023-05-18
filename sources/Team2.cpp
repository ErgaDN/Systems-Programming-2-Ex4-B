#include "Team2.hpp"

using namespace std;
using namespace ariel;

Team2::Team2(Character* leader) : Team(leader) {}

void Team2::add(Character* player)
{
    if (player == nullptr)
        throw invalid_argument("Character is nullptr");
    if (!player->isAlive())
        throw runtime_error("Player is dead.");
    if (getFighters().size() == 10)
        throw runtime_error("Team is full.");

    _fighters.push_back(player);
    player->setInTeam();

}