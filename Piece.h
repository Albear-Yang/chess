#ifndef PIECE_H
#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Enums.h"
#include "Position.h"
#include "Move.h"

class Piece {
    Position pos;
    Color color;
    Type type;
    int value;
public:
    Piece(Position pos, Color color, Type type);
    
    virtual std::vector<Move*> moves(Position pos) = 0;
    virtual void move(Position pos) = 0;
    virtual std::vector<Piece*> canCapture() = 0;
    virtual int positionValue() = 0;
    virtual int positionXValue() = 0;
    virtual int positionYValue() = 0;
    virtual Type typeValue() = 0;
    Color getColor() { return color; };
};

#endif