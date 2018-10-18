#include <iostream>
#include <ChessBoard.hpp>
#include <ChessPosition.hpp>

int main() {
    ChessBoard b;

    for (int i = 0; i < ChessBoard::board_height * ChessBoard::board_width; i++) {
        std::cout << "Piece: " << b.at(i).typeToString() << " (" << b.at(i).typeToChar() << ") can move " << b.at(i).moveAmount() << " Tiles" << std::endl;
        std::cout << "-Movelist-" << std::endl;
        for (auto i : b.at(i).movesToStrings()) {
            std::cout << "Move " << i << std::endl;
        }
    }
    
    return 0;
}