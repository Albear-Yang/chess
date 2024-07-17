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
    virtual Type typeValue() = 0;
    Color getColor() { return color; };
    void movePos(int x, int y) { pos.x_coord = x; pos.y_coord = y; };
};

#endif
