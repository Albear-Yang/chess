#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Enums.h"
#include "Move.h"

class Player {
protected:
    Board board;
    Color color;
    int score;

public:
    virtual Move move() = 0;
};

#endif