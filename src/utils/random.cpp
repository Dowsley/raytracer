#include "random.h"

#include <random>

double Random::RandomDouble()
{
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;

    return distribution(generator);
}

double Random::RandomDouble(double min, double max)
{
    // Returns a random real in [min,max).
    return min + (max-min) * RandomDouble();
}