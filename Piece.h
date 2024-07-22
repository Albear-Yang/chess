#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Board.h"
#include "Position.h"
#include "Move.h"
#include "Enums.h"

class Board;
class Move;

class Piece {
    protected:
        Board *board;
        const Type type;
        //const int value; NEED TO MAKE ALL THE PIECES ADD THE VALUE TO THE CTOR! CHANGE ALL CTORS
    public:
        Color color;
        Position pos;
        bool has_moved = false;
        Position* enpassable;
        Piece(Board* board, Position pos, Color color, Type type): board{board}, pos{pos}, color{color}, type{type} {}
        //Piece(const Piece& other): board{other.board}, pos{other.pos}, color{other.color}, type{type} {}
        ~Piece() = default;
        virtual std::vector<Move*> moves() = 0;
        virtual void move(Position pos) = 0;
        virtual std::vector<Move*> canCapture() = 0;
        virtual std::vector<Move*> movesNoCheck() = 0;
        //virtual int positionValue() = 0; NEED AN OVERIDE IN ALL PIECE SUBCLASSES
        int positionXValue() { return pos.x; };
        int positionYValue() { return pos.y; };
        Position getPos() { return pos; };
        Type typeValue() { return type; };
        Color getColor() { return color; };
        void movePos(int x, int y) { pos.x = x; pos.y = y; };


};

#endif
