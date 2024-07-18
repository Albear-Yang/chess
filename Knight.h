#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
    int value = 3;
public:
    std::vector<Move*> moves() override;
    void move(Position pos) override;
    std::vector<Piece*> canCapture() override;
};

#endif
