#include "ComputerTwo.h"
#include <stdlib.h>

Move *ComputerTwo::algorithm()
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
    std::vector<Move *> capturingMoves;
    for (Move *move : possibleMoves)
    {
        if (move->pieceCaped() != nullptr)
        {
            capturingMoves.push_back(move);
        }
    }
    size_t movePicked = rand() % possibleMoves.size();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(possibleMoves.begin(), possibleMoves.end(), rng);
    if (!capturingMoves.empty())
    {
        size_t movePicked = std::rand() % capturingMoves.size();
        Move *m = capturingMoves[movePicked];
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
