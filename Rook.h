#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
    int value = 5;
public:
    bool has_moved;

    std::vector<Move*> moves(Position pos) override;
    void move(Position pos) override;
    std::vector<Piece*> canCapture() override;
};

#endif
