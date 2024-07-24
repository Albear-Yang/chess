#include "Board.h"

std::vector<Move*> Board::whiteMoves() {
    std::vector<Move*> whiteMoves;
    //setup test game human human move a7 a8 Q move e8 e7 move a8 a6 move e7 f8 move h1 h7 move f8 g8 move a6 a8
    for (int z = 0; z < whitePieces.size(); ++z) {
        std::vector<Move*> pMoves = whitePieces[z]->moves();
        //std::cout << " size " << pMoves.size() << std::endl;
        //std::cout << whitePieces.size() << std::endl;x
        /*char c;
        Type type = whitePieces[z]->typeValue();
        if (type == Type::BISHOP) c = 'B';
        else if (type == Type::KNIGHT) c = 'N';
        else if (type == Type::PAWN) c = 'P';
        else if (type == Type::ROOK) c = 'R';
        else if (type == Type::QUEEN) c = 'Q';
        else if (type == Type::KING) c = 'K';
        std::cout << c << " size " << pMoves.size() << std::endl;
        for (auto t : pMoves) {
            std::cout << t->initPos()->x << " " << t->initPos()->y << " " << t->finPos()->x << " " << t->finPos()->y << std::endl;
        }*/
        whiteMoves.insert(end(whiteMoves), begin(pMoves), end(pMoves));
    }
    Piece* r1 = nullptr;
    Piece* r2 = nullptr;
    Piece* k = nullptr;
    for (auto p : whitePieces) {
        if (p->typeValue() == Type::ROOK) {
            if (r1 == nullptr) {
                r1 = p;
            }
            else {
                r2 = p;
            }
        }
        if (p->typeValue() == Type::KING) {
            k = p;
        }
        if (r1 != nullptr && r2 != nullptr && k != nullptr) break;
    }
    bool pass = true;
    int i1, j1, i2, j2, ri1, ri2, rj1, rj2;
    i1 = j1 = i2 = j2 = ri1 = ri2 = rj1 = rj2 = -1;
    if (r1 != nullptr) {
        if (r1->getPos()->x == 7 && r1->getPos()->y == 0 && k->getPos()->x == 7 && k->getPos()->y == 4 && empty(7, 1) && empty(7, 2) && empty(7, 3) && !r1->has_moved && !k->has_moved) {
            i1 = 7; j1 = 4; i2 = 7; j2 = 2; ri1 = 7; rj1 = 0; ri2 = 7; rj2 = 3;
            std::vector<Move*> temp = blackMovesNoCastle();
            for (auto m : temp) {
                if ((m->finPos()->x == 7 && m->finPos()->y == 4) || (m->finPos()->x == 7 && m->finPos()->y == 3) || (m->finPos()->x == 7 && m->finPos()->y == 2)) {
                    pass = false;
                }
            }
            for (auto m : temp) { delete m; }
        }
        else if (r1->getPos()->x == 7 && r1->getPos()->y == 7 && k->getPos()->x == 7 && k->getPos()->y == 4 && empty(7, 5) && empty(7, 6) && !r1->has_moved && !k->has_moved) {
            i1 = 7; j1 = 4; i2 = 7; j2 = 6; ri1 = 7; rj1 = 7; ri2 = 7; rj2 = 5;
            std::vector<Move*> temp = blackMovesNoCastle();
            for (auto m : temp) {
                if ((m->finPos()->x == 7 && m->finPos()->y == 4) || (m->finPos()->x == 7 && m->finPos()->y == 5) || (m->finPos()->x == 7 && m->finPos()->y == 6)) {
                    pass = false;
                }
            }
            for (auto m : temp) { delete m; }
        }
    }
    if (pass && r1 != nullptr && i1 != -1) {
        Move* castling = new Move{k, nullptr, new Position{i1, j1}, new Position{i2, j2}};
        castling->castle = new Move{r1, nullptr, new Position{ri1, rj1}, new Position{ri2, rj2}};
        whiteMoves.emplace_back(castling);
    }
    pass = true;
    i1 = j1 = i2 = j2 = ri1 = ri2 = rj1 = rj2 = -1;
    if (r2 != nullptr) {
        if (r2->getPos()->x == 7 && r2->getPos()->y == 0 && k->getPos()->x == 7 && k->getPos()->y == 4 && empty(7, 1) && empty(7, 2) && empty(7, 3) && !r2->has_moved && !k->has_moved) {
            i1 = 7; j1 = 4; i2 = 7; j2 = 2; ri1 = 7; rj1 = 0; ri2 = 7; rj2 = 3;
            std::vector<Move*> temp = blackMovesNoCastle();
            for (auto m : temp) {
                if ((m->finPos()->x == 7 && m->finPos()->y == 4) || (m->finPos()->x == 7 && m->finPos()->y == 3) || (m->finPos()->x == 7 && m->finPos()->y == 2)) {
                    pass = false;
                }
            }
            for (auto m : temp) { delete m; }
        }
        else if (r2->getPos()->x == 7 && r2->getPos()->y == 7 && k->getPos()->x == 7 && k->getPos()->y == 4 && empty(7, 5) && empty(7, 6) && !r2->has_moved && !k->has_moved) {
            i1 = 7; j1 = 4; i2 = 7; j2 = 6; ri1 = 7; rj1 = 7; ri2 = 7; rj2 = 5;
            std::vector<Move*> temp = blackMovesNoCastle();
            for (auto m : temp) {
                if ((m->finPos()->x == 7 && m->finPos()->y == 4) || (m->finPos()->x == 7 && m->finPos()->y == 5) || (m->finPos()->x == 7 && m->finPos()->y == 6)) {
                    pass = false;
                }
            }
            for (auto m : temp) { delete m; }
        }
    }
    if (pass && r2 != nullptr && i1 != -1) {
        Move* castling = new Move{k, nullptr, new Position{i1, j1}, new Position{i2, j2}};
        castling->castle = new Move{r2, nullptr, new Position{ri1, rj1}, new Position{ri2, rj2}};
        whiteMoves.emplace_back(castling);
    }
    //std::cout << whiteMoves.size() << std::endl;
    return whiteMoves;
}

