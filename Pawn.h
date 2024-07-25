#ifndef PAWN_H
#define PAWN_H
#include "Board.h"

class Pawn : public Piece
{
    int value = 1;

public:
    std::vector<Move *> moves() override;
    Pawn(Board *board, Position *pos, Color color);
    std::vector<Move *> movesNoCheck() override;
    ~Pawn() {}
};
#endif
