#pragma once

#include <thread>
#include <algorithm>
#include <cctype>
#include "nlohmann/json.hpp"

#include "../roster/DefaultTeam.hpp"
#include "../io-tools/ProgressBar.hpp"
#include "../io-tools/FileValidator.h"

class LeagueResourceLoader
{
public:

    using json = nlohmann::json;

    LeagueResourceLoader() {}
    ~LeagueResourceLoader() = default;

    static void loadTeamFromJSON(DefaultTeam& team);

private:

    static std::string toLowercase(std::string str);

};