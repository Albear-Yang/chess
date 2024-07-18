/*#include "GraphicDisplay.h"

GraphicsDisplay::GraphicsDisplay(Board* subj): subj{subj} { subj->attach(this); }

void GraphicsDisplay::notify() {
    int boardLen = subj->boardLength();
    Xwindow w{50*(2 + boardLen), 50*(1 + boardLen)};
    if (subj->round1) {
        for (int i = 0; i < boardLen; i++) {
            w.fillRectangle(50*i, 0, 100, 50, Xwindow::Green);
            w.drawString(50*i, 0, std::to_string(8-i));
            for (int j = 0; j < boardLen; j++) {
                if ((i + j) % 2 == 0) w.fillRectangle(50*i, 50*(j+2), 50, 50, Xwindow::White);
                else w.fillRectangle(50*i, 50*(j+2), 50, 50, Xwindow::Black);;
                for (auto p : subj->whitePieces) {
                    char c;
                    Type type = p->typeValue();
                    if (p->positionXValue() == i && p->positionYValue() == j) {
                        if (p->typeValue() == Type::BISHOP) c = 'B';
                        else if (type == Type::KNIGHT) c = 'N';
                        else if (type == Type::PAWN) c = 'P';
                        else if (type == Type::ROOK) c = 'R';
                        else if (type == Type::QUEEN) c = 'Q';
                        else if (type == Type::KING) c = 'K';
                        w.drawString(50*i, 50*(j+2), std::to_string(c));
                    }
                }
                for (auto p : subj->blackPieces) {
                    char c;
                    Type type = p->typeValue();
                    if (p->positionXValue() == i && p->positionYValue() == j) {
                        if (p->typeValue() == Type::BISHOP) c = 'b';
                        else if (type == Type::KNIGHT) c = 'n';
                        else if (type == Type::PAWN) c = 'p';
                        else if (type == Type::ROOK) c = 'r';
                        else if (type == Type::QUEEN) c = 'q';
                        else if (type == Type::KING) c = 'k';
                        w.drawString(50*i, 50*(j+2), std::to_string(c));
                    }
                }
            }
        }
        w.fillRectangle(50*boardLen, 0, 50*(2 + boardLen), 50, Xwindow::Green);
        for (int i = 0; i < boardLen; i++) {
            char c = ('a' + i);
            w.drawString(50*boardLen, 50*i, std::to_string(c));
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
        if ((i + j) % 2 == 0) w.fillRectangle(50*i, 50*(j+2), 50, 50, Xwindow::White);
        else w.fillRectangle(50*i, 50*(j+2), 50, 50, Xwindow::Black);
        i = m->finPos().x; j = m->finPos().y;
        if ((i + j) % 2 == 0) w.fillRectangle(50*i, 50*(j+2), 50, 50, Xwindow::White);
        else w.fillRectangle(50*i, 50*(j+2), 50, 50, Xwindow::Black);
        w.drawString(50*i, 50*(j+2), std::to_string(c));
    }
}

GraphicsDisplay::~GraphicsDisplay() { subj->detach(this); }
*/