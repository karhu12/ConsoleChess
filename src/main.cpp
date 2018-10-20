#include <ChessGame.hpp>

int main() {
    
    ChessBoard b;
    b.movePiece(ChessPosition("D8"), ChessPosition("D4"));
    ChessPosition from("D4");
    ChessPosition to("A7");
    std::cout << std::boolalpha;
    std::cout << b.at(from).typeToString() << " at " << from.move() << " to " << to.move() << " where " << b.at(to).typeToString() << ", Collision: " << b.checkCollision(from, to, Piece::MoveType::Diagonal) << std::endl;


    return 0;
}