#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Enums.h"
#include "Position.h"

enum class Color { Black, White };

class Piece {
    Position pos;
    Color color;
    int value;
public:

    Piece(Position pos, Color color);
    
    virtual std::vector<Move> moves(Position pos) = 0;
    virtual void move(Position pos) = 0;
    virtual std::vector<Piece*> canCapture() = 0;
    int positionValue();
    Color getColor();
};

#endif 