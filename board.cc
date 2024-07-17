#include "Board.h"

std::vector<Move*> Board::whiteMoves() {
     std::vector<Move*> whiteMoves;
     for (auto p : white_pieces) {
        std::vector<Move*> pMoves;
        whiteMoves.insert(end(whiteMoves), begin(pMoves), end(pMoves));
     }
     return whiteMoves;
}

std::vector<Move*> Board::blackMoves() {
     std::vector<Move*> blackMoves;
     for (auto p : black_pieces) {
        std::vector<Move*> pMoves;
        blackMoves.insert(end(blackMoves), begin(pMoves), end(pMoves));
     }
     return blackMoves;
}

bool Board::draw() {
    if (whosTurn == Color::White && whiteMoves().empty()) return true;
    if (whosTurn == Color::Black && blackMoves().empty()) return true;
    if (white_pieces.size() == 1 && black_pieces.size() == 1 && white_pieces[0]->typeValue() == Type::King && black_pieces[0]->typeValue() == Type::King) return true;
    if (white_pieces.size() == 1 && black_pieces.size() == 1 && white_pieces[0]->typeValue() == Type::King && black_pieces[0]->typeValue() == Type::King) return true;
    if (white_pieces.size() == 2 && black_pieces.size() == 1 && white_pieces[0]->typeValue() == Type::King && white_pieces[1]->typeValue() == Type::Bishop && black_pieces[0]->typeValue() == Type::King) return true;
    if (white_pieces.size() == 2 && black_pieces.size() == 1 && white_pieces[1]->typeValue() == Type::King && white_pieces[0]->typeValue() == Type::Bishop && black_pieces[0]->typeValue() == Type::King) return true;
    if (white_pieces.size() == 1 && black_pieces.size() == 2 && black_pieces[0]->typeValue() == Type::King && black_pieces[1]->typeValue() == Type::Bishop && white_pieces[0]->typeValue() == Type::King) return true;
    if (white_pieces.size() == 1 && black_pieces.size() == 2 && black_pieces[1]->typeValue() == Type::King && black_pieces[0]->typeValue() == Type::Bishop && white_pieces[0]->typeValue() == Type::King) return true;
    if (white_pieces.size() == 2 && black_pieces.size() == 1 && white_pieces[0]->typeValue() == Type::King && white_pieces[1]->typeValue() == Type::Knight && black_pieces[0]->typeValue() == Type::King) return true;
    if (white_pieces.size() == 2 && black_pieces.size() == 1 && white_pieces[1]->typeValue() == Type::King && white_pieces[0]->typeValue() == Type::Knight && black_pieces[0]->typeValue() == Type::King) return true;
    if (white_pieces.size() == 1 && black_pieces.size() == 2 && black_pieces[0]->typeValue() == Type::King && black_pieces[1]->typeValue() == Type::Knight && white_pieces[0]->typeValue() == Type::King) return true;
    if (white_pieces.size() == 1 && black_pieces.size() == 2 && black_pieces[1]->typeValue() == Type::King && black_pieces[0]->typeValue() == Type::Knight && white_pieces[0]->typeValue() == Type::King) return true;
    if (white_pieces.size() == 2 && black_pieces.size() == 2 && black_pieces[0]->typeValue() == Type::King && black_pieces[1]->typeValue() == Type::Bishop && white_pieces[0]->typeValue() == Type::King && white_pieces[1]->typeValue() == Type::Bishop && black_pieces[1]->positionXValue() + black_pieces[1]->positionYValue() % 2 == 0 && white_pieces[1]->positionXValue() + white_pieces[1]->positionYValue() % 2 == 0) return true;
    if (white_pieces.size() == 2 && black_pieces.size() == 2 && black_pieces[1]->typeValue() == Type::King && black_pieces[0]->typeValue() == Type::Bishop && white_pieces[1]->typeValue() == Type::King && white_pieces[0]->typeValue() == Type::Bishop && black_pieces[0]->positionXValue() + black_pieces[0]->positionYValue() % 2 == 0 && white_pieces[0]->positionXValue() + white_pieces[0]->positionYValue() % 2 == 0) return true;
    if (white_pieces.size() == 2 && black_pieces.size() == 2 && black_pieces[1]->typeValue() == Type::King && black_pieces[0]->typeValue() == Type::Bishop && white_pieces[0]->typeValue() == Type::King && white_pieces[1]->typeValue() == Type::Bishop && black_pieces[0]->positionXValue() + black_pieces[0]->positionYValue() % 2 == 0 && white_pieces[1]->positionXValue() + white_pieces[1]->positionYValue() % 2 == 0) return true;
    if (white_pieces.size() == 2 && black_pieces.size() == 2 && black_pieces[0]->typeValue() == Type::King && black_pieces[1]->typeValue() == Type::Bishop && white_pieces[1]->typeValue() == Type::King && white_pieces[0]->typeValue() == Type::Bishop && black_pieces[1]->positionXValue() + black_pieces[1]->positionYValue() % 2 == 0 && white_pieces[0]->positionXValue() + white_pieces[0]->positionYValue() % 2 == 0) return true;
    return false;
}

