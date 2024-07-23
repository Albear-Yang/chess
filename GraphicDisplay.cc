/*
#include "GraphicDisplay.h"
#include <string>

GraphicsDisplay::GraphicsDisplay(Board* subj, Xwindow* w): subj{subj}, w{w} { subj->attach(this); }

void GraphicsDisplay::notify() {
    int boardLen = subj->boardLength();
    if (subj->round1) {
        for (int i = 0; i < boardLen; i++) {
            //w->fillRectangle(0, 50*i, 100, 50, Xwindow::Green);
            w->drawString(23, 50*i+25, std::to_string(8-i));
            for (int j = 0; j < boardLen; j++) {
                if ((i + j) % 2 == 0) w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::White);
                else w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::Green);;
                for (auto p : subj->whitePieces) {
                    std::string c;
                    Type type = p->typeValue();
                    if (p->positionXValue() == i && p->positionYValue() == j) {
                        if (p->typeValue() == Type::BISHOP) c = "B";
                        else if (type == Type::KNIGHT) c = "N";
                        else if (type == Type::PAWN) c = "P";
                        else if (type == Type::ROOK) c = "R";
                        else if (type == Type::QUEEN) c = "Q";
                        else if (type == Type::KING) c = "K";
                        w->drawString(50*(j+2)+23, 50*i+25, c);
                    }
                }
                for (auto p : subj->blackPieces) {
                    std::string c;
                    Type type = p->typeValue();
                    if (p->positionXValue() == i && p->positionYValue() == j) {
                        if (p->typeValue() == Type::BISHOP) c = "b";
                        else if (type == Type::KNIGHT) c = "n";
                        else if (type == Type::PAWN) c = "p";
                        else if (type == Type::ROOK) c = "r";
                        else if (type == Type::QUEEN) c = "q";
                        else if (type == Type::KING) c = "k";
                        w->drawString(50*(j+2)+23, 50*i+25, c);
                    }
                }
            }
        }
        //w->fillRectangle(0, 50*(boardLen), 50*(2 + boardLen), 50, Xwindow::Green);
        for (int i = 0; i < boardLen; i++) {
            char c = ('a' + i);
            w->drawString(50*(i + 2)+23, 50*boardLen+25, std::string(1, c));
        }
    }
    else {
        char c;
        Move* m = subj->pastMoves.back();
        Type type = m->pieceMoved()->typeValue();
        Color color = m->pieceMoved()->getColor();
        if (color == Color::BLACK) {
            if (type == Type::BISHOP) c = 'b';
            else if (type == Type::KNIGHT) c = 'n';
            else if (type == Type::PAWN) c = 'p';
            else if (type == Type::ROOK) c = 'r';
            else if (type == Type::QUEEN) c = 'q';
            else if (type == Type::KING) c = 'k';
        }
        else {
            if (type == Type::BISHOP) c = 'B';
            else if (type == Type::KNIGHT) c = 'N';
            else if (type == Type::PAWN) c = 'P';
            else if (type == Type::ROOK) c = 'R';
            else if (type == Type::QUEEN) c = 'Q';
            else if (type == Type::KING) c = 'K';
        }
        int i = m->initPos().x; int j = m->initPos().y;
        if ((i + j) % 2 == 0) w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::White);
        else w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::Green);
        i = m->finPos().x; j = m->finPos().y;
        if ((i + j) % 2 == 0) w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::White);
        else w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::Green);
        w->drawString(50*(j+2)+23, 50*i+25, std::string(1, c));
        if (subj->enpassed != nullptr) {
            i = subj->enpassed->x; j = subj->enpassed->y;
            if ((i + j) % 2 == 0) w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::White);
            else w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::Green);
        }
        if (subj->pastMoves.size() >= 2) {
            m = subj->pastMoves[subj->pastMoves.size() - 2];
            if (m->castle != nullptr) {
                char c;
                Type type = m->pieceMoved()->typeValue();
                Color color = m->pieceMoved()->getColor();
                if (color == Color::BLACK) {
                    c = 'k';
                }
                else {
                    c = 'K';
                }
                int i = m->initPos().x; int j = m->initPos().y;
                if ((i + j) % 2 == 0) w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::White);
                else w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::Green);
                i = m->finPos().x; j = m->finPos().y;
                if ((i + j) % 2 == 0) w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::White);
                else w->fillRectangle(50*(j+2), 50*i, 50, 50, Xwindow::Green);
                w->drawString(50*(j+2)+23, 50*i+25, std::string(1, c));
            }
        }
    }
}

GraphicsDisplay::~GraphicsDisplay() { subj->detach(this); }
*/