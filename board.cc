#include "Board.h"

std::vector<Move*> Board::whiteMoves() {
     std::vector<Move*> whiteMoves;
     for (auto p : whitePieces) {
        std::vector<Move*> pMoves;
        whiteMoves.insert(end(whiteMoves), begin(pMoves), end(pMoves));
     }
     return whiteMoves;
}

std::vector<Move*> Board::blackMoves() {
     std::vector<Move*> blackMoves;
     for (auto p : blackPieces) {
        std::vector<Move*> pMoves;
        blackMoves.insert(end(blackMoves), begin(pMoves), end(pMoves));
     }
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
    removePiece(pieceMoved);
    pieceMoved->movePos(move->finPos().x, move->finPos().y);
    addPiece(pieceMoved);
    pastMoves.emplace_back(move);
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
    removePiece(pieceMoved);
    if (pieceMoved->getColor() == Color::WHITE) {
        Move* lastMove = nullptr;
        for (auto p : pastMoves) {
            if (p->pieceMoved() == pieceMoved) lastMove = p;
        }
        if (lastMove != nullptr) {
            pieceMoved->movePos(lastMove->finPos().x, lastMove->finPos().y);
            addPiece(pieceMoved);
        }
        else {
            Piece* piece;
            for (auto p : startingWhitePieces) {
                if (p == pieceMoved) {
                    piece = p; break;
                }
            }
            pieceMoved->movePos(piece->positionXValue(), piece->positionYValue());
            addPiece(pieceMoved);
        }
    }
    else {
        Move* lastMove = nullptr;
        for (auto p : pastMoves) {
            if (p->pieceMoved() == pieceMoved) lastMove = p;
        }
        if (lastMove != nullptr) {
            pieceMoved->movePos(lastMove->finPos().x, lastMove->finPos().y);
            addPiece(pieceMoved);
        }
        else {
            Piece* piece;
            for (auto p : startingBlackPieces) {
                if (p == pieceMoved) {
                    piece = p; break;
                }
            }
            pieceMoved->movePos(piece->positionXValue(), piece->positionYValue());
            addPiece(pieceMoved);
        }
    }
}

void Board::addPiece(Piece* piece) {
    if (piece->getColor() == Color::WHITE) {
        whitePieces.emplace_back(piece);
    }
    else {
        blackPieces.emplace_back(piece);
    }
}

void Board::removePiece(Piece* piece) {
    if (piece->getColor() == Color::WHITE) {
        for (auto p = whitePieces.begin(); p != whitePieces.end();) {
            if (*p == piece) {
                whitePieces.erase(p);
                break;
            }
            else p++;
        }
    }
    else {
        for (auto p = blackPieces.begin(); p != blackPieces.end();) {
            if (*p == piece) {
                blackPieces.erase(p);
                break;
            }
            else p++;
        }
    }
}

int Board::boardLength() { return LEN_MAX; }


