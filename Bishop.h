#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
    value = 3;
public:
    std::vector<Move> moves(Position pos) override;
    void move(Position pos) override;
    std::vector<Piece*> canCapture() override;
};

#endif // BISHOP_H
