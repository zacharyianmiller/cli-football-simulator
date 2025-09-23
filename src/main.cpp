#include <fstream>
#include <thread>
#include <sstream>
#include <vector>

#include "roster/DefaultTeam.hpp"
#include "roster/PlayerSpecs.hpp"
#include "roster/LeagueResourceLoader.hpp"

#define LEAGUE_SIZE 16

int main(int argc, char* argv[])
{
    using json = nlohmann::json;

    std::vector<DefaultTeam> mLeagueArr;
    mLeagueArr.reserve(LEAGUE_SIZE);

    /* AFC East */
    DefaultTeam mBuffaloBills       { "Buffalo",       "Bills"    };
    DefaultTeam mMiamiDolphins      { "Miami",         "Dolphins" };
    DefaultTeam mNewYorkJets        { "New York",      "Jets"     };
    DefaultTeam mNewEnglandPatriots { "New England",   "Patriots" };

    mLeagueArr.push_back(mBuffaloBills);
    mLeagueArr.push_back(mMiamiDolphins);
    mLeagueArr.push_back(mNewYorkJets);
    mLeagueArr.push_back(mNewEnglandPatriots);

    // /* AFC North */
    DefaultTeam mCincinnatiBengals  { "Cincinnati",    "Bengals"  };
    DefaultTeam mClevelandBrowns    { "Cleveland",     "Browns"   };
    DefaultTeam mBaltimoreRavens    { "Baltimore",     "Ravens"   };
    DefaultTeam mPittsburghSteelers { "Pittsburgh",    "Steelers" };

    mLeagueArr.push_back(mCincinnatiBengals);
    mLeagueArr.push_back(mClevelandBrowns);
    mLeagueArr.push_back(mBaltimoreRavens);
    mLeagueArr.push_back(mPittsburghSteelers);

    /* AFC South */
    DefaultTeam mIndianapolisColts   { "Indianapolis", "Colts"    };
    DefaultTeam mJacksonvilleJaguars { "Jacksonville", "Jaguars"  };
    DefaultTeam mHoustonTexans       { "Houston",      "Texans"   };
    DefaultTeam mTennesseeTitans     { "Tennessee",    "Titans"   };

    mLeagueArr.push_back(mIndianapolisColts);
    mLeagueArr.push_back(mJacksonvilleJaguars);
    mLeagueArr.push_back(mHoustonTexans);
    mLeagueArr.push_back(mTennesseeTitans);

    /* AFC West */
    DefaultTeam mDenverBroncos      { "Denver",        "Broncos"  };
    DefaultTeam mLosAngelesChargers { "Los Angeles",   "Chargers" };
    DefaultTeam mKansasCityChiefs   { "Kansas City",   "Chiefs"   };
    DefaultTeam mLasVegasRaiders    { "Las Vegas",     "Raiders"  };
    
    mLeagueArr.push_back(mDenverBroncos);
    mLeagueArr.push_back(mLosAngelesChargers);
    mLeagueArr.push_back(mKansasCityChiefs);
    mLeagueArr.push_back(mLasVegasRaiders);

    LeagueResourceLoader::loadTeamFromJSON(mLeagueArr);

    return 0;
}