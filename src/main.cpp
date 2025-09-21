#include <iostream>

#include "roster/DefaultTeam.hpp"
#include "roster/PlayerSpecs.hpp"

#define print(x) std::cout << x << std::endl

int main(int argc, char* argv[])
{
    DefaultTeam mBuffaloBills { "Buffalo", "Bills" };
    PlayerSpecs specs { "Josh Allen", PlayerSpecs::OffensivePositions::QB, 17 };

    print("Name: " << specs.getPlayerName());
    print("Position: " << specs.getPlayerPositionStr());
    print("Jersey number: " << specs.getPlayerJerseyNumber());

    mBuffaloBills.loadIntoPosition(specs);
}