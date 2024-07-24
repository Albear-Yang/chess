#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include "Board.h"
#include "Move.h"

class Computer : public Player {
protected:
    Board *board;
public:
    virtual Move* algorithm() = 0;
};

#endif
