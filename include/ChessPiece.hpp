#pragma once
#include <string>

namespace Piece {
    const std::string typeStrings[7] = { "Tile", "King", "Queen", "Rook", "Bishop", "Knight", "Pawn" };
    enum Type { Tile, King, Queen, Rook, Bishop, Knight, Pawn };
    enum Side { None, Black, White };
}

class ChessPiece {
public:
    ChessPiece(Piece::Type type, Piece::Side side);
    std::string typeToString() const {
        return Piece::typeStrings[static_cast<int>(mPieceType)];
    }
    int type() const { return static_cast<int>(mPieceType); }
    int side() const { return mPieceSide; }
    
private:
    Piece::Type mPieceType;
    Piece::Side mPieceSide;
};