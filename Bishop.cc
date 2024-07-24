#include "Bishop.h"
using namespace std;

Bishop::Bishop(Board* board, Position* pos, Color color)
    : Piece(board, pos, color, Type::BISHOP) {}

vector<Move*> Bishop::moves(){
    enpassable = nullptr;
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  
    //for(Position i = Position(pos->x + 1, pos->y + 1); i.x < 8 && i.y < 8; i.tr()){
    for(int x = pos->x + 1, y = pos->y + 1; x < 8 && y < 8; x++, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos->x && y == allPieces[z]->pos->y){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x - 1, y = pos->y - 1; x >= 0 && y >= 0; x--, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos->x && y == allPieces[z]->pos->y){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x + 1, y = pos->y - 1; x < 8 && y >= 0; x++, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos->x && y == allPieces[z]->pos->y){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x - 1, y = pos->y + 1; x >= 0 && y < 8; x--, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos->x && y == allPieces[z]->pos->y){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(auto i = possibleMoves.begin(); i != possibleMoves.end();){
        if (board->check4checkMove(color, *i)) {
            delete *i;
            possibleMoves.erase(i);
        }
        else{
            i++;
        }
    }
    return possibleMoves;
}

std::vector<Move*> Bishop::movesNoCheck() {
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  
    //for(Position i = Position(pos->x + 1, pos->y + 1); i.x < 8 && i.y < 8; i.tr()){
    for(int x = pos->x + 1, y = pos->y + 1; x < 8 && y < 8; x++, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos->x && y == allPieces[z]->pos->y){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x - 1, y = pos->y - 1; x >= 0 && y >= 0; x--, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos->x && y == allPieces[z]->pos->y){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x + 1, y = pos->y - 1; x < 8 && y >= 0; x++, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos->x && y == allPieces[z]->pos->y){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x - 1, y = pos->y + 1; x >= 0 && y < 8; x--, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos->x && y == allPieces[z]->pos->y){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    return possibleMoves;
}

/*void Bishop::move(Position newpos){
    pos = newpos;
}

vector<Move*> Bishop::canCapture(){
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  
       for(Position i = Position(pos->x, pos->y); pos->x <= 8 && pos->y <= 8; i.tr()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = false;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], new Position{pos->x, pos->y}, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }
    for(Position i = Position(pos->x, pos->y); pos->x >= 0 && pos->y >=0; i.bl()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = false;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], new Position{pos->x, pos->y}, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }
    for(Position i = Position(pos->x, pos->y); pos->x <= 8 && pos->y >=0; i.br()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = false;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], new Position{pos->x, pos->y}, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }
    for(Position i = Position(pos->x, pos->y); pos->x >= 0 && pos->y <= 8; i.tl()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = false;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], new Position{pos->x, pos->y}, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }
    return possibleMoves;
}*/
