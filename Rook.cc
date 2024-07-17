#include "rook.h"
using namespace std;

Rook::Rook(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::Rook) {}

vector<Move*> Rook::moves(Position pos) const {
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board.blackPieces.size(); ++z){
        allPieces.pushback(blackPieces[z]);
    } 
    for(int z = 0; z < board.whitePieces.size(); ++z){
        allPieces.pushback(whitePieces[z]);
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
            if(temp == board->allPieces[z]->pos){
                if(board->allPieces->color != color){
                    noPieceBetween = false;
                    *tempMove = new Move(*this, board->blackPieces[z], pos, temp);
                    possibleMoves.pushback(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(*this, nullptr, pos, temp);
        possibleMoves.pushback(tempMove);
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
            if(temp == board->allPieces[z]->pos){
                if(board->allPieces->color != color){
                    noPieceBetween = false;
                    *tempMove = new Move(*this, board->blackPieces[z], pos, temp);
                    possibleMoves.pushback(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(*this, nullptr, pos, temp);
        possibleMoves.pushback(tempMove);
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
            if(temp == board->allPieces[z]->pos){
                if(board->allPieces->color != color){
                    noPieceBetween = false;
                    *tempMove = new Move(*this, board->blackPieces[z], pos, temp);
                    possibleMoves.pushback(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(*this, nullptr, pos, temp);
        possibleMoves.pushback(tempMove);
    }
    for(int i = pos.y; i <= 8; ++i){
        //black
        Piece* capturablePiece = nullptr;
        Position temp = Position(pos.x, i);
        bool validMove = true;
        bool noPieceBetween = true;

        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(temp == board->allPieces[z]->pos){
                if(board->allPieces->color != color){
                    noPieceBetween = false;
                    *tempMove = new Move(*this, board->blackPieces[z], pos, temp);
                    possibleMoves.pushback(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(*this, nullptr, pos, temp);
        possibleMoves.pushback(tempMove);
    }
    for(int i = 0; i < possibleMoves.size();){
        board->addMove(possibleMoves[i]);
        if(board->check4check(color)){
            possibleMoves.erase[i];
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
    for(int z = 0; z < board.blackPieces.size(); ++z){
        allPieces.pushback(blackPieces[z]);
    } 
    for(int z = 0; z < board.whitePieces.size(); ++z){
        allPieces.pushback(whitePieces[z]);
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
            if(temp == board->allPieces[z]->pos){
                if(board->allPieces->color != color){
                    noPieceBetween = false;
                    *tempMove = new Move(*this, board->blackPieces[z], pos, temp);
                    possibleMoves.pushback(tempMove);
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
            if(temp == board->allPieces[z]->pos){
                if(board->allPieces->color != color){
                    noPieceBetween = false;
                    *tempMove = new Move(*this, board->blackPieces[z], pos, temp);
                    possibleMoves.pushback(tempMove);
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
            if(temp == board->allPieces[z]->pos){
                if(board->allPieces->color != color){
                    noPieceBetween = false;
                    *tempMove = new Move(*this, board->blackPieces[z], pos, temp);
                    possibleMoves.pushback(tempMove);
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
            if(temp == board->allPieces[z]->pos){
                if(board->allPieces->color != color){
                    noPieceBetween = false;
                    *tempMove = new Move(*this, board->blackPieces[z], pos, temp);
                    possibleMoves.pushback(tempMove);
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