bool Board::checkmate() {
    if (whosTurn == Color::White) {
        if (!check4check(Color::White)) return false;
        int x, y;
        for (auto p : white_pieces) {
            if (p->typeValue() == Type::King) { x = p->positionXValue(); y = p->positionYValue(); }
        }
        for (auto p : whiteMoves()) {
            if (p->pieceMoved()->typeValue() == Type::King) return false;
            addMove(p);
            if (!check4check(Color::White)) return false;
            undo();
        }
    }
    return true;
}

bool Board::check4check(Color king) {
    if (king == Color::White) {
        Piece* k;
        for (auto p : white_pieces) {
            if (p->typeValue() == Type::King) {
                k = p; break;
            }
        }
        for (auto p : black_pieces) {
            for (auto move : p->moves()) {
                if (k->positionXValue() == move->finPos().x_coord && k->positionYValue() == move->finPos().y_coord) {
                    return true;
                }
            }
        }
    }
    else {
        Piece* k;
        for (auto p : black_pieces) {
            if (p->typeValue() == Type::King) {
                k = p; break;
            }
        }
        for (auto p : white_pieces) {
            for (auto move : p->moves()) {
                if (k->positionXValue() == move->finPos().x_coord && k->positionYValue() == move->finPos().y_coord) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Board::addMove(Move* move) {
    Piece* pieceMoved = move->pieceMoved();
    if (whosTurn == Color::White) {
        whosTurn == Color::Black;
    }
    else {
        whosTurn == Color::White;
    }
    removePiece(pieceMoved);
    pieceMoved->movePos(move->finPos().x_coord, move->finPos().y_coord);
    addPiece(pieceMoved);
    pastMoves.emplace_back(move);
}

void Board::undo() {
    if (whosTurn == Color::White) {
        whosTurn == Color::Black;
    }
    else {
        whosTurn == Color::White;
    }
    Move* undoMove = pastMoves.back();
    pastMoves.pop_back();
    Piece* pieceMoved = undoMove->pieceMoved();
    removePiece(pieceMoved);
    if (pieceMoved->getColor() == Color::White) {
        Move* lastMove = nullptr;
        for (auto p : pastMoves) {
            if (p->pieceMoved() == pieceMoved) lastMove = p;
        }
        if (lastMove != nullptr) {
            pieceMoved->movePos(lastMove->finPos().x_coord, lastMove->finPos().y_coord);
            addPiece(pieceMoved);
        }
        else {
            Piece* piece;
            for (auto p : starting_white_pieces) {
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
            pieceMoved->movePos(lastMove->finPos().x_coord, lastMove->finPos().y_coord);
            addPiece(pieceMoved);
        }
        else {
            Piece* piece;
            for (auto p : starting_black_pieces) {
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
    if (piece->getColor() == Color::White) {
        white_pieces.emplace_back(piece);
    }
    else {
        black_pieces.emplace_back(piece);
    }
}

void Board::removePiece(Piece* piece) {
    if (piece->getColor() == Color::White) {
        for (auto p = white_pieces.begin(); p != white_pieces.end();) {
            if (*p == piece) {
                white_pieces.erase(p);
                break;
            }
            else p++;
        }
    }
    else {
        for (auto p = black_pieces.begin(); p != black_pieces.end();) {
            if (*p == piece) {
                black_pieces.erase(p);
                break;
            }
            else p++;
        }
    }
}

int Board::boardLength() { return LEN_MAX; }


