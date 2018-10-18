#include <iostream>
#include <ChessBoard.hpp>
#include <ChessPosition.hpp>

int main() {
    ChessBoard b;
    ChessPosition start("E8");
    ChessPosition to("D6");
    std::cout << b.isValidMove(start, to, b.at(start)) << std::endl;

    b.movePiece(ChessPosition("A7"), ChessPosition("A6"));
    std::cout << b.at(ChessPosition("A7")).typeToString() << " " << b.at(ChessPosition("A6")).typeToString() << std::endl;
    
    return 0;
}