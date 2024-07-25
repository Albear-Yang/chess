#include <iostream>
#include <vector>
#include "Board.h"
#include "Enums.h"
#include "Computer.h"
#include "ComputerOne.h"
#include "ComputerTwo.h"
#include "ComputerThree.h"
#include "ComputerFour.h"
#include "GraphicDisplay.h"
#include "GraphicDisplay.h"
#include "TextDisplay.h"
#include <string>

int main() {
    int count = 0;
    Board* board = new Board;
    int boardLen = board->boardLength();
    TextDisplay* Text = new TextDisplay(board);
    GraphicsDisplay* Graphics = new GraphicsDisplay(board, new Xwindow(50*(boardLen+2), 50*(boardLen+1)));
    std::string command;
    while (std::cin >> command) {
        if (command == "setup") {
            board->setup= true;
            board->notifyObservers();
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
                else if (command == "+") {
                    char c;
                    std::string pos;
                    std::cin >> c >> pos;
                    bool empty = true;
                    for (auto p : board->whitePieces) {
                        if (p->getPos()->x == 8 - (pos[1] - '0') && p->getPos()->y == pos[0] - 'a') empty = false;
                    }
                    for (auto p : board->blackPieces) {
                        if (p->getPos()->x == 8 - (pos[1] - '0') && p->getPos()->y == pos[0] - 'a') empty = false;
                    }
                    if (empty) {
                        switch (c) {
                            case 'K': 
                                if (board->hasWhiteKing) {
                                    std::cout << "Too many white kings" << std::endl;
                                }
                                else {
                                    board->addPiece(Type::KING, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                    if (board->check4check(Color::WHITE)) {
                                        std::cout << "King cannot start on check" << std::endl;
                                        board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                    }
                                    else board->hasWhiteKing = true; 
                                }
                                break;
                            case 'N': 
                                board->addPiece(Type::KNIGHT, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                if (board->check4check(Color::BLACK)) {
                                    std::cout << "King cannot start on check" << std::endl;
                                    board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                }
                                break;
                            case 'B': 
                                board->addPiece(Type::BISHOP, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                if (board->check4check(Color::BLACK)) {
                                    std::cout << "King cannot start on check" << std::endl;
                                    board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                }
                                break;
                            case 'R': 
                                board->addPiece(Type::ROOK, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                if (board->check4check(Color::BLACK)) {
                                    std::cout << "King cannot start on check" << std::endl;
                                    board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                }
                                break;
                            case 'Q': 
                                board->addPiece(Type::QUEEN, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                if (board->check4check(Color::BLACK)) {
                                    std::cout << "King cannot start on check" << std::endl;
                                    board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                }
                                break;
                            case 'P': 
                                if (8 - (pos[1] - '0') == 0 || 8 - (pos[1] - '0') == boardLen - 1) {
                                    std::cout << "Pawn must not be on first or last row" << std::endl; break;
                                }
                                else {
                                    board->addPiece(Type::PAWN, Color::WHITE, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                    if (board->check4check(Color::BLACK)) {
                                        std::cout << "King cannot start on check" << std::endl;
                                        board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                    }
                                    break;
                                }
                            case 'k': 
                                if (board->hasBlackKing) {
                                    std::cout << "Too many black kings" << std::endl;
                                }
                                else {
                                    board->addPiece(Type::KING, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                    if (board->check4check(Color::BLACK)) {
                                        std::cout << "King cannot start on check" << std::endl;
                                        board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                    }
                                    else board->hasBlackKing = true; 
                                }
                                break;
                            case 'n': 
                                board->addPiece(Type::KNIGHT, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                if (board->check4check(Color::WHITE)) {
                                    std::cout << "King cannot start on check" << std::endl;
                                    board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                }
                                break;
                            case 'b': 
                                board->addPiece(Type::BISHOP, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                if (board->check4check(Color::WHITE)) {
                                    std::cout << "King cannot start on check" << std::endl;
                                    board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                }
                                break;
                            case 'r': 
                                board->addPiece(Type::ROOK, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                if (board->check4check(Color::WHITE)) {
                                    std::cout << "King cannot start on check" << std::endl;
                                    board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                }
                                break;
                            case 'q': 
                                board->addPiece(Type::QUEEN, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                if (board->check4check(Color::WHITE)) {
                                    std::cout << "King cannot start on check" << std::endl;
                                    board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                }
                                break;
                            case 'p': 
                                if (8 - (pos[1] - '0') == 0 || 8 - (pos[1] - '0') == boardLen - 1) {
                                    std::cout << "Pawn must not be on first or last row" << std::endl; break;
                                }
                                else {
                                    board->addPiece(Type::PAWN, Color::BLACK, 8 - (pos[1] - '0'), pos[0] - 'a'); 
                                    if (board->check4check(Color::WHITE)) {
                                        std::cout << "King cannot start on check" << std::endl;
                                        board->removePiece(8 - (pos[1] - '0'), pos[0] - 'a');
                                    }
                                    break;
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
                        if (p->getPos()->x == 8 - (pos[1] - '0') && p->getPos()->y == pos[0] - 'a') { pieceRm = p; break; }
                    }
                    for (auto p : board->blackPieces) {
                        if (p->getPos()->x == 8 - (pos[1] - '0') && p->getPos()->y == pos[0] - 'a') { pieceRm = p; break; }
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
        else if (command == "game" && board->setup) {
            std::string state = " ";
            ComputerOne compOne(board);
            ComputerTwo compTwo(board);
            ComputerThree compThree(board);
            ComputerFour compFour(board);
            board->round1 = true;
            board->undoCalled = false;
            board->notifyObservers();
            for (auto p : board->whitePieces) {
                Type type = p->typeValue();
                if (type == Type::ROOK) board->startingWhitePieces.emplace_back(new Rook(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::BISHOP) board->startingWhitePieces.emplace_back(new Bishop(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::KING) board->startingWhitePieces.emplace_back(new King(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::QUEEN) board->startingWhitePieces.emplace_back(new Queen(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::KNIGHT) board->startingWhitePieces.emplace_back(new Knight(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::PAWN) board->startingWhitePieces.emplace_back(new Pawn(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
            }
            for (auto p : board->blackPieces) {
                Type type = p->typeValue();
                if (type == Type::ROOK) board->startingBlackPieces.emplace_back(new Rook(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::BISHOP) board->startingBlackPieces.emplace_back(new Bishop(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::KING) board->startingBlackPieces.emplace_back(new King(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::QUEEN) board->startingBlackPieces.emplace_back(new Queen(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::KNIGHT) board->startingBlackPieces.emplace_back(new Knight(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
                else if (type == Type::PAWN) board->startingBlackPieces.emplace_back(new Pawn(board, new Position{p->positionXValue(), p->positionYValue()}, p->getColor()));
            }
            std::string white, black;
            std::cin >> white >> black;
            while (command != "resign" && state != "checkmate" && state != "stalemate" && state != "draw") {
                if (board->enpassed != nullptr) delete board->enpassed;
                board->enpassed = nullptr;
                if (board->whosTurn == Color::WHITE) {
                    if (white == "human") {
                        std::cout << "White Move (move <pos1> <pos2>) : " << std::endl;
                        std::string init, fin;
                        std::cin >> command;
                        bool pass = false;
                        if (command == "move") {
                            std::cin >> init >> fin;
                            std::vector<Move*> temp = board->whiteMoves();
                            while (true) {
                                Piece* starter = nullptr;
                                Piece* capturee = nullptr;
                                for (auto p : board->whitePieces) {
                                    if (p->positionXValue() == 8 - init[1] + '0' && p->positionYValue() == init[0] - 'a') {
                                        starter = p;
                                        break;
                                    }
                                }
                                for (auto p : board->blackPieces) {
                                    if (p->positionXValue() == 8 - fin[1] + '0' && p->positionYValue() == fin[0] - 'a') {
                                        capturee = p;
                                        break;
                                    }
                                }
                                if (starter != nullptr) {
                                    for (auto m : temp) {
                                        if (capturee == nullptr) {
                                            if (m->initPos()->x == starter->positionXValue() && m->initPos()->y == starter->positionYValue() && m->initPos()->x == 8 - init[1] + '0' && m->initPos()->y == init[0] - 'a' && m->finPos()->x == 8 - fin[1] + '0' && m->finPos()->y == fin[0] - 'a' && m->pieceMoved() == starter) {
                                                if (starter->enpassable != nullptr) {
                                                    if (8 - fin[1] + '0' == starter->enpassable->x && fin[0] - 'a' == starter->enpassable->y) {
                                                        board->removePiece(starter->enpassable->x + 1, starter->enpassable->y);
                                                        board->enpassed = new Position{starter->enpassable->x + 1, starter->enpassable->y};
                                                    }
                                                }
                                                if (starter->typeValue() == Type::PAWN && m->finPos()->x == 0) {
                                                    Piece* promo;
                                                    char c;
                                                    while (true) {
                                                        std::cout << "Select a Promotion for Pawn moved (Q/R/N/B): " << std::endl;
                                                        std::cin >> c;
                                                        if (c == 'Q' || c == 'R' || c == 'N' || c == 'B') break;
                                                        else std::cout << "Invalid Selection" << std::endl;
                                                    }
                                                    switch (c)
                                                    {
                                                    case 'Q':
                                                        board->removePiece(starter);
                                                        promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                                        promo->has_moved = true;
                                                        board->addPiece(promo);
                                                        board->startingWhitePieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                                        break;
                                                    case 'R':
                                                        board->removePiece(starter);
                                                        promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                                        promo->has_moved = true;
                                                        board->addPiece(promo);
                                                        board->startingWhitePieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                                        break;
                                                    case 'N':
                                                        board->removePiece(starter);
                                                        promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                                        promo->has_moved = true;
                                                        board->addPiece(promo);
                                                        board->startingWhitePieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                                        break;
                                                    case 'B':
                                                        board->removePiece(starter);
                                                        promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                                        promo->has_moved = true;
                                                        board->addPiece(promo);
                                                        board->startingWhitePieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                                        break;
                                                    }
                                                    board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{8 - fin[1] + '0', fin[0] - 'a'}));
                                                }
                                                else board->addMove(m);
                                                board->whosTurn = Color::BLACK;
                                                pass = true;
                                                starter->has_moved = true;
                                                break;
                                            }
                                        }
                                        else if (m->initPos()->x == starter->positionXValue() && m->initPos()->y == starter->positionYValue() && m->finPos()->x == capturee->positionXValue() && m->finPos()->y == capturee->positionYValue() && m->initPos()->x == 8 - init[1] + '0' && m->initPos()->y == init[0] - 'a' && m->finPos()->x == 8 - fin[1] + '0' && m->finPos()->y == fin[0] - 'a' && m->pieceMoved() == starter && m->pieceCaped() == capturee) {
                                            board->removePiece(8 - fin[1] + '0', fin[0] - 'a');
                                            if (starter->typeValue() == Type::PAWN && m->finPos()->x == 0) {
                                                Piece* promo;
                                                char c;
                                                while (true) {
                                                    std::cout << "Select a Promotion for Pawn moved (Q/R/N/B): " << std::endl;
                                                    std::cin >> c;
                                                    if (c == 'Q' || c == 'R' || c == 'N' || c == 'B') break;
                                                    else std::cout << "Invalid Selection" << std::endl;
                                                }
                                                switch (c)
                                                {
                                                case 'Q':
                                                    board->removePiece(starter);
                                                    promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                                    promo->has_moved = true;
                                                    board->addPiece(promo);
                                                    board->startingWhitePieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                                    break;
                                                case 'R':
                                                    board->removePiece(starter);
                                                    promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                                    promo->has_moved = true;
                                                    board->addPiece(promo);
                                                    board->startingWhitePieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                                    break;
                                                case 'N':
                                                    board->removePiece(starter);
                                                    promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                                    promo->has_moved = true;
                                                    board->addPiece(promo);
                                                    board->startingWhitePieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                                    break;
                                                case 'B':
                                                    board->removePiece(starter);
                                                    promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                                    promo->has_moved = true;
                                                    board->addPiece(promo);
                                                    board->startingWhitePieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                                    break;
                                                }
                                                board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{8 - fin[1] + '0', fin[0] - 'a'}));
                                            }
                                            else board->addMove(m);
                                            starter->has_moved = true;
                                            board->whosTurn = Color::BLACK;
                                            pass = true;
                                            break;
                                        }
                                    }
                                }
                                if (!pass) {
                                    std::cout << "Invalid move" << std::endl;
                                    std::cin >> command;
                                }
                                else break;
                                while (command != "resign" && command != "move") {
                                    std::cout << "Invalid input (resign or move <pos1> <pos2>)" << std::endl;
                                    std::cin >> command;
                                }
                                if (command == "resign") break;
                                else std::cin >> init >> fin;
                            }
                            for(auto i = temp.begin(); i != temp.end();){
                                bool flag = false;
                                if ((*i)->castle != nullptr) flag = true;
                                if (board->pastMoves.size() > 0) {
                                    if (flag) {
                                        if (board->pastMoves.back() != (*i)->castle) {
                                            delete (*i)->castle;
                                            delete *i;
                                            temp.erase(i);
                                        }
                                        else i++;
                                    }
                                    else if (board->pastMoves.back() != *i) {
                                        delete *i;
                                        temp.erase(i);
                                    }
                                    else {
                                        i++;
                                    }
                                }
                                else {
                                    if (flag) delete (*i)->castle;
                                    delete *i;
                                    temp.erase(i);
                                }
                            }
                            if (command != "resign") std::cout << "Move made" << std::endl;
                        }
                        else if (command == "undo") {
                            Move* lastMove = board->pastMoves.back();
                            board->undo();
                            board->undoCalled = true;
                            if (lastMove->pieceCaped() != nullptr) {
                                for (auto i = board->gone.begin(); i != board->gone.end(); i++) {
                                    if (*i == lastMove->pieceCaped()) {
                                        board->addPiece(*i);
                                        board->gone.erase(i);
                                        break;
                                    }
                                }
                            }
                            delete lastMove;
                        }
                    }
                    else { 
                        if (white == "computer[1]"){
                            Move* m = compOne.algorithm();
                            Piece* starter = m->pieceMoved();
                            Piece* capturee = m->pieceCaped();
                            if (starter->enpassable != nullptr) {
                                if (m->finPos()->x == starter->enpassable->x && m->finPos()->y == starter->enpassable->y) {
                                    board->removePiece(starter->enpassable->x + 1, starter->enpassable->y);
                                    board->enpassed = new Position{starter->enpassable->x + 1, starter->enpassable->y};
                                }
                            }
                            board->removePiece(m->finPos()->x, m->finPos()->y);
                            if (starter->typeValue() == Type::PAWN && m->finPos()->x == 0) {
                                Piece* promo;
                                int c = rand() % 4;
                                switch (c)
                                {
                                case 0:
                                    board->removePiece(starter);
                                    promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 1:
                                    board->removePiece(starter);
                                    promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 2:
                                    board->removePiece(starter);
                                    promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 3:
                                    board->removePiece(starter);
                                    promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                }
                                board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{m->finPos()->x, m->finPos()->y}));
                            }
                            else board->addMove(m);
                            board->whosTurn = Color::BLACK;
                            starter->has_moved = true;
                            std::cout << "Move made ["<< m->initPos()-> x << " " <<  m->initPos()-> y <<  " to "<<m->finPos()->x << " " <<  m->finPos()->y << std::endl;
                        }
                        else if (white == "computer[2]"){
                            Move* m = compTwo.algorithm();
                            Piece* starter = m->pieceMoved();
                            Piece* capturee = m->pieceCaped();
                            if (starter->enpassable != nullptr) {
                                if (m->finPos()->x == starter->enpassable->x && m->finPos()->y == starter->enpassable->y) {
                                    board->removePiece(starter->enpassable->x + 1, starter->enpassable->y);
                                    board->enpassed = new Position{starter->enpassable->x + 1, starter->enpassable->y};
                                }
                            }
                            board->removePiece(m->finPos()->x, m->finPos()->y);
                            if (starter->typeValue() == Type::PAWN && m->finPos()->x == 0) {
                                Piece* promo;
                                int c = rand() % 4;
                                switch (c)
                                {
                                case 0:
                                    board->removePiece(starter);
                                    promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 1:
                                    board->removePiece(starter);
                                    promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 2:
                                    board->removePiece(starter);
                                    promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 3:
                                    board->removePiece(starter);
                                    promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                }
                                board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{m->finPos()->x, m->finPos()->y}));
                            }
                            else board->addMove(m);
                            board->whosTurn = Color::BLACK;
                            starter->has_moved = true;
                            std::cout << "Move made" << std::endl; 
                        }
                        else if (white == "computer[3]"){
                            Move* m = compThree.algorithm();
                            Piece* starter = m->pieceMoved();
                            Piece* capturee = m->pieceCaped();
                            if (starter->enpassable != nullptr) {
                                if (m->finPos()->x == starter->enpassable->x && m->finPos()->y == starter->enpassable->y) {
                                    board->removePiece(starter->enpassable->x + 1, starter->enpassable->y);
                                    board->enpassed = new Position{starter->enpassable->x + 1, starter->enpassable->y};
                                }
                            }
                            board->removePiece(m->finPos()->x, m->finPos()->y);
                            if (starter->typeValue() == Type::PAWN && m->finPos()->x == 0) {
                                Piece* promo;
                                int c = rand() % 4;
                                switch (c)
                                {
                                case 0:
                                    board->removePiece(starter);
                                    promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 1:
                                    board->removePiece(starter);
                                    promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 2:
                                    board->removePiece(starter);
                                    promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 3:
                                    board->removePiece(starter);
                                    promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                }
                                board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{m->finPos()->x, m->finPos()->y}));
                            }
                            else board->addMove(m);
                            board->whosTurn = Color::BLACK;
                            starter->has_moved = true;
                            std::cout << "Move made" << std::endl; 
                        }
                        else if (white == "computer[4]"){
                            Move* m = compFour.algorithm();
                            Piece* starter = m->pieceMoved();
                            Piece* capturee = m->pieceCaped();
                            if (starter->enpassable != nullptr) {
                                if (m->finPos()->x == starter->enpassable->x && m->finPos()->y == starter->enpassable->y) {
                                    board->removePiece(starter->enpassable->x + 1, starter->enpassable->y);
                                    board->enpassed = new Position{starter->enpassable->x + 1, starter->enpassable->y};
                                }
                            }
                            board->removePiece(m->finPos()->x, m->finPos()->y);
                            if (starter->typeValue() == Type::PAWN && m->finPos()->x == 0) {
                                Piece* promo;
                                int c = rand() % 4;
                                switch (c)
                                {
                                case 0:
                                    board->removePiece(starter);
                                    promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 1:
                                    board->removePiece(starter);
                                    promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 2:
                                    board->removePiece(starter);
                                    promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                case 3:
                                    board->removePiece(starter);
                                    promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingWhitePieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::WHITE));
                                    break;
                                }
                                board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{m->finPos()->x, m->finPos()->y}));
                            }
                            else board->addMove(m);
                            board->whosTurn = Color::BLACK;
                            starter->has_moved = true;
                            std::cout << "Move made" << std::endl; 
                        }
                    }
                }
                else {
                    if (black == "human") {
                        std::cout << "Black Move (move <pos1> <pos2>) : " << std::endl;
                        std::string init, fin;
                        std::cin >> command;
                        bool pass = false;
                        if (command == "move") {
                            std::cin >> init >> fin;
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
                                if (starter != nullptr) {
                                    for (auto m : temp) {
                                        if (capturee == nullptr) {
                                            if (m->initPos()->x == starter->positionXValue() && m->initPos()->y == starter->positionYValue() && m->initPos()->x == 8 - init[1] + '0' && m->initPos()->y == init[0] - 'a' && m->finPos()->x == 8 - fin[1] + '0' && m->finPos()->y == fin[0] - 'a' && m->pieceMoved() == starter) {
                                                if (starter->enpassable != nullptr) {
                                                    if (8 - fin[1] + '0' == starter->enpassable->x && fin[0] - 'a' == starter->enpassable->y) {
                                                        board->removePiece(starter->enpassable->x - 1, starter->enpassable->y);
                                                        board->enpassed = new Position{starter->enpassable->x + 1, starter->enpassable->y};
                                                    }
                                                }
                                                if (starter->typeValue() == Type::PAWN && m->finPos()->x == 7) {
                                                    Piece* promo;
                                                    char c;
                                                    while (true) {
                                                        std::cout << "Select a Promotion for Pawn moved (Q/R/N/B): " << std::endl;
                                                        std::cin >> c;
                                                        if (c == 'q' || c == 'r' || c == 'n' || c == 'b') break;
                                                        else std::cout << "Invalid Selection" << std::endl;
                                                    }
                                                    switch (c)
                                                    {
                                                    case 'q':
                                                        board->removePiece(starter);
                                                        promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                                        promo->has_moved = true;
                                                        board->addPiece(promo);
                                                        board->startingBlackPieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                                        break;
                                                    case 'r':
                                                        board->removePiece(starter);
                                                        promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                                        promo->has_moved = true;
                                                        board->addPiece(promo);
                                                        board->startingBlackPieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                                        break;
                                                    case 'n':
                                                        board->removePiece(starter);
                                                        promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                                        promo->has_moved = true;
                                                        board->addPiece(promo);
                                                        board->startingBlackPieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                                        break;
                                                    case 'b':
                                                        board->removePiece(starter);
                                                        promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                                        promo->has_moved = true;
                                                        board->addPiece(promo);
                                                        board->startingBlackPieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                                        break;
                                                    }
                                                    board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{8 - fin[1] + '0', fin[0] - 'a'}));
                                                }
                                                else board->addMove(m);
                                                starter->has_moved = true;
                                                board->whosTurn = Color::WHITE;
                                                pass = true;
                                                break;
                                            }
                                        }
                                        else if (m->initPos()->x == starter->positionXValue() && m->initPos()->y == starter->positionYValue() && m->finPos()->x == capturee->positionXValue() && m->finPos()->y == capturee->positionYValue() && m->initPos()->x == 8 - init[1] + '0' && m->initPos()->y == init[0] - 'a' && m->finPos()->x == 8 - fin[1] + '0' && m->finPos()->y == fin[0] - 'a' && m->pieceMoved() == starter && m->pieceCaped() == capturee) {
                                            board->removePiece(8 - fin[1] + '0', fin[0] - 'a');
                                            if (starter->typeValue() == Type::PAWN && m->finPos()->x == 0) {
                                                Piece* promo;
                                                char c;
                                                while (true) {
                                                    std::cout << "Select a Promotion for Pawn moved (Q/R/N/B): " << std::endl;
                                                    std::cin >> c;
                                                    if (c == 'Q' || c == 'R' || c == 'N' || c == 'B') break;
                                                    else std::cout << "Invalid Selection" << std::endl;
                                                }
                                                switch (c)
                                                {
                                                case 'Q':
                                                    board->removePiece(starter);
                                                    promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                                    promo->has_moved = true;
                                                    board->addPiece(promo);
                                                    board->startingBlackPieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                                    break;
                                                case 'R':
                                                    board->removePiece(starter);
                                                    promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                                    promo->has_moved = true;
                                                    board->addPiece(promo);
                                                    board->startingBlackPieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                                    break;
                                                case 'N':
                                                    board->removePiece(starter);
                                                    promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                                    promo->has_moved = true;
                                                    board->addPiece(promo);
                                                    board->startingBlackPieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                                    break;
                                                case 'B':
                                                    board->removePiece(starter);
                                                    promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                                    promo->has_moved = true;
                                                    board->addPiece(promo);
                                                    board->startingBlackPieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                                    break;
                                                }
                                                board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{8 - fin[1] + '0', fin[0] - 'a'}));
                                            }
                                            else board->addMove(m);
                                            starter->has_moved = true;
                                            board->whosTurn = Color::WHITE;
                                            pass = true;
                                            break;
                                        }
                                    }
                                }
                                if (!pass) {
                                    std::cout << "Invalid move" << std::endl;
                                    std::cin >> command;
                                }
                                else break;
                                while (command != "resign" && command != "move") {
                                    std::cout << "Invalid input (resign or move <pos1> <pos2>)" << std::endl;
                                    std::cin >> command;
                                }
                                if (command == "resign") break;
                                else std::cin >> init >> fin;
                            }
                            for(auto i = temp.begin(); i != temp.end();){
                                bool flag = false;
                                if ((*i)->castle != nullptr) flag = true;
                                if (board->pastMoves.size() > 0) {
                                    if (flag) {
                                        if (board->pastMoves.back() != (*i)->castle) {
                                            delete (*i)->castle;
                                            delete *i;
                                            temp.erase(i);
                                        }
                                        else i++;
                                    }
                                    else if (board->pastMoves.back() != *i) {
                                        delete *i;
                                        temp.erase(i);
                                    }
                                    else {
                                        i++;
                                    }
                                }
                                else {
                                    if (flag) delete (*i)->castle;
                                    delete *i;
                                    temp.erase(i);
                                }
                            }
                            if (command != "resign") std::cout << "Move made" << std::endl; 
                        }
                        else if (command == "undo") {
                            Move* lastMove = board->pastMoves.back();
                            board->undo();
                            board->undoCalled = true;
                            if (lastMove->pieceCaped() != nullptr) {
                                for (auto i = board->gone.begin(); i != board->gone.end(); i++) {
                                    if (*i == lastMove->pieceCaped()) {
                                        board->addPiece(*i);
                                        board->gone.erase(i);
                                        break;
                                    }
                                }
                            }
                            delete lastMove;
                        }
                    }
                    else { 
                        if (black == "computer[1]"){
                            Move* m = compOne.algorithm();
                            Piece* starter = m->pieceMoved();
                            Piece* capturee = m->pieceCaped();
                            if (starter->enpassable != nullptr) {
                                if (m->finPos()->x == starter->enpassable->x && m->finPos()->y == starter->enpassable->y) {
                                    board->removePiece(starter->enpassable->x + 1, starter->enpassable->y);
                                    board->enpassed = new Position{starter->enpassable->x + 1, starter->enpassable->y};
                                }
                            }
                            board->removePiece(m->finPos()->x, m->finPos()->y);
                            if (starter->typeValue() == Type::PAWN && m->finPos()->x == 7) {
                                Piece* promo;
                                int c = rand() % 4;
                                switch (c)
                                {
                                case 0:
                                    board->removePiece(starter);
                                    promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 1:
                                    board->removePiece(starter);
                                    promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 2:
                                    board->removePiece(starter);
                                    promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 3:
                                    board->removePiece(starter);
                                    promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                }
                                board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{m->finPos()->x, m->finPos()->y}));
                            }
                            else board->addMove(m);
                            board->whosTurn = Color::WHITE;
                            starter->has_moved = true;
                            std::cout << "Move made" << std::endl; 
                        }
                        else if (black == "computer[2]"){
                            Move* m = compTwo.algorithm();
                            Piece* starter = m->pieceMoved();
                            Piece* capturee = m->pieceCaped();
                            if (starter->enpassable != nullptr) {
                                if (m->finPos()->x == starter->enpassable->x && m->finPos()->y == starter->enpassable->y) {
                                    board->removePiece(starter->enpassable->x + 1, starter->enpassable->y);
                                    board->enpassed = new Position{starter->enpassable->x + 1, starter->enpassable->y};
                                }
                            }
                            board->removePiece(m->finPos()->x, m->finPos()->y);
                            if (starter->typeValue() == Type::PAWN && m->finPos()->x == 7) {
                                Piece* promo;
                                int c = rand() % 4;
                                switch (c)
                                {
                                case 0:
                                    board->removePiece(starter);
                                    promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 1:
                                    board->removePiece(starter);
                                    promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 2:
                                    board->removePiece(starter);
                                    promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 3:
                                    board->removePiece(starter);
                                    promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                }
                                board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{m->finPos()->x, m->finPos()->y}));
                            }
                            else board->addMove(m);
                            board->whosTurn = Color::WHITE;
                            starter->has_moved = true;
                            std::cout << "Move made" << std::endl; 
                        }
                        else if (black == "computer[3]"){
                            Move* m = compThree.algorithm();
                            Piece* starter = m->pieceMoved();
                            Piece* capturee = m->pieceCaped();
                            if (starter->enpassable != nullptr) {
                                if (m->finPos()->x == starter->enpassable->x && m->finPos()->y == starter->enpassable->y) {
                                    board->removePiece(starter->enpassable->x + 1, starter->enpassable->y);
                                    board->enpassed = new Position{starter->enpassable->x + 1, starter->enpassable->y};
                                }
                            }
                            board->removePiece(m->finPos()->x, m->finPos()->y);
                            if (starter->typeValue() == Type::PAWN && m->finPos()->x == 7) {
                                Piece* promo;
                                int c = rand() % 4;
                                switch (c)
                                {
                                case 0:
                                    board->removePiece(starter);
                                    promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 1:
                                    board->removePiece(starter);
                                    promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 2:
                                    board->removePiece(starter);
                                    promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 3:
                                    board->removePiece(starter);
                                    promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                }
                                board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{m->finPos()->x, m->finPos()->y}));
                            }
                            else board->addMove(m);
                            board->whosTurn = Color::WHITE;
                            starter->has_moved = true;
                            std::cout << "Move made" << std::endl; 
                        }
                        else if (black == "computer[4]"){
                            Move* m = compFour.algorithm();
                            Piece* starter = m->pieceMoved();
                            Piece* capturee = m->pieceCaped();
                            if (starter->enpassable != nullptr) {
                                if (m->finPos()->x == starter->enpassable->x && m->finPos()->y == starter->enpassable->y) {
                                    board->removePiece(starter->enpassable->x + 1, starter->enpassable->y);
                                    board->enpassed = new Position{starter->enpassable->x + 1, starter->enpassable->y};
                                }
                            }
                            board->removePiece(m->finPos()->x, m->finPos()->y);
                            if (starter->typeValue() == Type::PAWN && m->finPos()->x == 7) {
                                Piece* promo;
                                int c = rand() % 4;
                                switch (c)
                                {
                                case 0:
                                    board->removePiece(starter);
                                    promo = new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Queen(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 1:
                                    board->removePiece(starter);
                                    promo = new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Rook(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 2:
                                    board->removePiece(starter);
                                    promo = new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Knight(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                case 3:
                                    board->removePiece(starter);
                                    promo = new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK);
                                    promo->has_moved = true;
                                    board->addPiece(promo);
                                    board->startingBlackPieces.emplace_back(new Bishop(board, new Position{m->finPos()->x, m->finPos()->y}, Color::BLACK));
                                    break;
                                }
                                board->addMove(new Move(promo, capturee, new Position{m->initPos()->x, m->initPos()->y},  new Position{m->finPos()->x, m->finPos()->y}));
                            }
                            else{
                                board->addMove(m);
                            } 
                            board->whosTurn = Color::WHITE;
                            starter->has_moved = true;
                            std::cout << "Move made" << std::endl; 
                        }
                    }
                }
                board->round1 = false;
                if (command != "resign") board->notifyObservers();
                board->undoCalled = false;
                if (board->checkmate()) {
                    state = "checkmate";
                }
                else if (board->stalemate()) {
                    state = "stalemate";
                }
                else if (board->draw()) {
                    state = "draw";
                }
            }
            if (state == "stalemate") {
                std::cout << "STALEMATE" << std::endl;
                board->blackScore += 0.5;
                board->whiteScore += 0.5;
            }
            else if (state == "draw") {
                std::cout << "DRAW" << std::endl;
            }
            else if (board->whosTurn == Color::WHITE) {
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
    delete Graphics;
    delete board;
}