std::vector<Move*> Board::whiteMovesNoCastle() {
    std::vector<Move*> whiteMoves;
    //setup test game human human move a7 a8 Q move e8 e7 move a8 a6 move e7 f8 move h1 h7 move f8 g8 move a6 a8
    for (int z = 0; z < whitePieces.size(); ++z) {
        std::vector<Move*> pMoves = whitePieces[z]->moves();
        //std::cout << " size " << pMoves.size() << std::endl;
        //std::cout << whitePieces.size() << std::endl;
        /*char c;
        Type type = whitePieces[z]->typeValue();
        if (type == Type::BISHOP) c = 'B';
        else if (type == Type::KNIGHT) c = 'N';
        else if (type == Type::PAWN) c = 'P';
        else if (type == Type::ROOK) c = 'R';
        else if (type == Type::QUEEN) c = 'Q';
        else if (type == Type::KING) c = 'K';
        std::cout << c << " size " << pMoves.size() << std::endl;
        for (auto t : pMoves) {
            std::cout << t->initPos()->x << " " << t->initPos()->y << " " << t->finPos()->x << " " << t->finPos()->y << std::endl;
        }*/
        whiteMoves.insert(end(whiteMoves), begin(pMoves), end(pMoves));
    }
    //std::cout << whiteMoves.size() << std::endl;
    return whiteMoves;
}

