# CMakeList.txt : CMake project for cli-football-simulator, include source and define
# Project specific logic here:
# ...

cmake_minimum_required (VERSION 3.20)

project(cli-football-simulator)

# Add source to this project's executable.
add_executable(src 
    "main.cpp" 
    "io-tools/ProgressBar.cpp"
    "roster/DefaultTeam.cpp" 
    "roster/PlayerSpecs.cpp"
    "roster/LeagueResourceLoader.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET src PROPERTY CXX_STANDARD 20)
endif()

install(TARGETS src)