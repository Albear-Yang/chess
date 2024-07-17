#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Piece.h"
#include "Move.h"
#include "Subject.h"

class Board : public Subject {
    const int LEN_MAX = 8;
public: 
    std::vector<Piece*> starting_white_pieces; //add COPIES of the pieces at the beginning MUST BE COPIES
    std::vector<Piece*> starting_black_pieces;
    std::vector<Piece*> white_pieces;
    std::vector<Piece*> black_pieces;
    int whiteScore;
    int blackScore;
    Color whosTurn;
    std::vector<Move*> pastMoves;

    std::vector<Move*> whiteMoves(); 
    std::vector<Move*> blackMoves();
    bool draw();
    bool checkmate();
    bool check4check(Color king);
    void addPiece(Piece* piece);
    void removePiece(Piece* piece);
    void undo();
    void addMove(Move* move);
    int boardLength();
};

#endif
