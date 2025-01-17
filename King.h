#ifndef KING_H
#define KING_H
#include "Board.h"

class King : public Piece
{
    int value = 1000000000;

public:
    bool in_check;
    King(Board *board, Position *pos, Color color);
    std::vector<Move *> movesNoCheck() override;
    std::vector<Move *> moves() override;
    ~King() {}
};
#endif
