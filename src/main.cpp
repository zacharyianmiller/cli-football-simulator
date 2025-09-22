#include <fstream>
#include <thread>
#include <sstream>

#include "roster/DefaultTeam.hpp"
#include "roster/PlayerSpecs.hpp"
#include "roster/LeagueResourceLoader.hpp"

#define print(x) std::cout << x << std::endl

int main(int argc, char* argv[])
{
    using json = nlohmann::json;

    /* AFC East */
    DefaultTeam mBuffaloBills       { "Buffalo",       "Bills"    };
    DefaultTeam mMiamiDolphins      { "Miami",         "Dolphins" };
    DefaultTeam mNewYorkJets        { "New York",      "Jets"     };
    DefaultTeam mNewEnglandPatriots { "New England",   "Patriots" };

    /* AFC North */
    DefaultTeam mCincinnatiBengals  { "Cincinnati",    "Bengals"  };
    DefaultTeam mClevelandBrowns    { "Cleveland",     "Browns"   };
    DefaultTeam mBaltimoreRavens    { "Baltimore",     "Ravens"   };
    DefaultTeam mPittsburghSteelers { "Pittsburgh",    "Steelers" };

    /* AFC South */
    DefaultTeam mIndianapolisColts   { "Indianapolis", "Colts"    };
    DefaultTeam mJacksonvilleJaguars { "Jacksonville", "Jaguars"  };
    DefaultTeam mHoustonTexans       { "Houston",      "Texans"   };
    DefaultTeam mTennesseeTitans     { "Tennessee",    "Titans"   };

    /* AFC West */
    DefaultTeam mDenverBroncos      { "Denver",        "Broncos"  };
    DefaultTeam mLosAngelesChargers { "Los Angeles",   "Chargers" };
    DefaultTeam mKansasCityChiefs   { "Kansas City",   "Chiefs"   };
    DefaultTeam mLasVegasRaiders    { "Las Vegas",     "Raiders"  };
    
    LeagueResourceLoader::loadTeamFromJSON(mBuffaloBills);

    return 0;
}