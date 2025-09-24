#pragma once

#include <random>
#include <ctime>

template <typename FloatType>
class MTUniformRandom
{
public:

    MTUniformRandom(const FloatType begin, const FloatType end) :
    dist(std::make_unique<std::uniform_real_distribution<FloatType>>(begin, end)),
    generator(std::time(nullptr))
    {
    }

    FloatType operator ()() { return (*dist)(generator); }

private:

    std::mt19937 generator;
    std::unique_ptr<std::uniform_real_distribution<FloatType>> dist;
    
};