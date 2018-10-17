#include <iostream>
#include <ChessBoard.hpp>
#include <ChessPosition.hpp>

int main() {
    std::cout << "x0 y0: " << ChessPosition::toMove(0, 0) << ", x3, y4: " << ChessPosition::toMove(3, 4) << std::endl;
    return 0;
}