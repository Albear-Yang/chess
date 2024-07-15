#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Position.h"

enum class Color { Black, White };

class Piece {
public:
    Position pos;
    Color color;
    int value;

    Piece(Position pos, Color color);
    
    virtual std::vector<Move> moves(Position pos) = 0;
    virtual void move(Position pos) = 0;
    virtual std::vector<Piece*> canCapture() = 0;
    Color getColor();
};

#endif 