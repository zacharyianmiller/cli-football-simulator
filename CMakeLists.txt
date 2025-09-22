# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.20)

project ("cli-football-simulator")

# Include sub-projects.
add_subdirectory ("src")

# External libs
add_subdirectory("ext/nlohmann-json")

target_link_libraries(src 
    PRIVATE 
        nlohmann_json::nlohmann_json
)