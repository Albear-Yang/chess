#ifndef QUEEN_H
#define QUEEN_H
#include "Board.h"

class Queen : public Piece
{
    int value = 9;

public:
    std::vector<Move *> moves() override;
    std::vector<Move *> movesNoCheck() override;
    Queen(Board *board, Position *pos, Color color);
    ~Queen() {}
};

#endif
