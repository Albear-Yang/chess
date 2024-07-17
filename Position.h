#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    int x_coord;
    int y_coord;

    bool operator==(const Position &other) const{
        return (other.x_coord == x_coord) && (other.y_coord == y_coord);
    };
};

#endif
