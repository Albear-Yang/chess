#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    int x_coord;
    int y_coord;

    bool operator==(const Position &other) const{
        return (other.x == x) && (other.y == y);
    };
};

#endif
