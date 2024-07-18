#include "Knight.h"
using namespace std;

Knight::Knight(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::Knight) {}

vector<Move*> Knight::moves(Position pos) const {
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
        if(possiblePosition[i].inBoard()){
            bool posOccupied = false;
            Position *tempMove = nullptr;
            for(int z = 0; z < allPieces.size(); ++z){
                if(possiblePosition[i] == board->allPieces[z]->pos){
                    posOccupied = true;
                    if(board->allPieces->color != color){
                        tempMove = new Move(*this, board->blackPieces[z], pos, tempPos);
                        possibleMoves.pushback(tempMove);
                    }
                }
            }
            if(posOccupied == false){
                tempMove = newMove(*this, nullptr, pos, tempPos);
                possibleMoves.pushback(tempMove);
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
    has_moved = 
    pos = newpos;
}

vector<Move*> Knight::canCapture(){
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
        if(possiblePosition[i].inBoard()){
            bool posOccupied = false;
            Position *tempMove = nullptr;
            for(int z = 0; z < allPieces.size(); ++z){
                if(possiblePosition[i] == board->allPieces[z]->pos){
                    posOccupied = true;
                    if(board->allPieces->color != color){
                        tempMove = new Move(*this, board->blackPieces[z], pos, tempPos);
                        possibleMoves.pushback(tempMove);
                    }
                }
            }
        }
    }


    return possibleMoves;
}