std::vector<Move*> Board::blackMoves() {
    std::vector<Move*> blackMoves;
    //std::cout << "BLACK PIECES NUMBER " << blackPieces.size() << std::endl;
    for (int z = 0; z < blackPieces.size(); ++z) {
        //std::cout << blackPieces[z]->getPos()->x << " " << blackPieces[z]->getPos()->y << std::endl;
        std::vector<Move*> pMoves = blackPieces[z]->moves();
        //std::cout << " size " << pMoves.size() << std::endl;
        //std::cout << whitePieces.size() << std::endl;
        /*char c;
        Type type = blackPieces[z]->typeValue();
        if (type == Type::BISHOP) c = 'b';
        else if (type == Type::KNIGHT) c = 'n';
        else if (type == Type::PAWN) c = 'p';
        else if (type == Type::ROOK) c = 'r';
        else if (type == Type::QUEEN) c = 'q';
        else if (type == Type::KING) c = 'k';
        std::cout << c << " size ";
        
        //remember to remove
        std::cout << pMoves.size() << std::endl;
        for (auto t : pMoves) {
            std::cout << t->initPos()->x << " " << t->initPos()->y << " " << t->finPos()->x << " " << t->finPos()->y << std::endl;
        }*/
        blackMoves.insert(end(blackMoves), begin(pMoves), end(pMoves));
    }
    Piece* r1 = nullptr;
    Piece* r2 = nullptr;
    Piece* k = nullptr;
    for (auto p : blackPieces) {
        if (p->typeValue() == Type::ROOK) {
            if (r1 == nullptr) {
                r1 = p;
            }
            else r2 = p;
        }
        if (p->typeValue() == Type::KING) k = p;
        if (r1 != nullptr && r2 != nullptr && k != nullptr) break;
    }
    bool pass = true;
    int i1, j1, i2, j2, ri1, ri2, rj1, rj2;
    i1 = j1 = i2 = j2 = ri1 = ri2 = rj1 = rj2 = -1;
    if (r1 != nullptr) {
        if (r1->getPos()->x == 0 && r1->getPos()->y == 0 && k->getPos()->x == 0 && k->getPos()->y == 4 && empty(0, 1) && empty(0, 2) && empty(0, 3) && !r1->has_moved && !k->has_moved) {
            i1 = 0; j1 = 4; i2 = 0; j2 = 2; ri1 = 0; rj1 = 0; ri2 = 0; rj2 = 3;
            std::vector<Move*> temp = whiteMovesNoCastle();
            for (auto m : temp) {
                if ((m->finPos()->x == 0 && m->finPos()->y == 4) || (m->finPos()->x == 0 && m->finPos()->y == 3) || (m->finPos()->x == 0 && m->finPos()->y == 2)) {
                    pass = false;
                }
            }
            for (auto m : temp) { delete m; }
        }
        else if (r1->getPos()->x == 0 && r1->getPos()->y == 0 && k->getPos()->x == 0 && k->getPos()->y == 4 && empty(0, 5) && empty(0, 6) && !r1->has_moved && !k->has_moved) {
            i1 = 0; j1 = 4; i2 = 0; j2 = 6; ri1 = 0; rj1 = 0; ri2 = 0; rj2 = 5;
            std::vector<Move*> temp = whiteMovesNoCastle();
            for (auto m : temp) {
                if ((m->finPos()->x == 0 && m->finPos()->y == 4) || (m->finPos()->x == 0 && m->finPos()->y == 5) || (m->finPos()->x == 0 && m->finPos()->y == 6)) {
                    pass = false;
                }
            }
            for (auto m : temp) { delete m; }
        }
    }
    if (pass && r1 != nullptr && i1 != -1) {
        Move* castling = new Move{k, nullptr, new Position{i1, j1}, new Position{i2, j2}};
        castling->castle = new Move{r1, nullptr, new Position{ri1, rj1}, new Position{ri2, rj2}};
        blackMoves.emplace_back(castling);
    }
    pass = true;
    i1 = j1 = i2 = j2 = ri1 = ri2 = rj1 = rj2 = -1;
    if (r2 != nullptr) {
        if (r2->getPos()->x == 0 && r2->getPos()->y == 0 && k->getPos()->x == 0 && k->getPos()->y == 4 && empty(0, 1) && empty(0, 2) && empty(0, 3) && !r2->has_moved && !k->has_moved) {
            i1 = 0; j1 = 4; i2 = 0; j2 = 2; ri1 = 0; rj1 = 0; ri2 = 0; rj2 = 3;
            std::vector<Move*> temp = whiteMovesNoCastle();
            for (auto m : temp) {
                if ((m->finPos()->x == 0 && m->finPos()->y == 4) || (m->finPos()->x == 0 && m->finPos()->y == 3) || (m->finPos()->x == 0 && m->finPos()->y == 2)) {
                    pass = false;
                }
            }
            for (auto m : temp) { delete m; }
        }
        else if (r2->getPos()->x == 0 && r2->getPos()->y == 0 && k->getPos()->x == 0 && k->getPos()->y == 4 && empty(0, 5) && empty(0, 6) && !r2->has_moved && !k->has_moved) {
            i1 = 0; j1 = 4; i2 = 0; j2 = 6; ri1 = 0; rj1 = 0; ri2 = 0; rj2 = 5;
            std::vector<Move*> temp = whiteMovesNoCastle();
            for (auto m : temp) {
                if ((m->finPos()->x == 0 && m->finPos()->y == 4) || (m->finPos()->x == 0 && m->finPos()->y == 5) || (m->finPos()->x == 0 && m->finPos()->y == 6)) {
                    pass = false;
                }
            }
            for (auto m : temp) { delete m; }
        }
    }
    if (pass && r2 != nullptr && i1 != -1) {
        Move* castling = new Move{k, nullptr, new Position{i1, j1}, new Position{i2, j2}};
        castling->castle = new Move{r2, nullptr, new Position{ri1, rj1}, new Position{ri2, rj2}};
        blackMoves.emplace_back(castling);
    }
    //std::cout << blackMoves.size() << std::endl;
    /*for (auto t : blackMoves) {
        std::cout << t->initPos()->x << " " << t->initPos()->y << " " << t->finPos()->x << " " << t->finPos()->y << std::endl;
    }*/
    return blackMoves;
}

