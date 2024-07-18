#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Piece;

class Bishop : public Piece {
    int value = 3;
public:
    std::vector<Move*> moves() override;
    Bishop(Board *board, Position pos, Color color);
    void move(Position pos) override;
    std::vector<Move*> canCapture() override;
};

#endif // BISHOP_H
