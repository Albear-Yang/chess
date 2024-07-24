#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include "Board.h"
#include "Move.h"

class Computer {
protected:
    Board *board;
public:
    Computer(Board *board): board{board}{};
    virtual Move* algorithm() = 0;
};

#endif
