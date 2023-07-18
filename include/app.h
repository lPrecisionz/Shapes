#pragma once

#include "screen.h"
#include "square.h"
#include "randomGenerator.h"
namespace shapes{

class app{
private:
    static screen m_screen;

public:
    static void run();
};

} //namespace shapes