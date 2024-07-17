#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include "Board.h"
#include "Observer.h"
#include "Xwindow.h"

class GraphicsDisplay : public Observer {
    Board* subj;
public:
    GraphicsDisplay(Board* subj);
    void notify() override;
    ~GraphicsDisplay();
};

#endif 