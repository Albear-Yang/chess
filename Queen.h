#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
    value = 9;
public:
    std::vector<Move*> moves() override;
    void move(Position newpos) override;
    std::vector<Move*> canCapture() override;
};

#endif