std::vector<Move*> Board::blackMovesNoCastle() {
    std::vector<Move*> blackMoves;
    for (int z = 0; z < blackPieces.size(); ++z) {
        std::vector<Move*> pMoves = blackPieces[z]->moves();
        //std::cout << " size " << pMoves.size() << std::endl;
        //std::cout << whitePieces.size() << std::endl;
        /*char c;
        Type type = blackPieces[z]->typeValue();
        if (type == Type::BISHOP) c = 'b';
        else if (type == Type::KNIGHT) c = 'n';
        else if (type == Type::PAWN) c = 'p';
        else if (type == Type::ROOK) c = 'r';
        else if (type == Type::QUEEN) c = 'q';
        else if (type == Type::KING) c = 'k';
        std::cout << c << " size ";
        
        //remember to remove
        std::cout << pMoves.size() << std::endl;
        for (auto t : pMoves) {
            std::cout << t->initPos()->x << " " << t->initPos()->y << " " << t->finPos()->x << " " << t->finPos()->y << std::endl;
        }*/
        blackMoves.insert(end(blackMoves), begin(pMoves), end(pMoves));
    }
    //std::cout << whiteMoves.size() << std::endl;
    return blackMoves;
}

bool Board::draw() {
    if (whitePieces.size() == 1 && blackPieces.size() == 1 && whitePieces[0]->typeValue() == Type::KING && blackPieces[0]->typeValue() == Type::KING) return true;
    if (whitePieces.size() == 1 && blackPieces.size() == 1 && whitePieces[0]->typeValue() == Type::KING && blackPieces[0]->typeValue() == Type::KING) return true;
    if (whitePieces.size() == 2 && blackPieces.size() == 1 && whitePieces[0]->typeValue() == Type::KING && whitePieces[1]->typeValue() == Type::BISHOP && blackPieces[0]->typeValue() == Type::KING) return true;
    if (whitePieces.size() == 2 && blackPieces.size() == 1 && whitePieces[1]->typeValue() == Type::KING && whitePieces[0]->typeValue() == Type::BISHOP && blackPieces[0]->typeValue() == Type::KING) return true;
    if (whitePieces.size() == 1 && blackPieces.size() == 2 && blackPieces[0]->typeValue() == Type::KING && blackPieces[1]->typeValue() == Type::BISHOP && whitePieces[0]->typeValue() == Type::KING) return true;
    if (whitePieces.size() == 1 && blackPieces.size() == 2 && blackPieces[1]->typeValue() == Type::KING && blackPieces[0]->typeValue() == Type::BISHOP && whitePieces[0]->typeValue() == Type::KING) return true;
    if (whitePieces.size() == 2 && blackPieces.size() == 1 && whitePieces[0]->typeValue() == Type::KING && whitePieces[1]->typeValue() == Type::KNIGHT && blackPieces[0]->typeValue() == Type::KING) return true;
    if (whitePieces.size() == 2 && blackPieces.size() == 1 && whitePieces[1]->typeValue() == Type::KING && whitePieces[0]->typeValue() == Type::KNIGHT && blackPieces[0]->typeValue() == Type::KING) return true;
    if (whitePieces.size() == 1 && blackPieces.size() == 2 && blackPieces[0]->typeValue() == Type::KING && blackPieces[1]->typeValue() == Type::KNIGHT && whitePieces[0]->typeValue() == Type::KING) return true;
    if (whitePieces.size() == 1 && blackPieces.size() == 2 && blackPieces[1]->typeValue() == Type::KING && blackPieces[0]->typeValue() == Type::KNIGHT && whitePieces[0]->typeValue() == Type::KING) return true;
    if (whitePieces.size() == 2 && blackPieces.size() == 2 && blackPieces[0]->typeValue() == Type::KING && blackPieces[1]->typeValue() == Type::BISHOP && whitePieces[0]->typeValue() == Type::KING && whitePieces[1]->typeValue() == Type::BISHOP && blackPieces[1]->positionXValue() + blackPieces[1]->positionYValue() % 2 == 0 && whitePieces[1]->positionXValue() + whitePieces[1]->positionYValue() % 2 == 0) return true;
    if (whitePieces.size() == 2 && blackPieces.size() == 2 && blackPieces[1]->typeValue() == Type::KING && blackPieces[0]->typeValue() == Type::BISHOP && whitePieces[1]->typeValue() == Type::KING && whitePieces[0]->typeValue() == Type::BISHOP && blackPieces[0]->positionXValue() + blackPieces[0]->positionYValue() % 2 == 0 && whitePieces[0]->positionXValue() + whitePieces[0]->positionYValue() % 2 == 0) return true;
    if (whitePieces.size() == 2 && blackPieces.size() == 2 && blackPieces[1]->typeValue() == Type::KING && blackPieces[0]->typeValue() == Type::BISHOP && whitePieces[0]->typeValue() == Type::KING && whitePieces[1]->typeValue() == Type::BISHOP && blackPieces[0]->positionXValue() + blackPieces[0]->positionYValue() % 2 == 0 && whitePieces[1]->positionXValue() + whitePieces[1]->positionYValue() % 2 == 0) return true;
    if (whitePieces.size() == 2 && blackPieces.size() == 2 && blackPieces[0]->typeValue() == Type::KING && blackPieces[1]->typeValue() == Type::BISHOP && whitePieces[1]->typeValue() == Type::KING && whitePieces[0]->typeValue() == Type::BISHOP && blackPieces[1]->positionXValue() + blackPieces[1]->positionYValue() % 2 == 0 && whitePieces[0]->positionXValue() + whitePieces[0]->positionYValue() % 2 == 0) return true;
    return false;
}

