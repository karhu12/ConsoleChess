#include <iostream>
#include <ChessBoard.hpp>
#include <ChessPosition.hpp>

int main() {
    ChessBoard b;
    ChessPosition start("E8");
    ChessPosition to("D6");
    std::cout << b.isValidMove(start, to, b.at(start)) << std::endl;
    
    return 0;
}