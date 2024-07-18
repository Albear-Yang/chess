#include <iostream>
#include <vector>
#include "Board.h"
#include "Enums.h"
#include "Computer.h"
#include "GraphicDisplay.h"
#include "TextDisplay.h"
#include <string>

int main() {
    Board* board = new Board;
    int boardLen = board->boardLength();
    TextDisplay* Text = new TextDisplay(board);
    GraphicsDisplay* Graphic = new GraphicsDisplay(board);

    std::string command;
    while (std::cin >> command) {
        if (command == "setup") {
            std::cin >> command;
            while (command != "done") {
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
                    board->notifyObservers();
                }
                else if (command == "+") {
                    char c;
                    std::string pos;
                    std::cin >> c >> pos;
                    switch (c) {
                        case 'K': 
                            if (board->hasWhiteKing) {
                                std::cout << "Too many white kings" << std::endl;
                            }
                            else if (board->check4check(Color::WHITE)) {
                                std::cout << "King cannot start on check" << std::endl;
                            }
                            else {
                                board->addPiece(Type::KING, Color::WHITE, pos[1] - '0', pos[0] - 'a'); 
                                board->hasWhiteKing = true; 
                                break;
                            }
                        case 'N': board->addPiece(Type::KNIGHT, Color::WHITE, pos[1] - '0', pos[0] - 'a'); break;
                        case 'B': board->addPiece(Type::BISHOP, Color::WHITE, pos[1] - '0', pos[0] - 'a'); break;
                        case 'R': board->addPiece(Type::ROOK, Color::WHITE, pos[1] - '0', pos[0] - 'a'); break;
                        case 'Q': board->addPiece(Type::QUEEN, Color::WHITE, pos[1] - '0', pos[0] - 'a'); break;
                        case 'P': 
                            if (pos[1] - '0' == 0 || pos[1] - '0' == boardLen - 1) {
                                std::cout << "Pawn must not be on first or last row" << std::endl;
                            }
                            else {
                                board->addPiece(Type::PAWN, Color::WHITE, pos[1] - '0', pos[0] - 'a'); break;
                            }
                        case 'k': 
                            if (board->hasBlackKing) {
                                std::cout << "Too many black kings" << std::endl;
                            }
                            else if (board->check4check(Color::BLACK)) {
                                std::cout << "King cannot start on check" << std::endl;
                            }
                            else {
                                board->addPiece(Type::KING, Color::BLACK, pos[1] - '0', pos[0] - 'a'); 
                                board->hasBlackKing = true; 
                                break;
                            }
                        case 'n': board->addPiece(Type::KNIGHT, Color::BLACK, pos[1] - '0', pos[0] - 'a'); break;
                        case 'b': board->addPiece(Type::BISHOP, Color::BLACK, pos[1] - '0', pos[0] - 'a'); break;
                        case 'r': board->addPiece(Type::ROOK, Color::BLACK, pos[1] - '0', pos[0] - 'a'); break;
                        case 'q': board->addPiece(Type::QUEEN, Color::BLACK, pos[1] - '0', pos[0] - 'a'); break;
                        case 'p': 
                            if (pos[1] - '0' == 0 || pos[1] - '0' == boardLen - 1) {
                                std::cout << "Pawn must not be on first or last row" << std::endl;
                            }
                            else {
                                board->addPiece(Type::PAWN, Color::BLACK, pos[1] - '0', pos[0] - 'a'); break;
                            }
                    }
                    board->notifyObservers();
                }
                else if (command == "-") {
                    std::string pos;
                    std::cin >> pos;
                    board->removePiece(pos[1] - '0', pos[0] - 'a');
                    board->notifyObservers();
                }
                else if (command == "=") {
                    std::string col;
                    std::cin >> col;
                    if (col == "white" || col == "White" || col == "WHITE") board->whosTurn = Color::WHITE;
                    else if (col == "black" || col == "Black" || col == "BLACK") board->whosTurn = Color::BLACK;
                }
            }
            std::cout << "Setup Complete" << std::endl;
        }
        else if (command == "game") {
            board->round1 = true;
            std::string white, black;
            std::cin >> white >> black;
            std::cin >> command;
            while (command != "resign" && command != "checkmate") {
                if (board->whosTurn == Color::WHITE) {
                    if (white == "human") {
                        std::string init, fin;
                        std::cin >> command >> init >> fin;
                        if (command == "move") {
                            Piece* starter = nullptr;
                            Piece* capturee = nullptr;
                            for (auto p : board->whitePieces) {
                                if (p->positionXValue() == init[1] - '0' && p->positionYValue() == init[0] - 'a') {
                                    starter = p;
                                    break;
                                }
                            }
                            for (auto p : board->blackPieces) {
                                if (p->positionXValue() == init[1] - '0' && p->positionYValue() == init[0] - 'a') {
                                    capturee = p;
                                    break;
                                }
                            }
                            bool pass = false;
                            for (auto m : board->whiteMoves()) {
                                if (m->initPos().x == starter->positionXValue() && m->initPos().y == starter->positionYValue() && m->finPos().x == capturee->positionXValue() && m->finPos().y == capturee->positionYValue() && m->pieceMoved() == starter && m->pieceCaped() == capturee) {
                                    board->addMove(new Move(starter, capturee, *new Position{starter->positionXValue(), starter->positionYValue()},  *new Position{capturee->positionXValue(), capturee->positionYValue()}));
                                    board->removePiece(capturee->positionXValue(), capturee->positionYValue());
                                    starter->movePos(capturee->positionXValue(), capturee->positionYValue());
                                    board->whosTurn = Color::BLACK;
                                    pass = true;
                                }
                            }
                            if (!pass) {
                                std::cout << "Invalid move" << std::endl;
                            }
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
                        std::string init, fin;
                        std::cin >> command >> init >> fin;
                        if (command == "move") {
                            Piece* starter = nullptr;
                            Piece* capturee = nullptr;
                            for (auto p : board->blackPieces) {
                                if (p->positionXValue() == init[1] - '0' && p->positionYValue() == init[0] - 'a') {
                                    starter = p;
                                    break;
                                }
                            }
                            for (auto p : board->whitePieces) {
                                if (p->positionXValue() == init[1] - '0' && p->positionYValue() == init[0] - 'a') {
                                    capturee = p;
                                    break;
                                }
                            }
                            bool pass = false;
                            for (auto m : board->blackMoves()) {
                                if (m->initPos().x == starter->positionXValue() && m->initPos().y == starter->positionYValue() && m->finPos().x == capturee->positionXValue() && m->finPos().y == capturee->positionYValue() && m->pieceMoved() == starter && m->pieceCaped() == capturee) {
                                    board->addMove(new Move(starter, capturee, *new Position{starter->positionXValue(), starter->positionYValue()},  *new Position{capturee->positionXValue(), capturee->positionYValue()}));
                                    board->removePiece(capturee->positionXValue(), capturee->positionYValue());
                                    starter->movePos(capturee->positionXValue(), capturee->positionYValue());
                                    board->whosTurn = Color::WHITE;
                                    pass = true;
                                }
                            }
                            if (!pass) {
                                std::cout << "Invalid move" << std::endl;
                            }
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
                board->blackScore++;
            }
            else {
                board->whiteScore++;
            }
        }
    }

    delete Text;
    delete Graphic;
}