#include "rook.h"
#include "Rook.h"
#include "Piece.h"
using namespace std;

Rook::Rook(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::Rook) {}

vector<Move*> Rook::moves(){
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  

    //checking right direction
    for(int i = pos.x; i <= 8; ++i){
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
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
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
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
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
        Move *tempMove = new Move(this, nullptr, pos, temp);
        possibleMoves.push_back(tempMove);
    }
    //check for up
    for(int i = pos.y; i <= 8; ++i){
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
        Move *tempMove = new Move(this, nullptr, pos, temp);
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

void Rook::move(Position newpos){
    pos = newpos;
}

vector<Move*> Rook::canCapture(){
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  

    //checking right direction
    for(int i = pos.x; i <= 8; ++i){
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
    for(int i = pos.y; i <= 8; ++i){
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
    //
    return possibleMoves;
}