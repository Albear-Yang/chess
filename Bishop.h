#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
    int value = 3;
public:
    Bishop(Board* board, Position pos, Color color);
    std::vector<Move*> moves() override;
    void move(Position pos) override;
    std::vector<Piece*> canCapture() override;
};

#endif // BISHOP_H
