#include "GraphicDisplay.h"

GraphicsDisplay::GraphicsDisplay(Board* subj): subj{subj} { subj->attach(this); }

void GraphicsDisplay::notify() {
    int boardLen = subj->boardLength();
    Xwindow w{50*(2 + boardLen), 50*(1 + boardLen)};
    for (int i = 0; i < boardLen; i++) {
        w.fillRectangle(50*i, 0, 100, 50, Xwindow::Green);
        w.drawString(50*i, 0, (8-i));
        for (int j = 0; j < boardLen; j++) {
            if ((i + j) % 2 == 0) c = w.fillRectangle(50*i, 50*(j+1), 50, 50, Xwindow::White);;
            else c = w.fillRectangle(50*i, 50*(j+1), 50, 50, Xwindow::Black);;
            for (auto p : subj->white_pieces) {
                char c;
                Type type = p->typeValue();
                if (p->positionXValue() == i && p->positionYValue() == j) {
                    char c;
                    if (p->typeValue() == Type::Bishop) c = 'B';
                    else if (type == Type::Knight) c = 'N';
                    else if (type == Type::Pawn) c = 'P';
                    else if (type == Type::Rook) c = 'R';
                    else if (type == Type::Queen) c = 'Q';
                    else if (type == Type::King) c = 'K';
                    w.drawString(50*i, 50*j, c);
                }
            }
        }
    }
    w.fillRectangle(50*boardLen, 0, 50*(2 + boardLen), 50, Xwindow::Green);
    for (int i = 0; i < boardLen; i++) {
        w.drawString(50*boardLen, 50*i, 'a' + i);
    }
}

GraphicsDisplay::~GraphicsDisplay() { subj->detach(this); }
