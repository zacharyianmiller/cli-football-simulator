#pragma once

#include <fstream>
#include <string>
#include <sys/stat.h>

class FileValidator
{
public:

    FileValidator() = default;

    inline static const bool isValid(const std::string& path)
    {
        return fileExists(path) && fileOpenable(path) ? true : false;
    }

private:

    inline static const bool fileOpenable(const std::string& path)
    {
        return std::ifstream(path).good();
    }

    inline static const bool fileExists(const std::string& path)
    {
        struct stat buffer;
        return (stat (path.c_str(), &buffer) == 0);
    }
};