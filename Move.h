#ifndef MOVE_H
#define MOVE_H

#include "Position.h"
#include "Piece.h"

class Move {
    Piece *pieceMoving;
    Piece *pieceCapturing;
    Position initialPos;
    Position finalPos;
public:
    Move(Piece* moving, Piece* captured, Position init, Position final): pieceMoving{moving}, pieceCapturing{captured}, initialPos{init}, finalPos{final} {}
    Move(const &other);
    Move& operator=(const &other);
    Move(Move && other);
    Move& operator=(Move&& other);
    Move reverseMove(Move m);
};

#endif