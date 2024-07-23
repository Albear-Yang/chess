#include "ComputerOne.h"
#include <stdlib.h> 


Move* ComputerOne::algorithm() {
    std::vector<Move *> possibleMoves;
    if(board->whosTurn == Color::WHITE){
        possibleMoves = board->whiteMoves();
    }
    else{
        possibleMoves = board->blackMoves();
    }

    size_t movePicked = rand() % possibleMoves.size();
    
    return possibleMoves[movePicked];

}