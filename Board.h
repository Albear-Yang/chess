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
    std::vector<Piece*> white_pieces;
    std::vector<Piece*> black_pieces;
    int whiteScore;
    int blackScore;
    Color whosTurn;
    std::vector<Move*> pastMoves; //call notifyObservers()

    std::vector<Move*> whiteMoves(); 
    std::vector<Move*> blackMoves();
    bool draw();
    bool checkmate();
    void addPiece(Piece* piece, Color color, int x, int y);
    void removePiece(Piece* piece, Color color, int x, int y);
    void undo();
    void addMove(Move move);
    void display();
    int boardLength();
};

#endif
