#ifndef COMPUTER_H
#define COMPUTER_H
#include "Board.h"
#include "Move.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class Computer
{
protected:
    Board *board;
public:
    Computer(Board *board) : board{board} {};
    virtual Move *algorithm() = 0;
};
#endif
