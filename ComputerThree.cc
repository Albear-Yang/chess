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

    size_t movePicked = rand() % possibleMoves.size();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	

	std::default_random_engine rng{seed};
    std::shuffle( possibleMoves.begin(), possibleMoves.end(), rng );
    std::vector<Move*> nonCapturingMoves;
    for (Move* move : possibleMoves) {
        if (move->pieceCaped() == nullptr) {
            nonCapturingMoves.push_back(move);
        }
    }

    if (!nonCapturingMoves.empty()) {
        size_t movePicked = std::rand() % nonCapturingMoves.size();
        Move* m = nonCapturingMoves[movePicked];
        for(auto i = possibleMoves.begin(); i != possibleMoves.end();){
            bool flag = false;
            if ((*i)->castle != nullptr) flag = true;
            if (flag) {
                if (m != (*i)->castle) {
                    delete (*i)->castle;
                    delete *i;
                    possibleMoves.erase(i);
                }
                else i++;
            }
            else if (m != *i) {
                delete *i;
                possibleMoves.erase(i);
            }
            else {
                i++;
            }
        }
        //std::cout << "SIZE " << possibleMoves.size() << std::endl;
        return m;
    }

    Move* m = possibleMoves[movePicked];
    for(auto i = possibleMoves.begin(); i != possibleMoves.end();){
        bool flag = false;
        if ((*i)->castle != nullptr) flag = true;
        if (flag) {
            if (m != (*i)->castle) {
                delete (*i)->castle;
                delete *i;
                possibleMoves.erase(i);
            }
            else i++;
        }
        else if (m != *i) {
            delete *i;
            possibleMoves.erase(i);
        }
        else {
            i++;
        }
    }
    //std::cout << "SIZE " << possibleMoves.size() << std::endl;
    return m;

}
