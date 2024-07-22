#include "Board.h"

std::vector<Move*> Board::whiteMoves() {
    std::vector<Move*> whiteMoves;
    
    for (int z = 0; z < whitePieces.size(); ++z) {
        //std::cout << whitePieces.size() << std::endl;
        char c;
        Type type = whitePieces[z]->typeValue();
        if (type == Type::BISHOP) c = 'B';
        else if (type == Type::KNIGHT) c = 'N';
        else if (type == Type::PAWN) c = 'P';
        else if (type == Type::ROOK) c = 'R';
        else if (type == Type::QUEEN) c = 'Q';
        else if (type == Type::KING) c = 'K';
        std::cout << "sigma" << std::endl;
        std::vector<Move*> pMoves = whitePieces[z]->moves();
        std::cout << "sigma2" << std::endl;
        //remember to remove
        std::cout << c << " size " << pMoves.size() << std::endl;
        for (auto t : pMoves) {
            std::cout << t->initPos().x << " " << t->initPos().y << " " << t->finPos().x << " " << t->finPos().y << std::endl;
        }
        whiteMoves.insert(end(whiteMoves), begin(pMoves), end(pMoves));
    }
    //std::cout << whiteMoves.size() << std::endl;
    return whiteMoves;
}

std::vector<Move*> Board::blackMoves() {
    std::vector<Move*> blackMoves;
    for (int z = 0; z < blackPieces.size(); ++z) {
        //std::cout << whitePieces.size() << std::endl;
        char c;
        Type type = blackPieces[z]->typeValue();
        if (type == Type::BISHOP) c = 'b';
        else if (type == Type::KNIGHT) c = 'n';
        else if (type == Type::PAWN) c = 'p';
        else if (type == Type::ROOK) c = 'r';
        else if (type == Type::QUEEN) c = 'q';
        else if (type == Type::KING) c = 'k';
        std::cout << c << " size ";
        std::vector<Move*> pMoves = blackPieces[z]->moves();
        //remember to remove
        std::cout << pMoves.size() << std::endl;
        for (auto t : pMoves) {
            std::cout << t->initPos().x << " " << t->initPos().y << " " << t->finPos().x << " " << t->finPos().y << std::endl;
        }
        blackMoves.insert(end(blackMoves), begin(pMoves), end(pMoves));
    }
    //std::cout << whiteMoves.size() << std::endl;
    return blackMoves;
}

