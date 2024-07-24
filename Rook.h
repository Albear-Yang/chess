#ifndef ROOK_H
#define ROOK_H

#include "Board.h"

class Rook : public Piece {
    int value = 5;
public:

    Rook(Board *board, Position* pos, Color color);
    std::vector<Move *> moves() override;
    //void move(Position pos) override;
    //std::vector<Move *> canCapture() override;
    std::vector<Move*> movesNoCheck() override;
    ~Rook() {}
};

#endif
