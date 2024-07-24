#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    int x;
    int y;
    Position(int x, int y): x{x}, y{y}{}
    bool operator==(const Position* &other) const{
        return (other->x == x) && (other->y == y);
    };
    bool operator==(const Position &other) const{
        return (other.x == x) && (other.y == y);
    };
    void tr(){
        x++;
        y++;
    }
    void tl(){
        x--;
        y++;
    }
    void br(){
        x++;
        y--;
    }
    void bl(){
        x--;
        y--;
    }
    bool inBoard(){
        return(x < 8 && x >= 0 && y < 8 && y >= 0);
    }
};

#endif
