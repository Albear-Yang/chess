#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
    int value = 1000000000;
public:
    bool in_check;
    bool has_moved;

    std::vector<Move*> moves() override;
    void move(Position pos) override;
    std::vector<Piece*> canCapture() override;
};

#endif
