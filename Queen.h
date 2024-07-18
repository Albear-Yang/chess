#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
    int value = 9;
public:
    Queen::Queen(Board* board, Position pos, Color color);
    std::vector<Move*> moves() override;
    Queen(Board *board, Position pos, Color color);
    void move(Position newpos) override;
    std::vector<Piece*> canCapture() override;
};

#endif
