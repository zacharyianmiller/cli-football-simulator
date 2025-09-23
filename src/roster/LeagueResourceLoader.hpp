#pragma once

#include <thread>
#include <algorithm>
#include <cctype>
#include <fstream>

#include "../roster/DefaultTeam.hpp"
#include "../io-tools/ProgressBar.hpp"

#include "nlohmann/json.hpp"

class LeagueResourceLoader
{
public:

    using json = nlohmann::json;

    LeagueResourceLoader() {}
    ~LeagueResourceLoader() = default;

    static void loadTeamFromJSON(std::vector<DefaultTeam> teamRefArr);

private:

    static std::string toLowercase(std::string str);

};