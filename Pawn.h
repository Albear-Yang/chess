#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
    int value = 1;
public:
    bool has_moved = !((color == White && pos.y  == 2) || (color == Black && pos.y  == 7));

    std::vector<Move*> moves() override;
    void move(Position pos) override;
    std::vector<Piece*> canCapture() override;
};

#endif
