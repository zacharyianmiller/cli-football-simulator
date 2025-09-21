#include <iostream>
#include <fstream>

#include "roster/DefaultTeam.hpp"
#include "roster/PlayerSpecs.hpp"
#include "io-tools/ProgressBar.hpp"

#include <thread>
#include <sstream>

#define print(x) std::cout << x << std::endl

int main(int argc, char* argv[])
{
    using json = nlohmann::json;

    DefaultTeam mBuffaloBills { "Buffalo", "Bills" };

    // PlayerSpecs specs { "Josh Allen", PlayerSpecs::OffensivePositions::QB, 17 };
    // print("Name: " << specs.getPlayerName());
    // print("Position: " << specs.getPlayerPositionStr());
    // print("Jersey number: " << specs.getPlayerJerseyNumber());

    // const auto path = "../res/bills.json";
    // bool status = FileValidator::isValid(path);

    // std::ifstream bills_file(path);
    // json bills = json::parse(bills_file);

    const int N = 250;
    for (size_t n = 1; n < N + 1; ++n)
    {
        ProgressBar::update(n, N);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}