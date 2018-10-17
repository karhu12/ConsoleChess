#include <iostream>
#include <ChessBoard.hpp>

int main() {
    ChessBoard b;
    for (int i = 0; i < ChessBoard::board_height * ChessBoard::board_width; i++) {
        std::cout << b.at(i).typeToChar() << (i != 0 && (i + 1) % 8 == 0 ? "\n" : "");
    }
}