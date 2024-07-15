#ifndef MOVE_H
#define MOVE_H

#include "Position.h"
#include "Piece.h"

class Move {
public:
    Piece *pieceMoving;
    Piece *pieceCapturing;
    Position initialPos;
    Position finalPos;

    Move reverseMove(Move m);
};

#endif