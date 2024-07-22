#include "Pawn.h"
using namespace std;

Pawn::Pawn(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::PAWN) {}

vector<Move*> Pawn::moves() {
    if (enpassable != nullptr) delete enpassable;
    enpassable = nullptr;
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    //bool noPieceBetween = true;

    for (int z = 0; z < board->blackPieces.size(); ++z) {
        allPieces.push_back(board->blackPieces[z]);
    } 
    for (int z = 0; z < board->whitePieces.size(); ++z) {
        allPieces.push_back(board->whitePieces[z]);
    }

    for (auto p : board->startingWhitePieces) {
        if (p == this && (p->getPos().x != pos.x || p->getPos().y != pos.y)) {
            has_moved = false;
        }
    }

    int reverse = -1;
    if (color == Color::BLACK) {
        reverse = 1;
    }

    // Normal moving forward
    for (int i = 1; i < 3; ++i) {
        if (i == 2 && has_moved) {
            continue;
        }
        //Position tempPos = Position(pos.x, pos.y + reverse * i);

        /*for (int z = 0; z < allPieces.size() && noPieceBetween; ++z) {
            if (tempPos == allPieces[z]->pos) {
                noPieceBetween = false;
                break;
            }
        }
        if (!noPieceBetween) {
            break;
        }*/

        bool pass = true;
        for (int z = 0; z < allPieces.size(); ++z) {
            if (pos.x + reverse * i == allPieces[z]->getPos().x && pos.y == allPieces[z]->getPos().y) {
                pass = false;
                break;
            }
        }   
        if (pass) possibleMoves.push_back(new Move(this, nullptr, pos, *new Position{pos.x + reverse * i, pos.y})); //does tempPos go out of stack? *new Position{pos.x, pos.y + reverse * i}
        else break;
    }

    // Normal capturing
    Position captR = Position(pos.x + reverse, pos.y + 1);
    Position captL = Position(pos.x + reverse, pos.y - 1);
    for (int z = 0; z < allPieces.size(); ++z) {
        if (captR == allPieces[z]->pos && allPieces[z]->getColor() != color) {
            possibleMoves.push_back(new Move(this, allPieces[z], pos, captR));
        }
        if (captL == allPieces[z]->pos && allPieces[z]->getColor() != color) {
            possibleMoves.push_back(new Move(this, allPieces[z], pos, captL));
        }
    }

    // En passant capturing
    if (color == Color::WHITE && pos.x == 3) {
        for (auto m : board->pastMoves) {
            if (m->pieceMoved()->typeValue() == Type::PAWN && m->pieceMoved()->getColor() == Color::BLACK) {
                if (!(m->finPos().x == 2 && (m->finPos().y == pos.y - 1 || m->finPos().y == pos.y + 1)) && m->pieceMoved() == board->pastMoves.back()->pieceMoved() && board->pastMoves.back()->finPos().x == 3) {
                    possibleMoves.push_back(new Move(this, board->pastMoves.back()->pieceMoved(), pos, *new Position{2, board->pastMoves.back()->finPos().y}));
                    enpassable = new Position{2, board->pastMoves.back()->finPos().y};
                    break;
                }
            } 
        }

        /*const auto& lastMove = board->pastMoves.back();
        if (lastMove->pieceMoved()->typeValue() == Type::PAWN && abs(lastMove->initPos().y - lastMove->finPos().y) == 2) {
            Position capturedPos = lastMove->finPos();
            if (capturedPos.y == pos.y && (capturedPos.x == pos.x - 1 || capturedPos.x == pos.x + 1)) {
                possibleMoves.push_back(new Move(this, lastMove->pieceMoved(), pos, Position(capturedPos.x, pos.y + reverse)));
            }
        }*/
    }
    else if (color == Color::BLACK && pos.x == 4) {
        for (auto m : board->pastMoves) {
            if (m->pieceMoved()->typeValue() == Type::PAWN && m->pieceMoved()->getColor() == Color::WHITE) {
                if (!(m->finPos().x == 5 && (m->finPos().y == pos.y - 1 || m->finPos().y == pos.y + 1)) && m->pieceMoved() == board->pastMoves.back()->pieceMoved() && board->pastMoves.back()->finPos().x == 4) {
                    possibleMoves.push_back(new Move(this, board->pastMoves.back()->pieceMoved(), pos, *new Position{5, board->pastMoves.back()->finPos().y}));
                    enpassable = new Position{5, board->pastMoves.back()->finPos().y};
                    break;
                }
            } 
        }
    }

    // Check if moves put own king in check
    /*for (int i = 0; i < possibleMoves.size(); ) {
        board->addMove(possibleMoves[i]);
        if (board->check4check(color)) {
            board->undo();
            possibleMoves.erase(possibleMoves.begin() + i);
        } else {
            ++i;
        }
        //board->undo();
    }*/

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