bool Board::empty(int x, int y) {
    for (auto p : whitePieces) {
        if (p->getPos()->x == x && p->getPos()->y == y) return false;
    }
    for (auto p : blackPieces) {
        if (p->getPos()->x == x && p->getPos()->y == y) return false;
    }
    return true;
}

bool Board::checkmate() {
    if (!check4check(Color::WHITE)) return false;
    if (!check4check(Color::BLACK)) return false;
    if (whosTurn == Color::WHITE) {
        std::vector<Move*> temp = whiteMoves();
        if (temp.empty()) { for (auto m : temp) { if (m->castle != nullptr) { delete m->castle; } delete m; } return true; } 
        for (auto m : temp) { if (m->castle != nullptr) { delete m->castle; } delete m; }
    }
    else {
        std::vector<Move*> temp = blackMoves();
        if (temp.empty()) { for (auto m : temp) { if (m->castle != nullptr) { delete m->castle; } delete m; } return true; } 
        for (auto m : temp) { if (m->castle != nullptr) { delete m->castle; } delete m; }
    } 
    return false;
}

bool Board::stalemate() {
    if (whosTurn == Color::WHITE) {
        std::vector<Move*> temp = whiteMoves();
        if (temp.empty()) { for (auto m : temp) { if (m->castle != nullptr) { delete m->castle; } delete m; } return true; } 
        for (auto m : temp) { if (m->castle != nullptr) { delete m->castle; } delete m; }
    }
    else {
        std::vector<Move*> temp = blackMoves();
        if (temp.empty()) { for (auto m : temp) { if (m->castle != nullptr) { delete m->castle; } delete m; } return true; } 
        for (auto m : temp) { if (m->castle != nullptr) { delete m->castle; } delete m; }
    } 
    return false;
}

