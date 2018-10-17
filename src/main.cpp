#include <iostream>
#include <ChessPiece.hpp>

int main() {
    ChessPiece piece(Piece::Rook, Piece::Black) ;

    std::cout << "Piece type: " << piece.typeToString() << " + as int: " << piece.type() << std::endl;
}