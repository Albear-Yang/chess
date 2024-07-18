#include "Pawn.h"
using namespace std;

Pawn::Pawn(Board* board, Position pos, Color color)
    : Piece(board, pos, color, Type::Pawn) {}

vector<Move*> Pawn::moves(Position pos) const {
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    bool noPieceBetween = true;
    for(int z = 0; z < board.blackPieces.size(); ++z){
        allPieces.pushback(blackPieces[z]);
    } 
    for(int z = 0; z < board.whitePieces.size(); ++z){
        allPieces.pushback(whitePieces[z]);
    }  
    //normal moving forward
    for(int i = 1; i < 3; i++){
        if(i == 2 && has_moved == true){
            continue;
        }
        int reverse = 1;
        if(color == black){
            reverse = -1;
        }
        Position tempPos = Position(pos.x, pos.y + reverse * i);
                
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            if(tempPos == board->allPieces[z]->pos){
                noPieceBetween = false;
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(*this, nullptr, pos, tempPos);
        possibleMoves.pushback(tempMove);
    }
    //normal capturing
    //Capturing Right
    captR = Position(pos.x + 1, pos.y + reverse);
    //Capturing Left
    captL = Position(pos.x - 1, pos.y + reverse);
    for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
        Move *tempMove = nullptr;
        if(captR == board->allPieces[z]->pos){
            *tempMove = new Move(*this, board->blackPieces[z], pos, captR);
            possibleMoves.pushback(tempMove);
        }
        else if(captL == board->allPieces[z]->pos){
            *tempMove = new Move(*this, board->blackPieces[z], pos, captL);
            possibleMoves.pushback(tempMove);
        }
    }
    if(color == White && pos.y == 5 && board->pastMoves(board->pastMoves.end())->pieceMoving->typeValue() == Pawn && board->pastMoves(board->pastMoves.end())->initialPos == 7 && (board->pastMoves(boboard->pastMovesard.end())->pieceMoving->getPos() == pos.x - 1 || && board->pastMoves(board->pastMoves.end())->pieceMoving->getPos().x == pos.x + 1) && board->pastMoves(board.end())->finalPos == 5){
        int capturedPos = board->pastMoves(board->pastMoves.end())->pieceMoving->getPos().x 
        bool right = (capturedPos = pos.x + 1);
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            if(right && captR == board->allPieces[z]->pos){
                break;
            }
            else if(!right && captL == board->allPieces[z]->pos){
                break;
            }
        }
        possibleMoves.pushback(new Move(*this, board->pastMoves(board->pastMoves.end())->pieceMoving, pos, Position(capturedPos, pos.y)));
    }
    else if(color == Black && pos.y == 4 && board->pastMoves(board->pastMoves.end())->pieceMoving->typeValue() == Pawn && board->pastMoves(board.end())->initialPos == 2 && (board->pastMoves(board->pastMoves.end())->pieceMoving->getPos() == pos.x - 1 || && board->pastMoves(board->pastMoves.end())->pieceMoving->getPos().x == pos.x + 1) && board->pastMoves(board->pastMoves.end())->finalPos == 4){
        int capturedPos = board->pastMoves(board->pastMoves.end())->pieceMoving->getPos().x
        bool right = (capturedPos = pos.x + 1);
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            if(right && captR == board->allPieces[z]->pos){
                break;
            }
            else if(!right && captL == board->allPieces[z]->pos){
                break;
            }
        }
        possibleMoves.pushback(new Move(*this, board->pastMoves(board->pastMoves.end())->pieceMoving, pos, Position(capturedPos, pos.y)));
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

void Pawn::move(Position newpos){
    has_moved = true;
    pos = newpos;
}

vector<Move*> Pawn::canCapture(){
    vector<Move*> possibleMoves;

    vector<Piece*> allPieces;
    for(int z = 0; z < board.blackPieces.size(); ++z){
        allPieces.pushback(blackPieces[z]);
    } 
    for(int z = 0; z < board.whitePieces.size(); ++z){
        allPieces.pushback(whitePieces[z]);
    }  

    for(int i = 1; i < 3; i++){
        if(i == 2 && has_moved == true){
            continue;
        }
        int reverse = 1;
        if(color == black){
            reverse = -1;
        }
        Position tempPos = Position(pos.x, pos.y + reverse * i);
                
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            if(tempPos == board->allPieces[z]->pos){
                noPieceBetween = false;
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(*this, nullptr, pos, tempPos);
        possibleMoves.pushback(tempMove);
    }
    //normal capturing
    //Capturing Right
    captR = Position(pos.x + 1, pos.y + reverse);
    //Capturing Left
    captL = Position(pos.x - 1, pos.y + reverse);
    for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
        Move *tempMove = nullptr;
        if(captR == board->allPieces[z]->pos){
            *tempMove = new Move(*this, board->blackPieces[z], pos, captR);
            possibleMoves.pushback(tempMove);
        }
        else if(captL == board->allPieces[z]->pos){
            *tempMove = new Move(*this, board->blackPieces[z], pos, captL);
            possibleMoves.pushback(tempMove);
        }
    }
    if(color == White && pos.y == 5 && board->pastMoves(board->pastMoves.end())->pieceMoving->typeValue() == Pawn && board->pastMoves(board->pastMoves.end())->initialPos == 7 && (board->pastMoves(boboard->pastMovesard.end())->pieceMoving->getPos() == pos.x - 1 || && board->pastMoves(board->pastMoves.end())->pieceMoving->getPos().x == pos.x + 1) && board->pastMoves(board.end())->finalPos == 5){
        int capturedPos = board->pastMoves(board->pastMoves.end())->pieceMoving->getPos().x 
        bool right = (capturedPos = pos.x + 1);
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            if(right && captR == board->allPieces[z]->pos){
                break;
            }
            else if(!right && captL == board->allPieces[z]->pos){
                break;
            }
        }
        possibleMoves.pushback(new Move(*this, board->pastMoves(board->pastMoves.end())->pieceMoving, pos, Position(capturedPos, pos.y)));
    }
    else if(color == Black && pos.y == 4 && board->pastMoves(board->pastMoves.end())->pieceMoving->typeValue() == Pawn && board->pastMoves(board.end())->initialPos == 2 && (board->pastMoves(board->pastMoves.end())->pieceMoving->getPos() == pos.x - 1 || && board->pastMoves(board->pastMoves.end())->pieceMoving->getPos().x == pos.x + 1) && board->pastMoves(board->pastMoves.end())->finalPos == 4){
        int capturedPos = board->pastMoves(board->pastMoves.end())->pieceMoving->getPos().x
        bool right = (capturedPos = pos.x + 1);
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            if(right && captR == board->allPieces[z]->pos){
                break;
            }
            else if(!right && captL == board->allPieces[z]->pos){
                break;
            }
        }
        possibleMoves.pushback(new Move(*this, board->pastMoves(board->pastMoves.end())->pieceMoving, pos, Position(capturedPos, pos.y)));
    }
    return possibleMoves;
}