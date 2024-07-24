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

    ComputerFour(Board* board): Computer(board){}
    int eval();
    Move* algorithm() override;
    int mini(int depth);
    int maxi(int depth);
};

#endif
