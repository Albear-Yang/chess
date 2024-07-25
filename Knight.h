#ifndef KNIGHT_H
#define KNIGHT_H
#include "Board.h"

class Knight : public Piece
{
    int value = 3;

public:
    std::vector<Move *> moves() override;
    Knight(Board *board, Position *pos, Color color);
    std::vector<Move *> movesNoCheck() override;
    ~Knight() {}
};
#endif
