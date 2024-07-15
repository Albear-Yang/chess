#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "Observer.h"

class TextDisplay : public Observer {
public:
    void notify(Subject* subject) override;
};

#endif