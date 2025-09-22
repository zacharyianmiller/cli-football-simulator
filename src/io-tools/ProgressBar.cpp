#include "ProgressBar.hpp"

void ProgressBar::update(const int currentIdx, 
                         const int length,
                         const int maxNumChars)
{
    assert(currentIdx > 0);

    const float ratio = static_cast<float>(currentIdx) / static_cast<float>(length);
    const auto percent = ratio * 100.f;
    const int numBars = ratio * maxNumChars;

    if (currentIdx == 1)
        print("Loading team and player assets...");

    std::stringstream out;
    for (size_t prog = 0; prog < numBars; ++prog) { out << LOAD_CHAR; }
    for (size_t prog = numBars; prog < maxNumChars; ++prog) { out << EMPTY_CHAR; }

    /* Ensure final iteration outputs loaded animation */
    if (currentIdx != length)
    {
        std::cout << out.str() << " " << std::floor(percent) << "%" << " (" << currentIdx << "/" << length << ")\r" << std::flush;
    }
    else
    {
        std::cout << out.str() << ANSI_GREEN_START << " " << std::floor(percent) << "%" << " (" << currentIdx << "/" << length << ")\r" << ANSI_GREEN_END << std::endl;
        print("Assets loaded successfully.");
    }
}

void ProgressBar::print(const std::string& instr, 
                        const bool shouldNewline)
{
    std::cout << instr << (shouldNewline ? NEW_LINE : NO_CHAR);
}