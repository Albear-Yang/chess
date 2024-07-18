#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Piece.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"
#include "Rook.h"
#include "Move.h"
#include "Subject.h"

class Board : public Subject {
    const int LEN_MAX = 8;
public: 
    std::vector<Piece*> startingWhitePieces; //add COPIES of the pieces at the beginning MUST BE COPIES
    std::vector<Piece*> startingBlackPieces;
    std::vector<Piece*> whitePieces;
    std::vector<Piece*> blackPieces;
    int whiteScore = 0;
    int blackScore = 0;
    bool hasWhiteKing = false;
    bool hasBlackKing = false;
    bool round1;
    Color whosTurn;
    std::vector<Move*> pastMoves;

    std::vector<Move*> whiteMoves(); 
    std::vector<Move*> blackMoves();
    bool draw();
    bool checkmate();
    bool check4check(Color king);
    void addPiece(Piece* piece);
    void addPiece(Type type, Color color, int x, int y);
    void removePiece(Piece* piece);
    void removePiece(int x, int y);
    void undo();
    void addMove(Move* move);
    int boardLength();
};

#endif
