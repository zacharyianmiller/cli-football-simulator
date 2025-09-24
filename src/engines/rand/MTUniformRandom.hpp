#pragma once

#include <random>
#include <ctime>

template <typename FloatType>
class MTUniformRandom
{
public:

    MTUniformRandom(const FloatType begin, const FloatType end) :
    generator(std::make_unique<std::mt19937>(std::time(nullptr))),
    dist(std::make_unique<std::uniform_real_distribution<FloatType>>(begin, end)) 
    {
    }

    FloatType operator ()() { return (*dist)(*generator); }

private:

    std::unique_ptr<std::mt19937> generator;
    std::unique_ptr<std::uniform_real_distribution<FloatType>> dist;

};