bool Board::check4check(Color king) {
    if (king == Color::WHITE) {
        Piece* k;
        for (auto p : whitePieces) {
            if (p->typeValue() == Type::KING) {
                k = p; break;
            }
        }
        for (auto p : blackPieces) {
            std::vector<Move*> temp = p->movesNoCheck();
            for (auto move : temp) {
                if (k->positionXValue() == move->finPos()->x && k->positionYValue() == move->finPos()->y) {
                    for (auto m : temp) { delete m; }
                    return true;
                }
            }
            for (auto m : temp) { delete m; }
        }
    }
    else {
        Piece* k;
        for (auto p : blackPieces) {
            if (p->typeValue() == Type::KING) {
                k = p; break;
            }
        }
        for (auto p : whitePieces) {
            std::vector<Move*> temp = p->movesNoCheck();
            for (auto move : temp) {
                if (k->positionXValue() == move->finPos()->x && k->positionYValue() == move->finPos()->y) {
                    for (auto m : temp) { delete m; }
                    return true;
                }
            }
            for (auto m : temp) { delete m; }
        }
    }
    return false;
}

void Board::addMove(Move* move) {
    Piece* pieceMoved = move->pieceMoved();
    pieceMoved->has_moved = true;
    if (whosTurn == Color::WHITE) {
        whosTurn = Color::BLACK;
    }
    else {
        whosTurn = Color::WHITE;
    }
    //removePiece(pieceMoved);
    /*char c;
        Type type = pieceMoved->typeValue();
        if (type == Type::BISHOP) c = 'B';
        else if (type == Type::KNIGHT) c = 'N';
        else if (type == Type::PAWN) c = 'P';
        else if (type == Type::ROOK) c = 'R';
        else if (type == Type::QUEEN) c = 'Q';
        else if (type == Type::KING) c = 'K';
        std::cout << c << std::endl;
    std::cout << move->finPos()->x << " " << move->finPos()->y << std::endl;*/
    //std::cout << pieceMoved->getPos()->x << " " << pieceMoved->getPos()->x << std::endl;
    pieceMoved->movePos(move->finPos()->x, move->finPos()->y);
    //std::cout << pieceMoved->getPos()->x << " " << pieceMoved->getPos()->x << std::endl;
    //addPiece(pieceMoved);
    pastMoves.emplace_back(move);
    if (move->castle != nullptr) {
        if (whosTurn == Color::WHITE) {
            whosTurn = Color::BLACK;
        }
        else {
            whosTurn = Color::WHITE;
        }
        addMove(move->castle);
    }
}

void Board::undoMinMax() {
    if (whosTurn == Color::WHITE) {
        whosTurn = Color::BLACK;
    }
    else {
        whosTurn = Color::WHITE;
    }
    Move* undoMove = pastMoves.back();
    pastMoves.pop_back();
    Piece* pieceMoved = undoMove->pieceMoved();
    /*Move reverse = undoMove->reverseMove();
    addMove(&reverse);
    pastMoves.pop_back();*/
    //removePiece(pieceMoved);
    if(undoMove->pieceCaped() != nullptr){
        addPiece(undoMove->pieceCaped());
    }
    
    if (pieceMoved->getColor() == Color::WHITE) {
        Move* lastMove = nullptr;
        for (auto p : pastMoves) {
            if (p->pieceMoved() == pieceMoved) lastMove = p;
        }
        if (lastMove != nullptr) {
            pieceMoved->movePos(lastMove->finPos()->x, lastMove->finPos()->y);
        }
        else {
            Piece* piece;
            for (auto p : startingWhitePieces) {
                if (p->positionXValue() == undoMove->initPos()->x && p->positionYValue() == undoMove->initPos()->y) {
                    piece = p; break;
                }
            }
            pieceMoved->movePos(piece->positionXValue(), piece->positionYValue());
            pieceMoved->has_moved = false;
        }
    }
    else {
        Move* lastMove = nullptr;
        for (auto p : pastMoves) {
            if (p->pieceMoved() == pieceMoved) lastMove = p;
        }
        if (lastMove != nullptr) {
            pieceMoved->movePos(lastMove->finPos()->x, lastMove->finPos()->y);
        }
        else {
            Piece* piece;
            for (auto p : startingBlackPieces) {
                if (p->positionXValue() == undoMove->initPos()->x && p->positionYValue() == undoMove->initPos()->y) {
                    piece = p; break;
                }
            }
            pieceMoved->movePos(piece->positionXValue(), piece->positionYValue());
            pieceMoved->has_moved = false;
        }
    }
    if (!pastMoves.empty()) {
        if (pastMoves.back()->castle != nullptr) {
            undo();
        }
    }
}

