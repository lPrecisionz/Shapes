#pragma once

#include "screen.h"
#include "square.h"

namespace shapes{

class app{
private:
    static screen m_screen;

public:
    static void run();
};

} //namespace shapes