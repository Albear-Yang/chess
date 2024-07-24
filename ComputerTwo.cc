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

    size_t movePicked = rand() % possibleMoves.size();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	

	std::default_random_engine rng{seed};
    std::shuffle( possibleMoves.begin(), possibleMoves.end(), rng );
    if (!capturingMoves.empty()) {
        size_t movePicked = std::rand() % capturingMoves.size();
        return capturingMoves[movePicked];
    }
    return possibleMoves[movePicked];

}
