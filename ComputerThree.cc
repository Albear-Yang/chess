#include "ComputerThree.h"
#include <stdlib.h> 


Move* ComputerThree::algorithm() {
    std::vector<Move *> possibleMoves;
    if(board->whosTurn == Color::WHITE){
        possibleMoves = board->whiteMoves();
    }
    else{
        possibleMoves = board->blackMoves();
    }

    std::vector<Move*> nonCapturingMoves;
    for (Move* move : possibleMoves) {
        if (move->pieceCaped() == nullptr) {
            nonCapturingMoves.push_back(move);
        }
    }

    if (!nonCapturingMoves.empty()) {
        size_t movePicked = std::rand() % nonCapturingMoves.size();
        return nonCapturingMoves[movePicked];
    }
    size_t movePicked = std::rand() % possibleMoves.size();
    return possibleMoves[movePicked];

}