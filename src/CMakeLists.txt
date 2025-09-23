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

add_custom_command(
    TARGET src POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
            ${CMAKE_SOURCE_DIR}/res
            ${CMAKE_CURRENT_BINARY_DIR}/res
    COMMENT "Copying resource files to build directory"
)

target_compile_definitions(src PRIVATE BINARY_DIR="${CMAKE_CURRENT_BINARY_DIR}/res")

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET src PROPERTY CXX_STANDARD 20)
endif()

install(TARGETS src)