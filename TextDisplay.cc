#include "TextDisplay.h"

TextDisplay::TextDisplay(Board* subj): subj{subj} { subj->attach(this); }

void TextDisplay::notify() {
    for (int i = 0; i < subj->boardLength(); i++) {
        std::cout << (8 - i) << " ";
        for (int j = 0; j < subj->boardLength(); j++) {
            for (auto p : subj->white_pieces) {
                if (p->positionXValue() == i && p->positionYValue() == j) {
                    char c;
                    if (p->typeValue() == Type::Bishop) c = 'B';
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << "  abcdefg" << std::endl;
}