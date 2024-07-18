#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Piece;

class Queen : public Piece {
    int value = 9;
public:
    std::vector<Move*> moves() override;
    Queen(Board *board, Position pos, Color color);
    void move(Position newpos) override;
    std::vector<Move*> canCapture() override;
};

#endif
