#include "TextDisplay.h"

TextDisplay::TextDisplay(Board* subj): subj{subj} { subj->attach(this); }

void TextDisplay::notify() {
    for (int i = 0; i < subj->boardLength(); i++) {
        std::cout << (8 - i) << " ";
        for (int j = 0; j < subj->boardLength(); j++) {
            bool pass = true;
            for (auto p : subj->whitePieces) {
                char c;
                Type type = p->typeValue();
                if (p->positionXValue() == i && p->positionYValue() == j) {
                    char c;
                    if (p->typeValue() == Type::BISHOP) c = 'B';
                    else if (type == Type::KNIGHT) c = 'N';
                    else if (type == Type::PAWN) c = 'P';
                    else if (type == Type::ROOK) c = 'R';
                    else if (type == Type::QUEEN) c = 'Q';
                    else if (type == Type::KING) c = 'K';
                    std::cout << c;
                    pass = false;
                }
            }
            for (auto p : subj->blackPieces) {
                char c;
                Type type = p->typeValue();
                if (p->positionXValue() == i && p->positionYValue() == j) {
                    char c;
                    if (p->typeValue() == Type::BISHOP) c = 'b';
                    else if (type == Type::KNIGHT) c = 'n';
                    else if (type == Type::PAWN) c = 'p';
                    else if (type == Type::ROOK) c = 'r';
                    else if (type == Type::QUEEN) c = 'q';
                    else if (type == Type::KING) c = 'k';
                    std::cout << c;
                    pass = false;
                }
            }
            if (pass) {
                char c;
                if ((i + j) % 2 == 0) c = ' ';
                else c = '_';
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "  abcdefg" << std::endl;
}

TextDisplay::~TextDisplay() { subj->detach(this); }
