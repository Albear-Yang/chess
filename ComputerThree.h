#ifndef COMPUTERTHREE_H
#define COMPUTERTHREE_H

#include "Player.h"
#include "Board.h"
#include "Computer.h"
#include "Move.h"

class ComputerThree : public Computer {
public:
    ComputerThree(Board* board): Computer(board){}
    Move* algorithm() override;
};

#endif
