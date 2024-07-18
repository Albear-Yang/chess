#include "Bishop.h"
#include "Move.h"
using namespace std;

Bishop::Bishop(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::Bishop) {}

vector<Move*> Bishop::moves(){
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  

    for(Position i = Position(pos.x, pos.y); pos.x <= 8 && pos.y <= 8; i.tr()){
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
        Move *tempMove = new Move(this, nullptr, pos, i);
        possibleMoves.push_back(tempMove);
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
        Move *tempMove = new Move(this, nullptr, pos, i);
        possibleMoves.push_back(tempMove);
    }
    for(Position i = Position(pos.x, pos.y); pos.x <= 8 && pos.y >=0; i.br()){
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
        Move *tempMove = new Move(this, nullptr, pos, i);
        possibleMoves.push_back(tempMove);
    }
    for(Position i = Position(pos.x, pos.y); pos.x >= 0 && pos.y <= 8; i.tl()){
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
        Move *tempMove = new Move(this, nullptr, pos, i);
        possibleMoves.push_back(tempMove);
    }
    for(int i = 0; i < possibleMoves.size();){
        board->addMove(possibleMoves[i]);
        if(board->check4check(color)){
            possibleMoves.erase(possibleMoves.begin() + i);
        }
        else{
            i++;
        }
        board->undo();
    }
    //
    return possibleMoves;
}

void Bishop::move(Position newpos){
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
       for(Position i = Position(pos.x, pos.y); pos.x <= 8 && pos.y <= 8; i.tr()){
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
    for(Position i = Position(pos.x, pos.y); pos.x <= 8 && pos.y >=0; i.br()){
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
    for(Position i = Position(pos.x, pos.y); pos.x >= 0 && pos.y <= 8; i.tl()){
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