#pragma once

#include <string>
#include <vector>
#include <cassert>

#include "PlayerSpecs.hpp"
#include "../io-tools/FileValidator.h"

#include "nlohmann/json.hpp"

class DefaultTeam
{
public:

    enum class UnitTypes 
    { 
        Offense = 0, 
        Defense, 
    };

    /// @brief Parameterized constructor for general team
    /// @param pTeamPrefix The leading team title - usually the city/state association (e.g., New York for the Jets, Los Angeles for the Rams)
    /// @param pTeamSuffix The official team name (e.g., Bills, Patriots, Colts, etc.)
    DefaultTeam(std::string_view pTeamPrefix, std::string_view pTeamSuffix) :
    mRoster(std::make_unique<Roster>()),
    mTeamPrefix(pTeamPrefix),
    mTeamSuffix(pTeamSuffix)
    {}

    ~DefaultTeam() = default;

    void loadIntoPosition(const PlayerSpecs specs);

    auto getTeamName() { return mTeamSuffix; }

private:

    class Roster
    {
    public:
        
        using PositionArray = std::vector<PlayerSpecs>;

        enum class OffensePositions { QB, FB, RB, WR, TE, T, G, C, SizeHelper };
        enum class DefensePositions { DE, DT, LB, CB, SS, FS, SizeHelper };

        Roster() {}
        ~Roster() = default;

        std::array<PositionArray, (int)OffensePositions::SizeHelper>& getOffenseRef() { return mOffense; }
        std::array<PositionArray, (int)DefensePositions::SizeHelper>& getDefenseRef() { return mDefense; }

    private:

        std::array<PositionArray, (int)OffensePositions::SizeHelper> mOffense;
        std::array<PositionArray, (int)DefensePositions::SizeHelper> mDefense;

    };

    std::unique_ptr<Roster> mRoster;
    std::string_view mTeamPrefix;
    std::string_view mTeamSuffix;
};