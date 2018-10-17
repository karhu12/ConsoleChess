#pragma once
#include <string>
#include <vector>
#include <PieceMove.hpp>

namespace Piece {
    const std::string typeStrings[7] = { "Tile", "King", "Queen", "Rook", "Bishop", "Knight", "Pawn" };
    enum Type { Tile, King, Queen, Rook, Bishop, Knight, Pawn };
    const std::string sideStrings[3] = { "None", "Black", "White" };
    enum Side { None, Black, White };
    const std::vector<PieceMove> moves[7] = {
        std::vector<PieceMove> {},
        std::vector<PieceMove> { PieceMove(-1, -1), PieceMove(-1, 1), PieceMove(1, -1), PieceMove(1, 1), PieceMove(0, -1), PieceMove(0, 1), PieceMove(1, 0), PieceMove(-1, 0) },
        std::vector<PieceMove> {},
        std::vector<PieceMove> {},
        std::vector<PieceMove> {},
        std::vector<PieceMove> {},
        std::vector<PieceMove> {}
    };
}

class ChessPiece {
public:
    ChessPiece() {}
    ChessPiece(Piece::Type type, Piece::Side side);
    std::string typeToString() const {
        return Piece::typeStrings[static_cast<int>(mPieceType)];
    }
    char typeToChar() const {
        return Piece::typeStrings[static_cast<int>(mPieceType)][0];
    }
    int type() const { return static_cast<int>(mPieceType); }
    std::string sideToString() const {
        return Piece::sideStrings[static_cast<int>(mPieceSide)];
    }
    int side() const { return mPieceSide; }
    
private:
    Piece::Type mPieceType;
    Piece::Side mPieceSide;
};