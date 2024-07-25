#include "Queen.h"
using namespace std;

Queen::Queen(Board* board, Position* pos, Color color)
    : Piece(board, pos, color, Type::QUEEN) {}

vector<Move*> Queen::moves(){
    enpassable = nullptr;
    vector<Move*> possibleMoves;
    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  
    for(int i = pos->x + 1; i < 8; ++i){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->getPos()->x && pos->y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(i, pos->y));
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(i, pos->y));
        possibleMoves.push_back(tempMove);
    }
    for(int i = pos->x - 1; i >= 0; --i){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->getPos()->x && pos->y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(i, pos->y));
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(i, pos->y));
        possibleMoves.push_back(tempMove);
    }
    for(int i = pos->y - 1; i >= 0; --i){
        Piece* capturablePiece = nullptr;
        bool noPieceBetween = true;
        bool validMove = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(pos->x == allPieces[z]->getPos()->x && i == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(pos->x, i));
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(pos->x, i));
        possibleMoves.push_back(tempMove);
    }
    for(int i = pos->y + 1; i < 8; ++i){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(pos->x == allPieces[z]->getPos()->x && i == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(pos->x, i));
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(pos->x, i));
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x + 1, y = pos->y + 1; x < 8 && y < 8; x++, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->getPos()->x && y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x - 1, y = pos->y - 1; x >= 0 && y >= 0; x--, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->getPos()->x && y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x + 1, y = pos->y - 1; x < 8 && y >= 0; x++, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->getPos()->x && y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x - 1, y = pos->y + 1; x >= 0 && y < 8; x--, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->getPos()->x && y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
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

std::vector<Move*> Queen::movesNoCheck(){
    enpassable = nullptr;
    vector<Move*> possibleMoves;
    vector<Piece*> allPieces;
    for(int z = 0; z < board->blackPieces.size(); ++z){
        allPieces.push_back(board->blackPieces[z]);
    } 
    for(int z = 0; z < board->whitePieces.size(); ++z){
        allPieces.push_back(board->whitePieces[z]);
    }  
    for(int i = pos->x + 1; i < 8; ++i){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->getPos()->x && pos->y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(i, pos->y));
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(i, pos->y));
        possibleMoves.push_back(tempMove);
    }
    for(int i = pos->x - 1; i >= 0; --i){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(i == allPieces[z]->getPos()->x && pos->y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(i, pos->y));
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(i, pos->y));
        possibleMoves.push_back(tempMove);
    }
    for(int i = pos->y - 1; i >= 0; --i){
        Piece* capturablePiece = nullptr;
        bool noPieceBetween = true;
        bool validMove = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(pos->x == allPieces[z]->getPos()->x && i == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(pos->x, i));
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(pos->x, i));
        possibleMoves.push_back(tempMove);
    }
    for(int i = pos->y + 1; i < 8; ++i){
        Piece* capturablePiece = nullptr;
        bool validMove = true;
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(pos->x == allPieces[z]->getPos()->x && i == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position(pos->x, i));
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position(pos->x, i));
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x + 1, y = pos->y + 1; x < 8 && y < 8; x++, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->getPos()->x && y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x - 1, y = pos->y - 1; x >= 0 && y >= 0; x--, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->getPos()->x && y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x + 1, y = pos->y - 1; x < 8 && y >= 0; x++, y--){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->getPos()->x && y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    for(int x = pos->x - 1, y = pos->y + 1; x >= 0 && y < 8; x--, y++){
        bool noPieceBetween = true;
        for(int z = 0; z < allPieces.size() && noPieceBetween; ++z){
            Move *tempMove = nullptr;
            if(x == allPieces[z]->getPos()->x && y == allPieces[z]->getPos()->y){
                noPieceBetween = false;
                if(allPieces[z]->getColor() != color){
                    Piece* pc = nullptr;
                    for (auto p : board->blackPieces) {
                        if (p == allPieces[z]) { pc = p; break; }
                    } 
                    if (pc ==  nullptr) {
                        for (auto p : board->whitePieces) {
                            if (p == allPieces[z]) { pc = p; break; }
                        } 
                    }
                    tempMove = new Move(this, pc, new Position{pos->x, pos->y}, new Position{x, y});
                    possibleMoves.push_back(tempMove);
                }
                break;
            }
        }
        if(!noPieceBetween){
            break;
        }
        Move *tempMove = new Move(this, nullptr, new Position{pos->x, pos->y}, new Position{x, y});
        possibleMoves.push_back(tempMove);
    }
    return possibleMoves;
}
