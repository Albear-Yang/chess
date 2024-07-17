#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Enums.h"
#include "Position.h"
#include "Move.h"
#include "Board.h"

class Piece {
    Board *board;
    Position pos;
    Color color;
    Type type;
    const int value;
public:
    Piece(Board* board, Position pos, Color color, Type type);
    
    virtual std::vector<Move*> moves() = 0;
    virtual void move(Position pos) = 0;
    virtual std::vector<Piece*> canCapture() = 0;
    virtual int positionValue() = 0;
    virtual int positionXValue() = 0;
    virtual int positionYValue() = 0;
    Position getPos() {return pos; };
    Type typeValue() { return type; };
    Color getColor() { return color; };
};

#endif
