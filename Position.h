#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    int x;
    int y;

    bool operator==(const Position &other) const{
        return (other.x == x) && (other.y == y);
    };
    void tr(){
        x++;
        y++;
    }
    void tl(){
        x--;
        y--;
    }
    void br(){
        x++;
        y--;
    }
    void bl(){
        x--;
        y--;
    }
};

#endif
