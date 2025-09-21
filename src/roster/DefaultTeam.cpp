#include "DefaultTeam.hpp"

void DefaultTeam::loadIntoPosition(const PlayerSpecs specs)
{
    if (specs.isOffensive())
    {
        mRoster->getOffenseRef()[specs.getPlayerPositionIdx()].push_back(specs);
        return;
    }

    if (specs.isDefensive()) 
    {
        mRoster->getDefenseRef()[specs.getPlayerPositionIdx()].push_back(specs);
        return;
    }

    assert(false);
}