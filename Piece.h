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
    int positionXValue();
    int positionYValue();
    Type typeValue();
    Color getColor();
};

#endif 