void Board::addMoveMinMax(Move* move) {
    Piece* pieceMoved = move->pieceMoved();
    pieceMoved->has_moved = true;
    if (whosTurn == Color::WHITE) {
        whosTurn = Color::BLACK;
    }
    else {
        whosTurn = Color::WHITE;
    }
    //removePiece(pieceMoved);
    /*char c;
        Type type = pieceMoved->typeValue();
        if (type == Type::BISHOP) c = 'B';
        else if (type == Type::KNIGHT) c = 'N';
        else if (type == Type::PAWN) c = 'P';
        else if (type == Type::ROOK) c = 'R';
        else if (type == Type::QUEEN) c = 'Q';
        else if (type == Type::KING) c = 'K';
        std::cout << c << std::endl;
    std::cout << move->finPos()->x << " " << move->finPos()->y << std::endl;*/
    //std::cout << pieceMoved->getPos()->x << " " << pieceMoved->getPos()->x << std::endl;
    pieceMoved->movePos(move->finPos()->x, move->finPos()->y);
    //std::cout << pieceMoved->getPos()->x << " " << pieceMoved->getPos()->x << std::endl;
    //addPiece(pieceMoved);
    pastMoves.emplace_back(move);
    if (move->castle != nullptr) {
        if (whosTurn == Color::WHITE) {
            whosTurn = Color::BLACK;
        }
        else {
            whosTurn = Color::WHITE;
        }
        addMove(move->castle);
    }
    removePiece(move->finPos()->x, move->finPos()->y);
}

void Board::undo() {
    if (whosTurn == Color::WHITE) {
        whosTurn = Color::BLACK;
    }
    else {
        whosTurn = Color::WHITE;
    }
    Move* undoMove = pastMoves.back();
    pastMoves.pop_back();
    Piece* pieceMoved = undoMove->pieceMoved();
    /*Move reverse = undoMove->reverseMove();
    addMove(&reverse);
    pastMoves.pop_back();*/
    //removePiece(pieceMoved);
    if (pieceMoved->getColor() == Color::WHITE) {
        Move* lastMove = nullptr;
        for (auto p : pastMoves) {
            if (p->pieceMoved() == pieceMoved) lastMove = p;
        }
        if (lastMove != nullptr) {
            pieceMoved->movePos(lastMove->finPos()->x, lastMove->finPos()->y);
        }
        else {
            Piece* piece;
            for (auto p : startingWhitePieces) {
                if (p->positionXValue() == undoMove->initPos()->x && p->positionYValue() == undoMove->initPos()->y) {
                    piece = p; break;
                }
            }
            pieceMoved->movePos(piece->positionXValue(), piece->positionYValue());
            pieceMoved->has_moved = false;
        }
    }
    else {
        Move* lastMove = nullptr;
        for (auto p : pastMoves) {
            if (p->pieceMoved() == pieceMoved) lastMove = p;
        }
        if (lastMove != nullptr) {
            pieceMoved->movePos(lastMove->finPos()->x, lastMove->finPos()->y);
        }
        else {
            Piece* piece;
            for (auto p : startingBlackPieces) {
                if (p->positionXValue() == undoMove->initPos()->x && p->positionYValue() == undoMove->initPos()->y) {
                    piece = p; break;
                }
            }
            pieceMoved->movePos(piece->positionXValue(), piece->positionYValue());
            pieceMoved->has_moved = false;
        }
    }
    if (!pastMoves.empty()) {
        if (pastMoves.back()->castle != nullptr) {
            undo();
        }
    }

}


