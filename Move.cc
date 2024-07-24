#include "Move.h"

Move::Move(Piece* moving, Piece* captured, Position* init, Position* final): pieceMoving{moving}, pieceCapturing{captured}, initialPos{init}, finalPos{final} {}

Move::Move(const Move& other): pieceMoving{other.pieceMoving}, pieceCapturing{other.pieceCapturing}, initialPos{other.initialPos}, finalPos{other.finalPos} {}

Move& Move::operator=(const Move& other) {
    if (this == &other) return *this;
    pieceMoving = nullptr;
    pieceCapturing = nullptr;

    pieceMoving = other.pieceMoving;
    pieceCapturing = other.pieceCapturing;
    initialPos = other.initialPos;
    finalPos = other.finalPos;
}

Move::Move(Move&& other): pieceMoving{other.pieceMoving}, pieceCapturing{other.pieceCapturing}, initialPos{other.initialPos}, finalPos{other.finalPos}{
    other.pieceMoving = nullptr;
    other.pieceCapturing = nullptr;
}
Move& Move::operator=(Move&& other){
    if (this != &other) {
        pieceMoving = other.pieceMoving;
        pieceCapturing = other.pieceCapturing;
        initialPos = std::move(other.initialPos);
        finalPos = std::move(other.finalPos);

        other.pieceMoving = nullptr;
        other.pieceCapturing = nullptr;
    }
    return *this;
}

Move::~Move() {
    delete initialPos; delete finalPos;
}

Move Move::reverseMove(){
    return Move(pieceMoving, nullptr, finalPos, initialPos);
}
