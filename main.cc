#include <iostream>
#include <vector>
#include "Board.h"
#include "Enums.h"
#include "Computer.h"
//#include "GraphicDisplay.h"
#include "TextDisplay.h"
#include <string>

int main() {
    Board* board = new Board;
    int boardLen = board->boardLength();
    TextDisplay* Text = new TextDisplay(board);
    //GraphicsDisplay* Graphic = new GraphicsDisplay(board);

    std::string command;
    while (std::cin >> command) {
        if (command == "setup") {
            while (command != "done") {
                std::cin >> command;
                if (command == "default") {
                    board->hasBlackKing = true;
                    board->hasWhiteKing = true;
                    board->addPiece(Type::PAWN, Color::WHITE, 6, 0);
                    board->addPiece(Type::PAWN, Color::WHITE, 6, 1);
                    board->addPiece(Type::PAWN, Color::WHITE, 6, 2);
                    board->addPiece(Type::PAWN, Color::WHITE, 6, 3);
                    board->addPiece(Type::PAWN, Color::WHITE, 6, 4);
                    board->addPiece(Type::PAWN, Color::WHITE, 6, 5);
                    board->addPiece(Type::PAWN, Color::WHITE, 6, 6);
                    board->addPiece(Type::PAWN, Color::WHITE, 6, 7);
                    board->addPiece(Type::ROOK, Color::WHITE, 7, 0);
                    board->addPiece(Type::KNIGHT, Color::WHITE, 7, 1);
                    board->addPiece(Type::BISHOP, Color::WHITE, 7, 2);
                    board->addPiece(Type::QUEEN, Color::WHITE, 7, 3);
                    board->addPiece(Type::KING, Color::WHITE, 7, 4);
                    board->addPiece(Type::BISHOP, Color::WHITE, 7, 5);
                    board->addPiece(Type::KNIGHT, Color::WHITE, 7, 6);
                    board->addPiece(Type::ROOK, Color::WHITE, 7, 7);
                    board->addPiece(Type::PAWN, Color::BLACK, 1, 0);
                    board->addPiece(Type::PAWN, Color::BLACK, 1, 1);
                    board->addPiece(Type::PAWN, Color::BLACK, 1, 2);
                    board->addPiece(Type::PAWN, Color::BLACK, 1, 3);
                    board->addPiece(Type::PAWN, Color::BLACK, 1, 4);
                    board->addPiece(Type::PAWN, Color::BLACK, 1, 5);
                    board->addPiece(Type::PAWN, Color::BLACK, 1, 6);
                    board->addPiece(Type::PAWN, Color::BLACK, 1, 7);
                    board->addPiece(Type::ROOK, Color::BLACK, 0, 0);
                    board->addPiece(Type::KNIGHT, Color::BLACK, 0, 1);
                    board->addPiece(Type::BISHOP, Color::BLACK, 0, 2);
                    board->addPiece(Type::QUEEN, Color::BLACK, 0, 3);
                    board->addPiece(Type::KING, Color::BLACK, 0, 4);
                    board->addPiece(Type::BISHOP, Color::BLACK, 0, 5);
                    board->addPiece(Type::KNIGHT, Color::BLACK, 0, 6);
                    board->addPiece(Type::ROOK, Color::BLACK, 0, 7);
                    board->whosTurn = Color::WHITE;
                    board->notifyObservers();
                }
                else if (command == "test") {
                    board->addPiece(Type::KING, Color::WHITE, 7, 4);
                    board->addPiece(Type::KING, Color::BLACK, 0, 4);
                    board->addPiece(Type::ROOK, Color::WHITE, 7, 0);
                    board->addPiece(Type::ROOK, Color::WHITE, 1, 7);
                    board->addPiece(Type::ROOK, Color::BLACK, 6, 7);
                    board->addPiece(Type::ROOK, Color::BLACK, 5, 7);
                    board->hasBlackKing = true;
                    board->hasWhiteKing = true;
                    command = "done";
                }
                else if (command == "+") {
                    char c;
                    std::string pos;
                    std::cin >> c >> pos;
                    bool empty = true;
                    for (auto p : board->whitePieces) {
                        if (p->getPos().x == 8 - (pos[1] - '0') && p->getPos().y == pos[0] - 'a') empty = false;
                    }
                    for (auto p : board->blackPieces) {
                        if (p->getPos().x == 8 - (pos[1] - '0') && p->getPos().y == pos[0] - 'a') empty = false;
                    }
                    if (empty) {
                        switch (c) {
                            case 'K': 
                                if (board->hasWhiteKing) {
                                    std::cout << "Too many white kings" << std::endl;
                                }
                                /*else if (board->check4check(Color::WHITE)) { //uncomment when albert fixes moves()
                                    std::cout << "King cannot start on check" << std::endl;
                                }*/
                                else {
                                    board->addPiece(Type::KING, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                    board->hasWhiteKing = true; 
                                }
                                break;
                            case 'N': board->addPiece(Type::KNIGHT, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); break;
                            case 'B': board->addPiece(Type::BISHOP, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); break;
                            case 'R': board->addPiece(Type::ROOK, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); break;
                            case 'Q': board->addPiece(Type::QUEEN, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); break;
                            case 'P': 
                                if (8 - (pos[1] - '0') == 0 || 8 - (pos[1] - '0') == boardLen - 1) {
                                    std::cout << "Pawn must not be on first or last row" << std::endl;
                                }
                                else {
                                    board->addPiece(Type::PAWN, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); break;
                                }
                            case 'k': 
                                if (board->hasBlackKing) {
                                    std::cout << "Too many black kings" << std::endl;
                                }
                                /*else if (board->check4check(Color::BLACK)) {
                                    std::cout << "King cannot start on check" << std::endl;
                                }*/
                                else {
                                    board->addPiece(Type::KING, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                    board->hasBlackKing = true; 
                                }
                                break;
                            case 'n': board->addPiece(Type::KNIGHT, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); break;
                            case 'b': board->addPiece(Type::BISHOP, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); break;
                            case 'r': board->addPiece(Type::ROOK, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); break;
                            case 'q': board->addPiece(Type::QUEEN, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); break;
                            case 'p': 
                                if (8 - (pos[1] - '0') == 0 || 8 - (pos[1] - '0') == boardLen - 1) {
                                    std::cout << "Pawn must not be on first or last row" << std::endl;
                                }
                                else {
                                    board->addPiece(Type::PAWN, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); break;
                                }
                        }
                    }
                    else {
                        std::cout << "Position is not empty, use '- <pos>' to clear" << std::endl;
                    }
                    board->notifyObservers();
                }
                else if (command == "-") {
                    std::string pos;
                    std::cin >> pos;
                    Piece* pieceRm = nullptr;
                    for (auto p : board->whitePieces) {
                        if (p->getPos().x == 8 - (pos[1] - '0') && p->getPos().y == pos[0] - 'a') { pieceRm = p; break; }
                    }
                    for (auto p : board->blackPieces) {
                        if (p->getPos().x == 8 - (pos[1] - '0') && p->getPos().y == pos[0] - 'a') { pieceRm = p; break; }
                    }
                    if (pieceRm != nullptr) {
                        if (pieceRm->typeValue() == Type::KING) {
                            if (pieceRm->getColor() == Color::WHITE) board->hasWhiteKing = false;
                            else board->hasBlackKing = false;
                        }
                    }
                    board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                    board->notifyObservers();
                }
                else if (command == "=") {
                    std::string col;
                    std::cin >> col;
                    if (col == "white" || col == "White" || col == "WHITE") { board->whosTurn = Color::WHITE; std::cout << "White goes first" << std::endl; }
                    else if (col == "black" || col == "Black" || col == "BLACK") { board->whosTurn = Color::BLACK; std::cout << "Black goes first" << std::endl; }
                    else std::cout << "Valid color inputs : white White WHITE black Black BLACK" << std::endl;
                }
                else if (command == "done" && (!board->hasWhiteKing || !board->hasBlackKing )) {
                    std::cout << "Need exactly 1 King of each color to exit setup" << std::endl;
                    command = " ";
                }
            }
            std::cout << "Setup Complete" << std::endl;
        }
        else if (command == "game") {
            board->notifyObservers();
            for (auto p : board->whitePieces) {
                Type type = p->typeValue();
                if (type == Type::ROOK) board->startingWhitePieces.emplace_back(new Rook(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::BISHOP) board->startingWhitePieces.emplace_back(new Bishop(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::KING) board->startingWhitePieces.emplace_back(new King(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::QUEEN) board->startingWhitePieces.emplace_back(new Queen(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::KNIGHT) board->startingWhitePieces.emplace_back(new Knight(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::PAWN) board->startingWhitePieces.emplace_back(new Pawn(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
            }
            for (auto p : board->blackPieces) {
                Type type = p->typeValue();
                if (type == Type::ROOK) board->startingBlackPieces.emplace_back(new Rook(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::BISHOP) board->startingBlackPieces.emplace_back(new Bishop(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::KING) board->startingBlackPieces.emplace_back(new King(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::QUEEN) board->startingBlackPieces.emplace_back(new Queen(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::KNIGHT) board->startingBlackPieces.emplace_back(new Knight(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::PAWN) board->startingBlackPieces.emplace_back(new Pawn(board, *new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
            }
            board->round1 = true;
            std::string white, black;
            std::cin >> white >> black;
            while (command != "resign" && command != "checkmate") {
                if (board->whosTurn == Color::WHITE) {
                    if (white == "human") {
                        std::cout << "White Move (move <pos1> <pos2>) : " << std::endl;
                        std::string init, fin;
                        std::cin >> command >> init >> fin;
                        bool pass = false;
                        if (command == "move") {
                            //std::cout << "uh " << std::endl;
                            std::vector<Move*> temp = board->whiteMoves();
                            //std::cout << temp.size() << " temp size" << std:: endl;
                            while (true) {
                                //remember to remove
                                //std::cout << "hi" << std::endl;

                                Piece* starter = nullptr;
                                Piece* capturee = nullptr;
                                //if (board->whiteMoves().empty()) std::cout << "hi" << std::endl;
                                /*for (auto p : temp) {
                                    char c;
                                    Type type = p->pieceMoved()->typeValue();
                                    if (type == Type::BISHOP) c = 'B';
                                    else if (type == Type::KNIGHT) c = 'N';
                                    else if (type == Type::PAWN) c = 'P';
                                    else if (type == Type::ROOK) c = 'R';
                                    else if (type == Type::QUEEN) c = 'Q';
                                    else if (type == Type::KING) c = 'K';
                                    std::cout << c << " " << p->initPos().x << " " << p->initPos().y << " " << p->finPos().x << " " << p->finPos().y << std::endl;
                                }*/
                                //std::cout << board->whitePieces.size() << std::endl;
                                for (auto p : board->whitePieces) {
                                    //std::cout << 8 - init[1] + '0' << " " << init[0] - 'a' << std::endl;
                                    //std::cout << p->positionXValue() << " " << p->positionYValue() << std::endl;
                                    if (p->positionXValue() == 8 - init[1] + '0' && p->positionYValue() == init[0] - 'a') {
                                        starter = p;
                                        //std::cout << "starter found" << std::endl;
                                        break;
                                    }
                                }
                                //std::cout << " checkp 2" << std::endl;
                                for (auto p : board->blackPieces) {
                                    if (p->positionXValue() == 8 - fin[1] + '0' && p->positionYValue() == fin[0] - 'a') {
                                        capturee = p;
                                        break;
                                    }
                                }
                                //std::cout << " checkp 3" << std::endl;
                                if (starter != nullptr) {
                                    for (auto m : temp) {
                                        if (capturee == nullptr) {
                                            if (m->initPos().x == starter->positionXValue() && m->initPos().y == starter->positionYValue() && m->initPos().x == 8 - init[1] + '0' && m->initPos().y == init[0] - 'a' && m->finPos().x == 8 - fin[1] + '0' && m->finPos().y == fin[0] - 'a' && m->pieceMoved() == starter) {
                                                //std::cout << " move found " << std::endl;
                                                if (starter->enpassable != nullptr) {
                                                    if (8 - fin[1] + '0' == starter->enpassable->x && fin[0] - 'a' == starter->enpassable->y) {
                                                        board->removePiece(starter->enpassable->x + 1, starter->enpassable->y);
                                                    }
                                                }
                                                board->addMove(new Move(starter, capturee, *new Position{starter->positionXValue(), starter->positionYValue()},  *new Position{8 - fin[1] + '0', fin[0] - 'a'}));
                                                starter->movePos(8 - fin[1] + '0', fin[0] - 'a');
                                                board->whosTurn = Color::BLACK;
                                                pass = true;
                                                if (starter->typeValue() == Type::PAWN || starter->typeValue() == Type::ROOK || starter->typeValue() == Type::KING) starter->has_moved = true;
                                                break;
                                            }
                                        }
                                        else if (m->initPos().x == starter->positionXValue() && m->initPos().y == starter->positionYValue() && m->finPos().x == capturee->positionXValue() && m->finPos().y == capturee->positionYValue() && m->initPos().x == 8 - init[1] + '0' && m->initPos().y == init[0] - 'a' && m->finPos().x == 8 - fin[1] + '0' && m->finPos().y == fin[0] - 'a' && m->pieceMoved() == starter && m->pieceCaped() == capturee) {
                                            //std::cout << " move found " << std::endl;
                                            board->removePiece(8 - fin[1] + '0', fin[0] - 'a');
                                            board->addMove(new Move(starter, capturee, *new Position{starter->positionXValue(), starter->positionYValue()},  *new Position{capturee->positionXValue(), capturee->positionYValue()}));
                                            starter->movePos(8 - fin[1] + '0', fin[0] - 'a');
                                            //std::cout << 8 - init[1] << " " << init[0] - 'a' << std::endl;

                                            //board->addMove(m);
                                            //std::cout << m->finPos().x << " " << m->finPos().y << std::endl;
                                            //std::cout << starter->positionXValue() << " " << starter->positionYValue() << std::endl;
                                            if (starter->typeValue() == Type::PAWN || starter->typeValue() == Type::ROOK || starter->typeValue() == Type::KING) starter->has_moved = true;
                                            board->whosTurn = Color::BLACK;
                                            pass = true;
                                            break;
                                        }
                                    }
                                }
                                //std::cout << " checkp 4" << std::endl;
                                if (!pass) {
                                    std::cout << "Invalid move" << std::endl;
                                    std::cin >> command >> init >> fin;
                                }
                                else break;
                            }
                            std::cout << "Move made" << std::endl;
                        }
                    }
                    else { //FILL WITH AI
                        if (white == "computer[1]");
                        else if (white == "computer[2]");
                        else if (white == "computer[3]");
                        else if (white == "computer[4]");
                    }
                }
                else {
                    if (black == "human") {
                        std::cout << "Black Move (move <pos1> <pos2>) : " << std::endl;
                        std::string init, fin;
                        std::cin >> command >> init >> fin;
                        if (command == "move") {
                            std::vector<Move*> temp = board->blackMoves();
                            while (true) {
                                Piece* starter = nullptr;
                                Piece* capturee = nullptr;
                                for (auto p : board->blackPieces) {
                                    if (p->positionXValue() == 8 - init[1] + '0' && p->positionYValue() == init[0] - 'a') {
                                        starter = p;
                                        break;
                                    }
                                }
                                for (auto p : board->whitePieces) {
                                    if (p->positionXValue() == 8 - fin[1] + '0' && p->positionYValue() == fin[0] - 'a') {
                                        capturee = p;
                                        break;
                                    }
                                }
                                
                                bool pass = false;
                                if (starter != nullptr) {
                                    for (auto m : temp) {
                                        if (capturee == nullptr) {
                                            if (m->initPos().x == starter->positionXValue() && m->initPos().y == starter->positionYValue() && m->initPos().x == 8 - init[1] + '0' && m->initPos().y == init[0] - 'a' && m->finPos().x == 8 - fin[1] + '0' && m->finPos().y == fin[0] - 'a' && m->pieceMoved() == starter) {
                                                if (starter->enpassable != nullptr) {
                                                    if (8 - fin[1] + '0' == starter->enpassable->x && fin[0] - 'a' == starter->enpassable->y) {
                                                        board->removePiece(starter->enpassable->x - 1, starter->enpassable->y);
                                                    }
                                                }
                                                board->addMove(new Move(starter, capturee, *new Position{starter->positionXValue(), starter->positionYValue()},  *new Position{8 - fin[1] + '0', fin[0] - 'a'}));
                                                starter->movePos(8 - fin[1] + '0', fin[0] - 'a');
                                                if (starter->typeValue() == Type::PAWN || starter->typeValue() == Type::ROOK || starter->typeValue() == Type::KING) starter->has_moved = true;
                                                board->whosTurn = Color::WHITE;
                                                pass = true;
                                                break;
                                            }
                                        }
                                        else if (m->initPos().x == starter->positionXValue() && m->initPos().y == starter->positionYValue() && m->finPos().x == capturee->positionXValue() && m->finPos().y == capturee->positionYValue() && m->initPos().x == 8 - init[1] + '0' && m->initPos().y == init[0] - 'a' && m->finPos().x == 8 - fin[1] + '0' && m->finPos().y == fin[0] - 'a' && m->pieceMoved() == starter && m->pieceCaped() == capturee) {
                                            board->removePiece(8 - fin[1] + '0', fin[0] - 'a');
                                            board->addMove(new Move(starter, capturee, *new Position{starter->positionXValue(), starter->positionYValue()},  *new Position{capturee->positionXValue(), capturee->positionYValue()}));
                                            starter->movePos(8 - fin[1] + '0', fin[0] - 'a');
                                            if (starter->typeValue() == Type::PAWN || starter->typeValue() == Type::ROOK || starter->typeValue() == Type::KING) starter->has_moved = true;
                                            board->whosTurn = Color::WHITE;
                                            pass = true;
                                            break;
                                        }
                                    }
                                }
                                if (!pass) {
                                    std::cout << "Invalid move" << std::endl;
                                    std::cin >> command >> init >> fin;
                                }
                                else break;
                            }
                            std::cout << "Move made" << std::endl;
                        }
                    }
                    else { //FILL WITH AI
                        if (black == "computer[1]");
                        else if (black == "computer[2]");
                        else if (black == "computer[3]");
                        else if (black == "computer[4]");
                    }
                }
                board->notifyObservers();
                board->round1 = false;
                if (board->checkmate()) {
                    command = "checkmate";
                }
            }
            if (board->whosTurn == Color::WHITE) {
                std::cout << "BLACK wins a game!" << std::endl;
                board->blackScore++;
            }
            else {
                std::cout << "WHITE wins a game!" << std::endl;
                board->whiteScore++;
            }
            board->clear();
        }
    }
    std::cout << "Final Score: " << std::endl;
    std::cout << "White: " << board->whiteScore << std::endl;
    std::cout << "Black: " << board->blackScore << std::endl;
    delete Text;
    //delete Graphic;
}
