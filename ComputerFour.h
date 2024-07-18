#ifndef COMPUTERFOUR_H
#define COMPUTERFOUR_H

#include "Player.h"
#include "Board.h"
#include "Computer.h"
#include "Move.h"

class ComputerFour : public Computer {
public:
    int eval();
    Move algorithm() = 0;
};

#endif