#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "Observer.h"
#include "Xwindow.h"

class GraphicsDisplay : public Observer {
public:
    void notify(Subject* subject) override;
};

#endif 