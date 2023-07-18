#include "../include/randomGenerator.h"

namespace shapes{

randomGenerator::randomGenerator(){
    std::random_device rd;
    m_rng = std::mt19937(rd());
}


double randomGenerator::getRandomValue(double min, double max){
    std::uniform_real_distribution<double>dist(min, max);
    return dist(m_rng);
}   

};