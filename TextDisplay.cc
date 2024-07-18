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
                    if (p->typeValue() == Type::Bishop) c = 'B';
                    else if (type == Type::Knight) c = 'N';
                    else if (type == Type::Pawn) c = 'P';
                    else if (type == Type::Rook) c = 'R';
                    else if (type == Type::Queen) c = 'Q';
                    else if (type == Type::King) c = 'K';
                    std::cout << c;
                    pass = false;
                }
            }
            for (auto p : subj->blackPieces) {
                char c;
                Type type = p->typeValue();
                if (p->positionXValue() == i && p->positionYValue() == j) {
                    char c;
                    if (p->typeValue() == Type::Bishop) c = 'b';
                    else if (type == Type::Knight) c = 'n';
                    else if (type == Type::Pawn) c = 'p';
                    else if (type == Type::Rook) c = 'r';
                    else if (type == Type::Queen) c = 'q';
                    else if (type == Type::King) c = 'k';
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
