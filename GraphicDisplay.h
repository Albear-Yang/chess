/*
#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include "Board.h"
#include "Observer.h"
#include "window.h"

class GraphicsDisplay : public Observer
{
    Board *subj;
    Xwindow *w;
public:
    GraphicsDisplay(Board *subj, Xwindow *w);
    void notify() override;
    ~GraphicsDisplay();
};

#endif*/
