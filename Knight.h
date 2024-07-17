#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    std::vector<Move*> moves(Position pos) override;
    void move(Position pos) override;
    std::vector<Piece*> canCapture() override;
};

#endif
