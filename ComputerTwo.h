#ifndef COMPUTERTWO_H
#define COMPUTERTWO_H

#include "Player.h"
#include "Board.h"
#include "Computer.h"
#include "Move.h"

class ComputerTwo : public Computer {
public:
    Move algorithm() = 0;
};

#endif