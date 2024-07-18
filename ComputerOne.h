#ifndef COMPUTERONE_H
#define COMPUTERONE_H

#include "Player.h"
#include "Board.h"
#include "Computer.h"
#include "Move.h"

class ComputerOne : public Computer {
public:
    virtual Move algorithm() = 0;
};

#endif