#include "King.h"
using namespace std;

King::King(Board* board, Position* pos, Color color)
    : Piece(board, pos, color, Type::KING) {}

vector<Move*> King::moves(){
    enpassable = nullptr;
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
            if(pos->x + x < 8 && pos->x + x >= 0 && pos->y + y < 8 && pos->y + y < 8){
                //Position* tempPos = new Position(pos->x + x, pos->y + y);
                bool pass = true;
                for(int z = 0; z < allPieces.size(); ++z){
                    Move *tempMove = nullptr;
                    if(pos->x + x == allPieces[z]->pos->x && pos->y + y == allPieces[z]->pos->y){
                        pass = false;
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
                            tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(pos->x + x, pos->y + y));
                            possibleMoves.push_back(tempMove);
                        }
                    }
                }
                if (pass) {
                    Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(pos->x + x, pos->y + y));
                    possibleMoves.push_back(tempMove);
                }
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
    return possibleMoves;
}

std::vector<Move*> King::movesNoCheck() {
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
            if(pos->x + x < 8 && pos->x + x >= 0 && pos->y + y < 8 && pos->y + y < 8){
                Position* tempPos = new Position(pos->x + x, pos->y + y);

                for(int z = 0; z < allPieces.size(); ++z){
                    Move *tempMove = nullptr;
                    if(tempPos == allPieces[z]->pos){
                        if(allPieces[z]->color != color){
                            tempMove = new Move(this, board->blackPieces[z], new Position{pos->x, pos->y}, tempPos);
                            possibleMoves.push_back(tempMove);
                        }
                    }
                }
                Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, tempPos);
                possibleMoves.push_back(tempMove);
            }
        }
    }
    return possibleMoves;
}

/*void King::move(Position newpos){
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
            if(pos->x + x < 8 && pos->x + x >= 0 && pos->y + y < 8 && pos->y + y < 8){
                Position tempPos = Position(pos->x + x, pos->y + y);
                
                for(int z = 0; z < allPieces.size(); ++z){
                    Move *tempMove = nullptr;
                    if(tempPos == allPieces[z]->pos){
                        if(allPieces[z]->color != color){
                            tempMove = new Move(this, board->blackPieces[z], new Position{pos->x, pos->y}, tempPos);
                            possibleMoves.push_back(tempMove);
                        }
                    }
                }
            }
        }
    }
    return possibleMoves;
}*/
