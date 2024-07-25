#ifndef COMPUTERTWO_H
#define COMPUTERTWO_H

#include "Board.h"
#include "Computer.h"
#include "Move.h"

class ComputerTwo : public Computer {
public:
    ComputerTwo(Board* board): Computer(board){}
    Move* algorithm() override;
};

#endif