bool Board::check4checkMove(Color king, Move* move) {
    addMove(move);
    Piece* capturee = nullptr;
    if (move->pieceCaped() != nullptr) {capturee = move->pieceCaped();}
    //if (capturee != nullptr) removePiece(capturee);
    
    //setup test game human human move e2 f3
    if (king == Color::WHITE) {
        Piece* k;
        for (auto p : whitePieces) {
            if (p->typeValue() == Type::KING) {
                k = p; break;
            }
        }
        for (auto p : blackPieces) {
            std::vector<Move*> temp = p->movesNoCheck();
            for (auto move : temp) {
                //std::cout << "Q " << whitePieces[1]->pos.x << " " << whitePieces[1]->pos.y << std::endl;
                if (capturee != nullptr) {
                    if (move->initPos()->x != capturee->getPos()->x && move->initPos()->y != capturee->getPos()->y && k->positionXValue() == move->finPos()->x && k->positionYValue() == move->finPos()->y) {
                        undo();
                        for (auto m : temp) { delete m; }
                        return true;
                    }
                }
                else {
                    if (k->positionXValue() == move->finPos()->x && k->positionYValue() == move->finPos()->y) {
                        undo();
                        for (auto m : temp) { delete m; }
                        return true;
                    }
                }
            }
            for (auto m : temp) { delete m; }
        }
    }
    else {
        Piece* k;
        for (auto p : blackPieces) {
            if (p->typeValue() == Type::KING) {
                k = p; break;
            }
        }
        for (auto p : whitePieces) {
            std::vector<Move*> temp = p->movesNoCheck();
            for (auto move : temp) {
                if (capturee != nullptr) {
                    if (move->initPos()->x != capturee->getPos()->x && move->initPos()->y != capturee->getPos()->y && k->positionXValue() == move->finPos()->x && k->positionYValue() == move->finPos()->y) {
                        undo();
                        for (auto m : temp) { delete m; }
                        return true;
                    }
                }
                else {
                    if (k->positionXValue() == move->finPos()->x && k->positionYValue() == move->finPos()->y) {
                        undo();
                        for (auto m : temp) { delete m; }
                        return true;
                    }
                }
            }
            for (auto m : temp) { delete m; }
        }
    }
    undo();
    return false;
}

void Board::addPiece(Piece* piece) {
    
    if (piece->getColor() == Color::WHITE) {
        whitePieces.emplace_back(piece);
    }
    else {
        blackPieces.emplace_back(piece);
    }
}

void Board::addPiece(Type type, Color color, int x, int y) {
    if (type == Type::ROOK) addPiece(new Rook(this, new Position{x, y}, color));
    else if (type == Type::BISHOP) addPiece(new Bishop(this, new Position{x, y}, color));
    else if (type == Type::KING) addPiece(new King(this, new Position{x, y}, color));
    else if (type == Type::QUEEN) addPiece(new Queen(this, new Position{x, y}, color));
    else if (type == Type::KNIGHT) addPiece(new Knight(this, new Position{x, y}, color));
    else if (type == Type::PAWN) addPiece(new Pawn(this, new Position{x, y}, color));
}

void Board::removePiece(Piece* piece) {
    if (piece->getColor() == Color::WHITE) {
        for (auto p = whitePieces.begin(); p != whitePieces.end();) {
            if (*p == piece) {
                gone.emplace_back(*p);
                whitePieces.erase(p);
                return;
            }
            else p++;
        }
    }
    else {
        for (auto p = blackPieces.begin(); p != blackPieces.end();) {
            if (*p == piece) {
                gone.emplace_back(*p);
                blackPieces.erase(p);
                return;
            }
            else p++;
        }
    }
}

void Board::removePiece(int x, int y) {
    for (auto p = whitePieces.begin(); p != whitePieces.end();) {
        if ((*p)->positionXValue() == x && (*p)->positionYValue() == y) {
            gone.emplace_back(*p);
            whitePieces.erase(p);
            return;
        }
        else p++;
    }
    for (auto p = blackPieces.begin(); p != blackPieces.end();) {
        if ((*p)->positionXValue() == x && (*p)->positionYValue() == y) {
            gone.emplace_back(*p);
            blackPieces.erase(p);
            return;
        }
        else p++;
    }
}

int Board::boardLength() { return LEN_MAX; }

void Board::clear() {
    for (int i = 0; i < startingBlackPieces.size(); i++) {
        delete startingBlackPieces[i];
    }
    for (int i = 0; i < startingWhitePieces.size(); i++) {
        delete startingWhitePieces[i];
    }
    for (int i = 0; i < whitePieces.size(); i++) {
        delete whitePieces[i];
    }
    for (int i = 0; i < blackPieces.size(); i++) {
        delete blackPieces[i];
    }
    for (int i = 0; i < pastMoves.size(); i++) {
        delete pastMoves[i];
    }
    for (int i = 0; i < gone.size(); i++) {
        delete gone[i];
    }
    startingBlackPieces.clear();
    startingWhitePieces.clear();
    blackPieces.clear();
    whitePieces.clear();
    pastMoves.clear();
    gone.clear();
    hasWhiteKing = false;
    hasBlackKing = false;
    round1 = true;
    whosTurn = Color::WHITE;
    setup = false;
}

Board::~Board() {
    clear();
}
