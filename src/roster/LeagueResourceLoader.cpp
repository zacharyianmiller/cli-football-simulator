#include "LeagueResourceLoader.hpp"

void LeagueResourceLoader::loadTeamFromJSON(std::vector<DefaultTeam> teamRefArr)
{
    auto numTeams = teamRefArr.size();
    for (int n = 0; n < numTeams; ++n)
    {
        ProgressBar::update(n + 1, (int)numTeams);

        auto teamstr = std::string(teamRefArr[n].getTeamName());
        std::filesystem::path path = std::string(BINARY_DIR) + "/" + toLowercase(teamstr) + ".json";
    
        /* Ensure file exists before loading */
        if (!std::filesystem::exists(path))
            break;

        /* Parse out JSON file */
        std::ifstream file(path, std::ios::binary);
        json team = json::parse(file);

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

std::string LeagueResourceLoader::toLowercase(std::string str)
{
    /// TODO: Benchmark these two to see if the excessive traversing 
    /// is really any better than iterating linearly over the string.

#if 0
    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { 
            return static_cast<char>(std::towlower(c)); 
        });

    return str;
#endif

    for (auto& c : str) { c = std::tolower(c); }
    return str;
}
