#pragma once
#include <string>
#include <vector>
#include <ChessPosition.hpp>

namespace Piece {
    const std::string typeStrings[7] = { "King", "Queen", "Rook", "Bishop", "Knight", "Pawn", "Tile" };
    enum Type { King, Queen, Rook, Bishop, Knight, Pawn, Tile };
    const std::string sideStrings[3] = { "Black", "White", "None" };
    enum Side { Black, White, None };
    const std::string moveTypeStrings[5] = { "Horizontal", "Vertical", "Diagonal", "LShape", "Invalid" };
    enum MoveType { Invalid, Horizontal, Vertical, Diagonal, LShape };
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

    static std::string moveTypeToString(Piece::MoveType move) { return Piece::moveTypeStrings[move]; }

    int moveAmount() const { return mMoveAmount; }

    void setMoveAmount(int amount) { mMoveAmount = amount; }
    
private:
    Piece::Type mPieceType;
    Piece::Side mPieceSide;
    std::vector<Piece::MoveType> mMoves;
    int mMoveAmount;
};