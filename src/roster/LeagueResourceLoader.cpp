#include "LeagueResourceLoader.hpp"

void LeagueResourceLoader::loadTeamFromJSON(DefaultTeam& teamRef)
{
    auto teamstr = std::string(teamRef.getTeamName());
    std::string path = "../../res/" + toLowercase(teamstr) + ".json";

    /// FIXME: Issue at runtime where resources are not being found
    /// which cause parsing errors.
    // if (!FileValidator::isValid(path))
    //     return;

    // std::ifstream file(path);
    // json team = json::parse(file);

    const int N = 500;
    for (size_t n = 0; n < N; ++n)
    {
        ProgressBar::update(n + 1, N);

        /* Do something with teamRef... */

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
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
