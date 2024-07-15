#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Enums.h"
#include "Move.h"

class Player {
public:
    Board board;
    Color color;
    Score score;

    virtual Move move() = 0;
};

#endif