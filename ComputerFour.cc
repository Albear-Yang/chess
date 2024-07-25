#include "ComputerFour.h"

const int pawntable[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {5, 10, 10, -20, -20, 10, 10, 5},
    {10, 10, -10, 0, 0, -10, 10, 10},
    {0, 0, 0, 20, 20, 0, 0, 0},
    {5, 5, 10, 25, 25, 10, 5, 5},
    {10, 10, 20, 30, 30, 20, 10, 10},
    {50, 50, 50, 50, 50, 50, 50, 50},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

const int knightstable[8][8] = {
    {-25, -20, -15, -15, -15, -15, -20, -25},
    {-20, -10, 0, 5, 5, 0, -10, -20},
    {-30, 5, 10, 15, 15, 10, 5, -30},
    {-30, 0, 15, 20, 20, 15, 0, -30},
    {-30, 5, 15, 20, 20, 15, 5, -30},
    {-30, 0, 10, 15, 15, 10, 0, -30},
    {-20, -10, 0, 0, 0, 0, -10, -20},
    {-25, -20, -15, -15, -15, -15, -20, -25}
};

const int bishopstable[8][8] = {
    {-20, -10, -10, -10, -10, -10, -10, -20},
    {-10, 5, 0, 0, 0, 0, 5, -10},
    {-10, 10, 10, 10, 10, 10, 10, -10},
    {-10, 0, 10, 10, 10, 10, 0, -10},
    {-10, 5, 5, 10, 10, 5, 5, -10},
    {-10, 0, 5, 10, 10, 5, 0, -10},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-20, -10, -10, -10, -10, -10, -10, -20}
};

const int rookstable[8][8] = {
    {0, 0, 0, 5, 5, 0, 0, 0},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {5, 10, 10, 10, 10, 10, 10, 5},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

const int queenstable[8][8] = {
    {-20, -10, -10, -5, -5, -10, -10, -20},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-10, 5, 5, 5, 5, 5, 0, -10},
    {0, 0, 5, 5, 5, 5, 0, -5},
    {-5, 0, 5, 5, 5, 5, 0, -5},
    {-10, 0, 5, 5, 5, 5, 0, -10},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-20, -10, -10, -5, -5, -10, -10, -20}
};

const int kingstable[8][8] = {
    {20, 30, 10, 0, 0, 10, 30, 20},
    {20, 20, 0, 0, 0, 0, 20, 20},
    {-10, -20, -20, -20, -20, -20, -20, -10},
    {-20, -30, -30, -40, -40, -30, -30, -20},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30}
};

int ComputerFour:: eval(){
    int kingsq = 0;
    int pawnsq = 0;
    int bishopsq = 0;
    int rooksq = 0;
    int knightsq = 0;
    int queensq = 0;

    int material = 0;

    for(auto p : board->whitePieces){
        Position* pos = p->getPos();
        int x = 7 - pos->x;
        int y = 7 - pos->y;
        if(p->typeValue() == Type::PAWN){
            pawnsq += pawntable[x][y];
            material += 100;
        }
        else if(p->typeValue() == Type::KNIGHT){
            knightsq += knightstable[x][y];
            material += 320;
        }
        else if(p->typeValue() == Type::BISHOP){
            bishopsq += bishopstable[x][y];
            material += 330;
        }
        else if(p->typeValue() == Type::ROOK){
            rooksq += rookstable[x][y];
            material += 500;
        }
        else if(p->typeValue() == Type::QUEEN){
            queensq += queenstable[x][y];
            material += 900;
        }
        else if(p->typeValue() == Type::KING){
            kingsq += kingstable[x][y];
        }
    }
    for(auto p: board->blackPieces){
        Position* pos = p->getPos();
        int x = pos->x;
        int y = pos->y;
        if(p->typeValue() == Type::PAWN){
            pawnsq -= pawntable[x][y];
            material -= 100;
        }
        else if(p->typeValue() == Type::KNIGHT){
            knightsq -= knightstable[x][y];
            material -= 320;
        }
        else if(p->typeValue() == Type::BISHOP){
            bishopsq -= bishopstable[x][y];
            material -= 330;
        }
        else if(p->typeValue() == Type::ROOK){
            rooksq -= rookstable[x][y];
            material -= 500;
        }
        else if(p->typeValue() == Type::QUEEN){
            queensq -= queenstable[x][y];
            material -= 900;
        }
        else if(p->typeValue() == Type::KING){
            kingsq -= kingstable[x][y];
        }
    }

    if(board->stalemate()){
        return 0;
    }
    else if(board->checkmate()){
        if(board->whosTurn == Color::WHITE){
            return -99999;
        }
        else{
            return 99999;
        }
    }
    return material + kingsq + queensq + pawnsq + rooksq + bishopsq + knightsq;
}
//setup default done game computer[4] computer[4]
int ComputerFour::maxi(int depth, int alpha, int beta){
    if(depth == 0){
        return eval();
    }
    int maximum = -999999;
    int score = 0;
    Move* m = nullptr;
    std::vector<Move *> temp = board->whiteMoves();
    for(auto p : temp){
        board->addMove(p);
        Piece* capturee = p->pieceCaped();
        if (capturee) board->removePiece(capturee);
        score = mini(depth - 1, alpha, beta);
        board->undo();
        if (capturee) board->addPiece(capturee);

        if(score > maximum){
            maximum = score;
            m = p;
        }
        alpha = std::max(alpha, score);
        if (beta <= alpha) break;
    }
    for(auto i = temp.begin(); i != temp.end();){
        bool flag = false;
        if (m != *i) {
            if ((*i)->castle != nullptr) delete (*i)->castle;
            delete *i;
            temp.erase(i);
        }
        else {
            i++;
        }
        
    }
    if (bestMove) delete bestMove;
    bestMove = m;
    return eval();
}
int ComputerFour::mini(int depth, int alpha, int beta){
    if(depth == 0){
        return eval();
    }
    int minimum = 99999;
    int score = 0;
    Move* m = nullptr;

    std::vector<Move *> temp = board->blackMoves();
    for(auto p : temp){
        board->addMove(p);
        Piece* capturee = p->pieceCaped();
        if (capturee) board->removePiece(capturee);
        score = maxi(depth - 1, alpha, beta);
        board->undo();
        if (capturee) board->addPiece(capturee);

        if(score < minimum){
            minimum = score;
            m = p;
        }
        beta = std::min(beta, score);
        if (beta <= alpha) break;
    }
    for(auto i = temp.begin(); i != temp.end();){
        bool flag = false;
        if (m != *i) {
            if ((*i)->castle != nullptr) delete (*i)->castle;
            delete *i;
            temp.erase(i);
        }
        else {
            i++;
        }
    }
    if (bestMove) delete bestMove;
    bestMove = m;
    return eval();
}

Move* ComputerFour::algorithm(){
    if(board->whosTurn == Color::WHITE){
        bestMove = nullptr;
        int score = maxi(3, -10000, 10000);
        return bestMove;
    }
    else{
        bestMove = nullptr;
        /*for (auto p : board->blackPieces) {
            std::cout << p->getPos()->x << " " << p->getPos()->y << std::endl;
        }*/
        int score = mini(3, -10000, 10000);
        //std::cout << "black" << std::endl;
        std::cout << bestMove->initPos()->x << " " << bestMove->initPos()->y << " " << bestMove->finPos()->x << " " << bestMove->finPos()->y << std::endl;
        return bestMove;
    }
}