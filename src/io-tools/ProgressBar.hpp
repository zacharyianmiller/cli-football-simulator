#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>

class ProgressBar
{
public:

    ProgressBar() {}
    ~ProgressBar() = default;

    static void update(const int current, const int length, const int maxNumChars = 30);

private:

    static void print(const std::string& instr, const bool shouldNewline = true); // helper

    static constexpr std::string_view LOAD_CHAR = "\u25AC";
    static constexpr std::string_view NO_CHAR = "";
    static constexpr std::string_view EMPTY_CHAR = " ";
    static constexpr std::string_view NEW_LINE = "\n";
    static constexpr std::string_view ANSI_GREEN_START = "\033[32m";
    static constexpr std::string_view ANSI_GREEN_END = "\033[0m";

};