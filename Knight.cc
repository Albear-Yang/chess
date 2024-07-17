#include "King.h"
using namespace std;

King::King(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::King) {}

vector<Move*> King::moves(Position pos) const {
    vector<Move*> possibleMoves;
    vector<Piece*> allPieces;
    for(int z = 0; z < board.blackPieces.size(); ++z){
        allPieces.pushback(blackPieces[z]);
    } 
    for(int z = 0; z < board.whitePieces.size(); ++z){
        allPieces.pushback(whitePieces[z]);
    }  

    Position possiblePosition[8] = {Position(pos.x + 2, pos.y - 1), Position(pos.x + 2, pos.y + 1), Position(pos.x - 2, pos.y - 1), Position(pos.x - 2, pos.y + 1), Position(pos.x + 1, pos.y - 2), Position(pos.x - 1, pos.y - 2), Position(pos.x + 1, pos.y + 2), Position(pos.x - 1, pos.y + 2)};

    for(int i = 0; i < 8; i++){
        if(possiblePosition[i].x >= 0 && possiblePosition[i].x <= 8)
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
    has_moved = 
    pos = newpos;
}

vector<Move*> King::canCapture(){
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board.blackPieces.size(); ++z){
        allPieces.pushback(blackPieces[z]);
    } 
    for(int z = 0; z < board.whitePieces.size(); ++z){
        allPieces.pushback(whitePieces[z]);
    }  


    return possibleMoves;
}