bool Board::draw() {
    if (whosTurn == Color::WHITE && whiteMoves().empty()) return true;
    if (whosTurn == Color::BLACK && blackMoves().empty()) return true;
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

bool Board::checkmate() {
    if (whosTurn == Color::WHITE) {
        if (!check4check(Color::WHITE)) return false;
        int x, y;
        for (auto p : whitePieces) {
            if (p->typeValue() == Type::KING) { x = p->positionXValue(); y = p->positionYValue(); }
        }
        for (auto p : whiteMoves()) {
            if (p->pieceMoved()->typeValue() == Type::KING) return false;
            addMove(p);
            if (!check4check(Color::WHITE)) return false;
            undo();
        }
    }
    return true;
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
            for (auto move : p->moves()) {
                if (k->positionXValue() == move->finPos().x && k->positionYValue() == move->finPos().y) {
                    return true;
                }
            }
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
            for (auto move : p->moves()) {
                if (k->positionXValue() == move->finPos().x && k->positionYValue() == move->finPos().y) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Board::addMove(Move* move) {
    Piece* pieceMoved = move->pieceMoved();
    if (whosTurn == Color::WHITE) {
        whosTurn == Color::BLACK;
    }
    else {
        whosTurn == Color::WHITE;
    }
    //removePiece(pieceMoved);
    pieceMoved->movePos(move->finPos().x, move->finPos().y);
    //addPiece(pieceMoved);
    pastMoves.emplace_back(move);
    if (pieceMoved->typeValue() == Type::PAWN) {
        pieceMoved->has_moved == true;
    }
}

void Board::undo() {
    if (whosTurn == Color::WHITE) {
        whosTurn == Color::BLACK;
    }
    else {
        whosTurn == Color::WHITE;
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
            pieceMoved->movePos(lastMove->finPos().x, lastMove->finPos().y);
        }
        else {
            Piece* piece;
            for (auto p : startingWhitePieces) {
                if (p->positionXValue() == pieceMoved->positionXValue() && p->positionYValue() == pieceMoved->positionYValue()) {
                    piece = p; break;
                }
            }
            pieceMoved->movePos(piece->positionXValue(), piece->positionYValue());
            if (pieceMoved->typeValue() == Type::PAWN || pieceMoved->typeValue() == Type::ROOK || pieceMoved->typeValue() == Type::KING) {
                pieceMoved->has_moved = true;
            }
        }
    }
    else {
        Move* lastMove = nullptr;
        for (auto p : pastMoves) {
            if (p->pieceMoved() == pieceMoved) lastMove = p;
        }
        if (lastMove != nullptr) {
            pieceMoved->movePos(lastMove->finPos().x, lastMove->finPos().y);
        }
        else {
            Piece* piece;
            for (auto p : startingBlackPieces) {
                if (p->positionXValue() == pieceMoved->positionXValue() && p->positionYValue() == pieceMoved->positionYValue()) {
                    piece = p; break;
                }
            }
            pieceMoved->movePos(piece->positionXValue(), piece->positionYValue());
            if (pieceMoved->typeValue() == Type::PAWN || pieceMoved->typeValue() == Type::ROOK || pieceMoved->typeValue() == Type::KING) {
                pieceMoved->has_moved = true;
            }
        }
    }
}

bool Board::check4checkMove(Color king, Move* move) {
    Piece* starter = move->pieceMoved();
    Piece* capturee = nullptr;
    if (move->pieceCaped() != nullptr) {
        capturee = move->pieceCaped();
    }
    if (king == Color::WHITE) {
        Piece* k;
        for (auto p : whitePieces) {
            if (p->typeValue() == Type::KING) {
                k = p; break;
            }
        }
        for (int i = k->pos.x + 1; i < 8; ++i) {
            Position temp = Position(i, k->pos.y);
            for (auto o : blackPieces) {
                if (temp == o->getPos()) {
                    if (o->typeValue() == Type::ROOK || o->typeValue() == Type::QUEEN) {
                        
                    }
                }
            }
        }
    }
}

/*bool Board::check4checkMove(Color king, Move* move) {
    addMove(move);
    Piece* capturee = nullptr;
    if (move->pieceCaped() != nullptr) capturee = move->pieceCaped();
    if (move->pieceCaped() != nullptr) removePiece(capturee);
    
    //setup test game human human move e2 f3
    if (king == Color::WHITE) {
        Piece* k;
        for (auto p : whitePieces) {
            if (p->typeValue() == Type::KING) {
                k = p; break;
            }
        }
        for (auto p : blackPieces) {
            for (auto move : p->movesNoCheck()) {
                if (k->positionXValue() == move->finPos().x && k->positionYValue() == move->finPos().y) {
                    undo();
                    if (move->pieceCaped() != nullptr) addPiece(capturee);
                    return true;
                }
            }
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
            for (auto move : p->movesNoCheck()) {
                if (k->positionXValue() == move->finPos().x && k->positionYValue() == move->finPos().y) {
                    undo();
                    if (move->pieceCaped() != nullptr) addPiece(capturee);
                    return true;
                }
            }
        }
    }
    return false;
}*/

void Board::addPiece(Piece* piece) {
    if (piece->getColor() == Color::WHITE) {
        whitePieces.emplace_back(piece);
    }
    else {
        blackPieces.emplace_back(piece);
    }
}

void Board::addPiece(Type type, Color color, int x, int y) {
    if (type == Type::ROOK) addPiece(new Rook(this, *new Position{x, y}, color));
    else if (type == Type::BISHOP) addPiece(new Bishop(this, *new Position{x, y}, color));
    else if (type == Type::KING) addPiece(new King(this, *new Position{x, y}, color));
    else if (type == Type::QUEEN) addPiece(new Queen(this, *new Position{x, y}, color));
    else if (type == Type::KNIGHT) addPiece(new Knight(this, *new Position{x, y}, color));
    else if (type == Type::PAWN) addPiece(new Pawn(this, *new Position{x, y}, color));
}

void Board::removePiece(Piece* piece) {
    if (piece->getColor() == Color::WHITE) {
        for (auto p = whitePieces.begin(); p != whitePieces.end();) {
            if (*p == piece) {
                whitePieces.erase(p);
                return;
            }
            else p++;
        }
    }
    else {
        for (auto p = blackPieces.begin(); p != blackPieces.end();) {
            if (*p == piece) {
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
            whitePieces.erase(p);
            return;
        }
        else p++;
    }
    for (auto p = blackPieces.begin(); p != blackPieces.end();) {
        if ((*p)->positionXValue() == x && (*p)->positionYValue() == y) {
            blackPieces.erase(p);
            return;
        }
        else p++;
    }
}

int Board::boardLength() { return LEN_MAX; }

Board::~Board() {
    for (auto p : startingBlackPieces) {
        delete p;
    }
    for (auto p : startingWhitePieces) {
        delete p;
    }
    for (auto p : blackPieces) {
        delete p;
    }
    for (auto p : whitePieces) {
        delete p;
    }
    for (auto m : pastMoves) {
        delete m;
    }
}
