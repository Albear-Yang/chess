#include "ComputerOne.h"
#include <stdlib.h>

Move *ComputerOne::algorithm()
{
    std::vector<Move *> possibleMoves;
    if (board->whosTurn == Color::WHITE)
    {
        possibleMoves = board->whiteMoves();
    }
    else
    {
        possibleMoves = board->blackMoves();
    }

    size_t movePicked = rand() % possibleMoves.size();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(possibleMoves.begin(), possibleMoves.end(), rng);

    Move *m = possibleMoves[movePicked];
    for (auto i = possibleMoves.begin(); i != possibleMoves.end();)
    {
        bool flag = false;
        if (m != *i)
        {
            if ((*i)->castle != nullptr)
                delete (*i)->castle;
            delete *i;
            possibleMoves.erase(i);
        }
        else
        {
            i++;
        }
    }
    return m;
}
