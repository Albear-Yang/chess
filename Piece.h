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
        Color color;
        Position* pos;
    public:
        bool has_moved = false;
        Position* enpassable = nullptr;
        Piece(Board* board, Position* pos, Color color, Type type): board{board}, pos{pos}, color{color}, type{type} {}
        virtual ~Piece() { delete pos; if (enpassable != nullptr) delete enpassable; };
        virtual std::vector<Move*> moves() = 0;
        virtual std::vector<Move*> movesNoCheck() = 0;
        int positionXValue() { return pos->x; };
        int positionYValue() { return pos->y; };
        Position* getPos() { return pos; };
        Type typeValue() { return type; };
        Color getColor() { return color; };
        void movePos(int x, int y) { pos->x = x; pos->y = y; };
};
#endif
