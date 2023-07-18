#pragma once

#include <random>

namespace shapes{

class randomGenerator{
private:
    std::mt19937 m_rng;

public:
    randomGenerator();
    double getRandomValue(double min, double max);
};

} //namespace shapes