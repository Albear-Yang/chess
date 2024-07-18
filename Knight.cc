#include "Knight.h"
using namespace std;

Knight::Knight(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::Knight) {}

vector<Move*> Knight::moves() {
    vector<Move*> possibleMoves;
    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    }
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  

    Position possiblePosition[8] = {Position(pos.x + 2, pos.y - 1), Position(pos.x + 2, pos.y + 1), Position(pos.x - 2, pos.y - 1), Position(pos.x - 2, pos.y + 1), Position(pos.x + 1, pos.y - 2), Position(pos.x - 1, pos.y - 2), Position(pos.x + 1, pos.y + 2), Position(pos.x - 1, pos.y + 2)};

    for(int i = 0; i < 8; i++){
        if(possiblePosition[i].inBoard()){
            bool posOccupied = false;
            Move *tempMove = nullptr;
            for(int z = 0; z < allPieces.size(); ++z){
                if(possiblePosition[i] == allPieces[z]->pos){
                    posOccupied = true;
                    if(allPieces[z]->color != color){
                        tempMove = new Move(this, board->blackPieces[z], pos, possiblePosition[i]);
                        possibleMoves.push_back(tempMove);
                    }
                }
            }
            if(posOccupied == false){
                tempMove = new Move(this, nullptr, pos, possiblePosition[i]);
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

void Knight::move(Position newpos){
    pos = newpos;
}

vector<Move*> Knight::canCapture(){
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    }
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  

    Position possiblePosition[8] = {Position(pos.x + 2, pos.y - 1), Position(pos.x + 2, pos.y + 1), Position(pos.x - 2, pos.y - 1), Position(pos.x - 2, pos.y + 1), Position(pos.x + 1, pos.y - 2), Position(pos.x - 1, pos.y - 2), Position(pos.x + 1, pos.y + 2), Position(pos.x - 1, pos.y + 2)};

    for(int i = 0; i < 8; i++){
        if(possiblePosition[i].inBoard()){
            bool posOccupied = false;
            Move *tempMove = nullptr;
            for(int z = 0; z < allPieces.size(); ++z){
                if(possiblePosition[i] == allPieces[z]->pos){
                    posOccupied = true;
                    if(allPieces[z]->color != color){
                        tempMove = new Move(this, board->blackPieces[z], pos, possiblePosition[i]);
                        possibleMoves.push_back(tempMove);
                    }
                }
            }
        }
    }


    return possibleMoves;
}