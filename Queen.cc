#include "Queen.h"
using namespace std;

Queen::Queen(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::QUEEN) {}

vector<Move*> Queen::moves(){
    enpassable = nullptr;
    vector<Move*> possibleMoves;
    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  
    //remember to remove
    //checking right direction
    for(int i = pos.x + 1; i < 8; ++i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(i, pos.y);
        bool validMove = true;
        bool noPieceBetween = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
    }

    // checking left direction
    for(int i = pos.x - 1; i >= 0; --i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(i, pos.y);
        bool validMove = true;
        bool noPieceBetween = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
    }
    //check for down
    for(int i = pos.y - 1; i >= 0; --i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(pos.x, i);
        bool noPieceBetween = true;
        bool validMove = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
    }
    //check for up
    for(int i = pos.y + 1; i < 8; ++i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(pos.x, i);
        bool validMove = true;
        bool noPieceBetween = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos.x + 1, y = pos.y + 1; x < 8 && y < 8; x++, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos.x && y == allPieces[z]->pos.y){
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
                    tempMove = new Move(this, pc, pos, *new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, *new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos.x - 1, y = pos.y - 1; x >= 0 && y >= 0; x--, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos.x && y == allPieces[z]->pos.y){
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
                    tempMove = new Move(this, pc, pos, *new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, *new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos.x + 1, y = pos.y - 1; x < 8 && y >= 0; x++, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos.x && y == allPieces[z]->pos.y){
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
                    tempMove = new Move(this, pc, pos, *new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, *new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos.x - 1, y = pos.y + 1; x >= 0 && y < 8; x--, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos.x && y == allPieces[z]->pos.y){
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
                    tempMove = new Move(this, pc, pos, *new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, *new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    /*for(Position i = Position(pos.x + 1, pos.y + 1); pos.x < 8 && pos.y < 8; i.tr()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, i);
        possibleMoves.push_back(tempMove);
    }
    for(Position i = Position(pos.x - 1, pos.y - 1); pos.x >= 0 && pos.y >=0; i.bl()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, i);
        possibleMoves.push_back(tempMove);
    }
    for(Position i = Position(pos.x + 1, pos.y - 1); pos.x < 8 && pos.y >=0; i.br()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, i);
        possibleMoves.push_back(tempMove);
    }
    for(Position i = Position(pos.x - 1, pos.y + 1); pos.x >= 0 && pos.y < 8; i.tl()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = false;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, i);
        possibleMoves.push_back(tempMove);
    }*/
    for(auto i = possibleMoves.begin(); i != possibleMoves.end();){
        if (board->check4checkMove(color, *i)) {
            possibleMoves.erase(i);
        }
        else{
            i++;
        }
    }
    //
    return possibleMoves;
}

std::vector<Move*> Queen::movesNoCheck(){
    vector<Move*> possibleMoves;
    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  
    //remember to remove
    //checking right direction
    for(int i = pos.x + 1; i < 8; ++i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(i, pos.y);
        bool validMove = true;
        bool noPieceBetween = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
    }

    // checking left direction
    for(int i = pos.x - 1; i >= 0; --i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(i, pos.y);
        bool validMove = true;
        bool noPieceBetween = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
    }
    //check for down
    for(int i = pos.y - 1; i >= 0; --i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(pos.x, i);
        bool noPieceBetween = true;
        bool validMove = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
    }
    //check for up
    for(int i = pos.y + 1; i < 8; ++i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(pos.x, i);
        bool validMove = true;
        bool noPieceBetween = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                noPieceBetween = false;
                if(allPieces[z]->color != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc == nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos.x + 1, y = pos.y + 1; x < 8 && y < 8; x++, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos.x && y == allPieces[z]->pos.y){
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
                    tempMove = new Move(this, pc, pos, *new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, *new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos.x - 1, y = pos.y - 1; x >= 0 && y >= 0; x--, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos.x && y == allPieces[z]->pos.y){
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
                    tempMove = new Move(this, pc, pos, *new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, *new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos.x + 1, y = pos.y - 1; x < 8 && y >= 0; x++, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos.x && y == allPieces[z]->pos.y){
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
                    tempMove = new Move(this, pc, pos, *new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, *new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos.x - 1, y = pos.y + 1; x >= 0 && y < 8; x--, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->pos.x && y == allPieces[z]->pos.y){
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
                    tempMove = new Move(this, pc, pos, *new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, pos, *new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    return possibleMoves;
}

void Queen::move(Position newpos){
    pos = newpos;
}

vector<Move*> Queen::canCapture(){
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  

    //checking right direction
    for(int i = pos.x; i < 8; ++i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(i, pos.y);
        bool validMove = true;
        bool noPieceBetween = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }

    // checking left direction
    for(int i = pos.x; i >= 0; --i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(i, pos.y);
        bool validMove = true;
        bool noPieceBetween = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }
    //check for down
    for(int i = pos.y; i >= 0; --i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(pos.x, i);
        bool noPieceBetween = true;
        bool validMove = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }
    //check for up
    for(int i = pos.y; i < 8; ++i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(pos.x, i);
        bool validMove = true;
        bool noPieceBetween = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], pos, temp);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }
    for(Position i = Position(pos.x, pos.y); pos.x < 8 && pos.y < 8; i.tr()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = false;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], pos, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }
    for(Position i = Position(pos.x, pos.y); pos.x >= 0 && pos.y >=0; i.bl()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = false;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], pos, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }
    for(Position i = Position(pos.x, pos.y); pos.x < 8 && pos.y >=0; i.br()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = false;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], pos, i);
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
    }
    for(Position i = Position(pos.x, pos.y); pos.x >= 0 && pos.y < 8; i.tl()){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = false;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->pos){
                if(allPieces[z]->color != color){
                    noPieceBetween = false;
                    tempMove = new Move(this, board->blackPieces[z], pos, i);
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
}

