#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "Board.h"
#include "Observer.h"


class TextDisplay : public Observer {
    Board* subj;
public:
    TextDisplay(Board* subj);
    void notify() override;
    ~TextDisplay();
};

#endif