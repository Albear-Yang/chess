#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
    value = 1;
public:
    bool has_moved = !(color == White && );

    std::vector<Move*> moves() override;
    void move(Position pos) override;
    std::vector<Piece*> canCapture() override;
};

#endif
