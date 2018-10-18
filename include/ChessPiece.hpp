#pragma once
#include <string>
#include <vector>
#include <ChessPosition.hpp>

namespace Piece {
    const std::string typeStrings[7] = { "Tile", "King", "Queen", "Rook", "Bishop", "Knight", "Pawn" };
    enum Type { Tile, King, Queen, Rook, Bishop, Knight, Pawn };
    const std::string sideStrings[3] = { "None", "Black", "White" };
    enum Side { None, Black, White };
    const std::string moveTypeStrings[4] = { "Horizontal", "Vertical", "Diagonal", "LShape" };
    enum MoveType { Horizontal, Vertical, Diagonal, LShape };
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
    const std::vector<Piece::MoveType>& moves() const { return mMoves; }
    std::vector<std::string> movesToStrings() const {
        std::vector<std::string> movesAsStrings;
        for (auto it : mMoves) {
            movesAsStrings.push_back(Piece::moveTypeStrings[it]);
        }
        return movesAsStrings;
    }
    int moveAmount() const { return mMoveAmount; }
    
private:
    Piece::Type mPieceType;
    Piece::Side mPieceSide;
    std::vector<Piece::MoveType> mMoves;
    int mMoveAmount;
};