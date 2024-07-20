#include "TextDisplay.h"

TextDisplay::TextDisplay(Board* subj): subj{subj} { subj->attach(this); }

void TextDisplay::notify() {
    /*for (auto p : subj->whitePieces) {
        char c;
        Type type = p->typeValue();
        if (type == Type::BISHOP) c = 'B';
        else if (type == Type::KNIGHT) c = 'N';
        else if (type == Type::PAWN) c = 'P';
        else if (type == Type::ROOK) c = 'R';
        else if (type == Type::QUEEN) c = 'Q';
        else if (type == Type::KING) c = 'K';
        std::cout << c << " White " << p->getPos().x << " " << p->getPos().y << std::endl;
    }
    for (auto p : subj->blackPieces) {
        char c;
        Type type = p->typeValue();
        if (type == Type::BISHOP) c = 'B';
        else if (type == Type::KNIGHT) c = 'N';
        else if (type == Type::PAWN) c = 'P';
        else if (type == Type::ROOK) c = 'R';
        else if (type == Type::QUEEN) c = 'Q';
        else if (type == Type::KING) c = 'K';
        std::cout << c << " Black " << p->getPos().x << " " << p->getPos().y << std::endl;
    }*/
    for (int i = 0; i < subj->boardLength(); i++) {
        std::cout << (8 - i) << " ";
        for (int j = 0; j < subj->boardLength(); j++) {
            bool pass = true;
            for (auto p : subj->whitePieces) {
                char c;
                Type type = p->typeValue();
                if (p->positionXValue() == i && p->positionYValue() == j) {
                    char c;
                    if (type == Type::BISHOP) c = 'B';
                    else if (type == Type::KNIGHT) c = 'N';
                    else if (type == Type::PAWN) c = 'P';
                    else if (type == Type::ROOK) c = 'R';
                    else if (type == Type::QUEEN) c = 'Q';
                    else if (type == Type::KING) c = 'K';
                    std::cout << c;
                    pass = false;
                    break;
                }
            }
            for (auto p : subj->blackPieces) {
                char c;
                Type type = p->typeValue();
                if (p->positionXValue() == i && p->positionYValue() == j) {
                    char c;
                    if (type == Type::BISHOP) c = 'b';
                    else if (type == Type::KNIGHT) c = 'n';
                    else if (type == Type::PAWN) c = 'p';
                    else if (type == Type::ROOK) c = 'r';
                    else if (type == Type::QUEEN) c = 'q';
                    else if (type == Type::KING) c = 'k';
                    std::cout << c;
                    pass = false;
                    break;
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
    std::cout << "  abcdefgh" << std::endl;
}

TextDisplay::~TextDisplay() { subj->detach(this); }
