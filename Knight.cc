#include "Knight.h"
using namespace std;

Knight::Knight(Board* board, Position* pos, Color color)
    : Piece(board, pos, color, Type::KNIGHT) {}

vector<Move*> Knight::moves() {
    enpassable = nullptr;
    vector<Move*> possibleMoves;
    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    }
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    } 
    Position* possiblePosition[8] = {new Position(pos->x + 2, pos->y - 1), new Position(pos->x + 2, pos->y + 1), new Position(pos->x - 2, pos->y - 1), new Position(pos->x - 2, pos->y + 1), new Position(pos->x + 1, pos->y - 2), new Position(pos->x - 1, pos->y - 2), new Position(pos->x + 1, pos->y + 2), new Position(pos->x - 1, pos->y + 2)};

    for(int i = 0; i < 8; i++){
        if(possiblePosition[i]->inBoard()){
            bool posOccupied = false;
            Move *tempMove = nullptr;
            for(int z = 0; z < allPieces.size(); ++z){
                if(possiblePosition[i]->x == allPieces[z]->pos->x && possiblePosition[i]->y == allPieces[z]->pos->y){
                    posOccupied = true;
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
                        tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(possiblePosition[i]->x, possiblePosition[i]->y));
                        possibleMoves.push_back(tempMove);
                    }
                }
            }
            if(posOccupied == false){
                tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(possiblePosition[i]->x, possiblePosition[i]->y));
                possibleMoves.push_back(tempMove);
            }
        }
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
    for (auto p : possiblePosition) {
        delete p;
    }
    return possibleMoves;
}

std::vector<Move*> Knight::movesNoCheck() {
    vector<Move*> possibleMoves;
    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    }
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    } 
    Position* possiblePosition[8] = {new Position(pos->x + 2, pos->y - 1), new Position(pos->x + 2, pos->y + 1), new Position(pos->x - 2, pos->y - 1), new Position(pos->x - 2, pos->y + 1), new Position(pos->x + 1, pos->y - 2), new Position(pos->x - 1, pos->y - 2), new Position(pos->x + 1, pos->y + 2), new Position(pos->x - 1, pos->y + 2)};

    for(int i = 0; i < 8; i++){
        if(possiblePosition[i]->inBoard()){
            bool posOccupied = false;
            Move *tempMove = nullptr;
            for(int z = 0; z < allPieces.size(); ++z){
                if(possiblePosition[i] == allPieces[z]->pos){
                    posOccupied = true;
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
                        tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(possiblePosition[i]->x, possiblePosition[i]->y));
                        possibleMoves.push_back(tempMove);
                    }
                }
            }
            if(posOccupied == false){
                tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(possiblePosition[i]->x, possiblePosition[i]->y));
                possibleMoves.push_back(tempMove);
            }
        }
    }
    for (auto p : possiblePosition) {
        delete p;
    }
    return possibleMoves;
}

/*void Knight::move(Position newpos){
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

    Position possiblePosition[8] = {Position(pos->x + 2, pos->y - 1), Position(pos->x + 2, pos->y + 1), Position(pos->x - 2, pos->y - 1), Position(pos->x - 2, pos->y + 1), Position(pos->x + 1, pos->y - 2), Position(pos->x - 1, pos->y - 2), Position(pos->x + 1, pos->y + 2), Position(pos->x - 1, pos->y + 2)};

    for(int i = 0; i < 8; i++){
        if(possiblePosition[i].inBoard()){
            bool posOccupied = false;
            Move *tempMove = nullptr;
            for(int z = 0; z < allPieces.size(); ++z){
                if(possiblePosition[i] == allPieces[z]->pos){
                    posOccupied = true;
                    if(allPieces[z]->color != color){
                        tempMove = new Move(this, board->blackPieces[z], new Position{pos->x, pos->y}, possiblePosition[i]);
                        possibleMoves.push_back(tempMove);
                    }
                }
            }
        }
    }


    return possibleMoves;
}*/