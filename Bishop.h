#ifndef BISHOP_H
#define BISHOP_H
#include "Board.h"

class Bishop : public Piece {
    int value = 3;
public:
    std::vector<Move*> moves() override;
    std::vector<Move*> movesNoCheck() override;
    Bishop(Board *board, Position* pos, Color color);
    //void move(Position pos) override;
    //std::vector<Move*> canCapture() override;
    ~Bishop() {}
};

#endif // BISHOP_H
