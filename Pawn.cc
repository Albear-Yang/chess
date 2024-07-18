#include "Pawn.h"
using namespace std;

Pawn::Pawn(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::PAWN) {}

vector<Move*> Pawn::moves() {
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    bool noPieceBetween = true;

    for (int z = 0; z < board->blackPieces.size(); ++z) {
        allPieces.push_back(board->blackPieces[z]);
    } 
    for (int z = 0; z < board->whitePieces.size(); ++z) {
        allPieces.push_back(board->whitePieces[z]);
    }

    int reverse = 1;
    if (color == Color::BLACK) {
        reverse = -1;
    }

    // Normal moving forward
    for (int i = 1; i < 3; ++i) {
        if (i == 2 && has_moved) {
            continue;
        }
        Position tempPos = Position(pos.x, pos.y + reverse * i);

        for (int z = 0; z < allPieces.size() && noPieceBetween; ++z) {
            if (tempPos == allPieces[z]->pos) {
                noPieceBetween = false;
                break;
            }
        }
        if (!noPieceBetween) {
            break;
        }
        possibleMoves.push_back(new Move(this, nullptr, pos, tempPos));
    }

    // Normal capturing
    Position captR = Position(pos.x + 1, pos.y + reverse);
    Position captL = Position(pos.x - 1, pos.y + reverse);
    for (int z = 0; z < allPieces.size(); ++z) {
        if (captR == allPieces[z]->pos) {
            possibleMoves.push_back(new Move(this, allPieces[z], pos, captR));
        } else if (captL == allPieces[z]->pos) {
            possibleMoves.push_back(new Move(this, allPieces[z], pos, captL));
        }
    }

    // En passant capturing
    if (color == Color::WHITE && pos.y == 5 || color == Color::BLACK && pos.y == 4) {
        const auto& lastMove = board->pastMoves.back();
        if (lastMove->pieceMoved()->typeValue() == Type::PAWN && abs(lastMove->initPos().y - lastMove->finPos().y) == 2) {
            Position capturedPos = lastMove->finPos();
            if (capturedPos.y == pos.y && (capturedPos.x == pos.x - 1 || capturedPos.x == pos.x + 1)) {
                possibleMoves.push_back(new Move(this, lastMove->pieceMoved(), pos, Position(capturedPos.x, pos.y + reverse)));
            }
        }
    }

    // Check if moves put own king in check
    for (int i = 0; i < possibleMoves.size(); ) {
        board->addMove(possibleMoves[i]);
        if (board->check4check(color)) {
            delete possibleMoves[i];
            possibleMoves.erase(possibleMoves.begin() + i);
        } else {
            ++i;
        }
        board->undo();
    }

    return possibleMoves;
}

void Pawn::move(Position newpos) {
    has_moved = true;
    pos = newpos;
}

vector<Move*> Pawn::canCapture() {
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for (int z = 0; z < board->blackPieces.size(); ++z) {
        allPieces.push_back(board->blackPieces[z]);
    }
    for (int z = 0; z < board->whitePieces.size(); ++z) {
        allPieces.push_back(board->whitePieces[z]);
    }

    int reverse = 1;
    if (color == Color::BLACK) {
        reverse = -1;
    }

    // Normal capturing
    Position captR = Position(pos.x + 1, pos.y + reverse);
    Position captL = Position(pos.x - 1, pos.y + reverse);
    for (int z = 0; z < allPieces.size(); ++z) {
        if (captR == allPieces[z]->pos) {
            possibleMoves.push_back(new Move(this, allPieces[z], pos, captR));
        } else if (captL == allPieces[z]->pos) {
            possibleMoves.push_back(new Move(this, allPieces[z], pos, captL));
        }
    }

    // En passant capturing
    if (color == Color::WHITE && pos.y == 5 || color == Color::BLACK && pos.y == 4) {
        const auto& lastMove = board->pastMoves.back();
        if (lastMove->pieceMoved()->typeValue() == Type::PAWN && abs(lastMove->initPos().y - lastMove->finPos().y) == 2) {
            Position capturedPos = lastMove->finPos();
            if (capturedPos.y == pos.y && (capturedPos.x == pos.x - 1 || capturedPos.x == pos.x + 1)) {
                possibleMoves.push_back(new Move(this, lastMove->pieceMoved(), pos, Position(capturedPos.x, pos.y + reverse)));
            }
        }
    }

    return possibleMoves;
}
