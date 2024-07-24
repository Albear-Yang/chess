#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Subject.h"
#include "Piece.h"
#include "Move.h"
#include "Queen.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"
#include "Rook.h"


class Board : public Subject {
    const int LEN_MAX = 8;
public: 
    std::vector<Piece*> startingWhitePieces; //add COPIES of the pieces at the beginning MUST BE COPIES
    std::vector<Piece*> startingBlackPieces;
    std::vector<Piece*> whitePieces;
    std::vector<Piece*> blackPieces;
    std::vector<Piece*> gone;
    float whiteScore = 0;
    float blackScore = 0;
    bool hasWhiteKing = false;
    bool hasBlackKing = false;
    bool round1 = true;
    bool setup = false;
    Position* enpassed = nullptr;
    Color whosTurn = Color::WHITE;
    std::vector<Move*> pastMoves;

    std::vector<Move*> whiteMoves(); 
    std::vector<Move*> blackMoves();
    std::vector<Move*> whiteMovesNoCastle(); 
    std::vector<Move*> blackMovesNoCastle();
    bool empty(int x, int y);
    bool check4checkMove(Color king, Move* move);
    bool draw();
    bool stalemate();
    bool checkmate();
    bool check4check(Color king);
    void addPiece(Piece* piece);
    void addPiece(Type type, Color color, int x, int y);
    void removePiece(Piece* piece);
    void removePiece(int x, int y);
    void undo();
    void addMove(Move* move);
    void undoMinMax();
    void addMoveMinMax(Move* move);
    int boardLength();
    void clear();
    ~Board();
};

#endif
