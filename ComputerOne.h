#ifndef COMPUTERONE_H
#define COMPUTERONE_H
#include "Board.h"
#include "Computer.h"
#include "Move.h"

class ComputerOne : public Computer
{
public:
    ComputerOne(Board *board) : Computer(board) {}
    Move *algorithm() override;
};
#endif
