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
    Move(Piece* moving, Piece* captured, Position init, Position final);
    Move(const Move& other);
    Move& operator=(const Move& other);
    Move(Move && other);
    Move& operator=(Move&& other);
    Move reverseMove(Move m);
    Piece* pieceMoved(){
        return pieceMoving;
    }
    Position initPos(){
        return initialPos;
    };
    Position finPos(){
        return finalPos;
    };

};

#endif