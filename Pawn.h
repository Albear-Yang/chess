#ifndef PAWN_H
#define PAWN_H

#include "Board.h"

class Pawn : public Piece {
    int value = 1;
public:
    //bool has_moved = !((color == Color::WHITE && pos.y == 2) || (color == Color::BLACK && pos.y == 7));

    std::vector<Move*> moves() override;
    Pawn(Board *board, Position pos, Color color);
    void move(Position pos) override;
    std::vector<Move*> movesNoCheck() override;
    std::vector<Move*> canCapture() override;
};

#endif
