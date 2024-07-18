//attach an observer at the start to display board
#include <iostream>
#include <vector>
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Board.h"
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
                }
                else if (command == "+")
                    char c;
                    std::string pos;
                    std::cin >> c >> pos;
                    switch (c) {
                        case 'K': board->addPiece(Type::KING, Color::WHITE, pos[1] - '0', pos[0] - 'a'); break;
                        case 'N': board->addPiece(Type::KNIGHT, Color::WHITE, pos[1] - '0', pos[0] - 'a'); break;
                        case 'B': board->addPiece(Type::BISHOP, Color::WHITE, pos[1] - '0', pos[0] - 'a'); break;
                        case 'R': board->addPiece(Type::ROOK, Color::WHITE, pos[1] - '0', pos[0] - 'a'); break;
                        case 'B': board->addPiece(Type::BISHOP, Color::WHITE, pos[1] - '0', pos[0] - 'a'); break;
                    }
                    board->addPiece(Type::ROOK, Color::BLACK, 0, 7);
                    board->notifyObservers();
            }
        }
    }

    delete Text;
    delete Graphic;
}