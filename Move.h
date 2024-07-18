#ifndef MOVE_H
#define MOVE_H
#include "Piece.h"
#include "Position.h"

class Piece;

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
    Piece* pieceCaped(){
        return pieceCapturing;
    }
    Position initPos(){
        return initialPos;
    };
    Position finPos(){
        return finalPos;
    };

};

#endif