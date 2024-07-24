#ifndef COMPUTERFOUR_H
#define COMPUTERFOUR_H

#include "Player.h"
#include "Board.h"
#include "Computer.h"
#include "Move.h"

class ComputerFour : public Computer {
public:
    int evaluation;
    Move* bestMove;

    int eval();
    Move* algorithm();
    int mini(int depth);
    int maxi(int depth);
};

#endif
