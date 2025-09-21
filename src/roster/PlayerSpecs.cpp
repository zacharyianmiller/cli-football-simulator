#include "PlayerSpecs.hpp"

const int PlayerSpecs::getPlayerPositionIdx() const 
{ 
    if (isOffensive())
        return (int)std::get<PlayerSpecs::OffensivePositions>(mPosition);
    
    if (isDefensive())
        return (int)std::get<PlayerSpecs::DefensivePositions>(mPosition);

    assert(false);
}

const std::string PlayerSpecs::getPlayerPositionStr() const
{
    int pos = -1;
    if (isOffensive())
    {
        switch ((int)std::get<PlayerSpecs::OffensivePositions>(mPosition))
        {
            case 0: return "QB";
            case 1: return "FB";
            case 2: return "RB";
            case 3: return "WR";
            case 4: return "TE";
            case 5: return "T";
            case 6: return "G";
            case 7: return "C";
            default: assert(false);
        }
    }

    if (isDefensive())
    {
        switch ((int)std::get<PlayerSpecs::DefensivePositions>(mPosition))
        {
            case 0: return "DE";
            case 1: return "DT";
            case 2: return "LB";
            case 3: return "CB";
            case 4: return "SS";
            case 5: return "FS";
            default: assert(false);
        }
    }

    assert(false);
}
