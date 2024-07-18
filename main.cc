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
                    board->addPiece(Type::Pawn, Color::White, 6, 0);
                    board->addPiece(Type::Pawn, Color::White, 6, 1);
                    board->addPiece(Type::Pawn, Color::White, 6, 2);
                    board->addPiece(Type::Pawn, Color::White, 6, 3);
                    board->addPiece(Type::Pawn, Color::White, 6, 4);
                    board->addPiece(Type::Pawn, Color::White, 6, 5);
                    board->addPiece(Type::Pawn, Color::White, 6, 6);
                    board->addPiece(Type::Pawn, Color::White, 6, 7);
                    board->addPiece(Type::Rook, Color::White, 7, 0);
                    board->addPiece(Type::Knight, Color::White, 7, 1);
                    board->addPiece(Type::Bishop, Color::White, 7, 2);
                    board->addPiece(Type::Queen, Color::White, 7, 3);
                    board->addPiece(Type::King, Color::White, 7, 4);
                    board->addPiece(Type::Bishop, Color::White, 7, 5);
                    board->addPiece(Type::Knight, Color::White, 7, 6);
                    board->addPiece(Type::Rook, Color::White, 7, 7);
                    board->addPiece(Type::Pawn, Color::Black, 1, 0);
                    board->addPiece(Type::Pawn, Color::Black, 1, 1);
                    board->addPiece(Type::Pawn, Color::Black, 1, 2);
                    board->addPiece(Type::Pawn, Color::Black, 1, 3);
                    board->addPiece(Type::Pawn, Color::Black, 1, 4);
                    board->addPiece(Type::Pawn, Color::Black, 1, 5);
                    board->addPiece(Type::Pawn, Color::Black, 1, 6);
                    board->addPiece(Type::Pawn, Color::Black, 1, 7);
                    board->addPiece(Type::Rook, Color::Black, 0, 0);
                    board->addPiece(Type::Knight, Color::Black, 0, 1);
                    board->addPiece(Type::Bishop, Color::Black, 0, 2);
                    board->addPiece(Type::Queen, Color::Black, 0, 3);
                    board->addPiece(Type::King, Color::Black, 0, 4);
                    board->addPiece(Type::Bishop, Color::Black, 0, 5);
                    board->addPiece(Type::Knight, Color::Black, 0, 6);
                    board->addPiece(Type::Rook, Color::Black, 0, 7);
                }
                else if (command == "+")
                    char c;
                    std::string pos;
                    std::cin >> c >> pos;
                    switch (c) {
                        case 'K': board->addPiece(Type::King, Color::White, pos[1] - '0', pos[0] - 'a'); break;
                        case 'N': board->addPiece(Type::Knight, Color::White, pos[1] - '0', pos[0] - 'a'); break;
                        case 'B': board->addPiece(Type::Bishop, Color::White, pos[1] - '0', pos[0] - 'a'); break;
                    }
                    board->addPiece(Type::Rook, Color::Black, 0, 7);
                    board->notifyObservers();
            }
        }
    }

    delete Text;
    delete Graphic;
}