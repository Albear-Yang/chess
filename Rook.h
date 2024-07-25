#ifndef ROOK_H
#define ROOK_H
#include "Board.h"

class Rook : public Piece
{
    int value = 5;

public:
    Rook(Board *board, Position *pos, Color color);
    std::vector<Move *> moves() override;
    std::vector<Move *> movesNoCheck() override;
    ~Rook() {}
};
#endif
