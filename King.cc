#include "King.h"
using namespace std;

King::King(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::KING) {}

vector<Move*> King::moves(){
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  

    for(int x = -1; x < 2; x++){
        for(int y = -1; y < 2; y++){
            if(x == 0 && y == 0){
                continue;
            }
            if(pos.x + x <= 8 && pos.x + x >= 0 && pos.y + y <= 8 && pos.y + y <= 8){
                Position tempPos = Position(pos.x + x, pos.y + y);

                for(int z = 0; z < allPieces.size(); ++z){
                    Move *tempMove = nullptr;
                    if(tempPos == allPieces[z]->pos){
                        if(allPieces[z]->color != color){
                            tempMove = new Move(this, board->blackPieces[z], pos, tempPos);
                            possibleMoves.push_back(tempMove);
                        }
                    }
                }
                Move *tempMove = new Move(this, nullptr, pos, tempPos);
                possibleMoves.push_back(tempMove);
            }
        }
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

void King::move(Position newpos){
    has_moved = true;
    pos = newpos;
}

vector<Move*> King::canCapture(){
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  

    for(int x = -1; x < 2; x++){
        for(int y = -1; y < 2; y++){
            if(pos.x + x <= 8 && pos.x + x >= 0 && pos.y + y <= 8 && pos.y + y <= 8){
                Position tempPos = Position(pos.x + x, pos.y + y);
                
                for(int z = 0; z < allPieces.size(); ++z){
                    Move *tempMove = nullptr;
                    if(tempPos == allPieces[z]->pos){
                        if(allPieces[z]->color != color){
                            tempMove = new Move(this, board->blackPieces[z], pos, tempPos);
                            possibleMoves.push_back(tempMove);
                        }
                    }
                }
            }
        }
    }
    return possibleMoves;
}