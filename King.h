#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    bool in_check;
    bool has_moved;

    std::vector<Move> moves(Position pos) override;
    void move(Position pos) override;
    std::vector<Piece*> canCapture() override;
};

#endif // KING_H
