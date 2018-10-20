#include <ChessGame.hpp>

int main() {
    
    ChessBoard b;
    b.movePiece(ChessPosition("D7"), ChessPosition("D6"));
    ChessPosition from("D8");
    ChessPosition to("D6");
    Movement move(from, to);
    std::cout << std::boolalpha;
    std::cout << b.at(from).typeToString() << " at " << from.move() << " to " << to.move() << " where " << b.at(to).typeToString() << ", Collision: " << b.checkCollision(from, to, move.type()) << std::endl;


    return 0;
}