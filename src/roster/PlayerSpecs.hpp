#pragma once

#include <string>
#include <variant>
#include <cassert>

class PlayerSpecs
{
public:

    enum OffensivePositions { QB, FB, RB, WR, TE, T, G, C };
    enum DefensivePositions { DE, DT, LB, CB, SS, FS };

    using Position = std::variant<OffensivePositions, DefensivePositions>;

    /// @brief Parameterized constructor for general player type
    /// @param pName Player's first and last name (separated by a space)
    /// @param pPosition Offensive player's position type
    /// @param pJerseyNumber Player's number displayed on their jersey 
    PlayerSpecs(const std::string& pName, const Position pPosition, const int pJerseyNumber) :
    mName(pName),
    mPosition(pPosition),
    mJerseyNumber(pJerseyNumber)
    {}

    bool isOffensive() const { return std::holds_alternative<OffensivePositions>(mPosition); }
    bool isDefensive() const { return std::holds_alternative<OffensivePositions>(mPosition); }
    
    const std::string& getPlayerName() const { return mName; }
    const int getPlayerPositionIdx() const; // relative to enum
    const std::string getPlayerPositionStr() const;
    const int getPlayerJerseyNumber() const { return mJerseyNumber; }

    ~PlayerSpecs() = default;

private:

    std::string mName;
    Position mPosition;
    int mJerseyNumber;
};