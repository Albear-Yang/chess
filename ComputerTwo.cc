#include "ComputerTwo.h"
#include <stdlib.h> 


Move* ComputerTwo::algorithm() {
    std::vector<Move *> possibleMoves;
    if(board->whosTurn == Color::WHITE){
        possibleMoves = board->whiteMoves();
    }
    else{
        possibleMoves = board->blackMoves();
    }
    //filter through moves that capture
    std::vector<Move*> capturingMoves;
    for (Move* move : possibleMoves) {
        if (move->pieceCaped() != nullptr) {
            capturingMoves.push_back(move);
        }
    }

    if (!capturingMoves.empty()) {
        size_t movePicked = std::rand() % capturingMoves.size();
        return capturingMoves[movePicked];
    }
    size_t movePicked = std::rand() % possibleMoves.size();
    return possibleMoves[movePicked];

}
