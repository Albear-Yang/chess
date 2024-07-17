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

