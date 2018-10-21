#pragma once
#include <ChessPiece.hpp>
#include <ChessPosition.hpp>
#include <Movement.hpp>
#include <array>
#include <utility>
#include <memory>

class ChessBoard {
public:
    ChessBoard();

    static constexpr int board_width = 8;
    static constexpr int board_height = 8;
    
    ChessPiece& at(int x, int y) {
        return mBoard[board_height * y + x];
    }

    ChessPiece& at(const ChessPosition& pos) {
        return mBoard[board_height * pos.y() + pos.x()];
    }

    ChessPiece& at(int i) {
        return mBoard[i];
    }

    int indexAt(ChessPosition pos) const {
        return board_height * pos.y() + pos.x(); 
    }

    int indexAt(int x, int y) const {
        return board_height * y + x; 
    }

    const std::array<ChessPiece, board_width * board_height>& board() const { return mBoard; }

    bool isValidMove(const ChessPosition& from, const ChessPosition& to);

    bool isValidEat(const ChessPosition& from, const ChessPosition& to);
    
    static bool isValidPos(int x, int y);

    static bool isPosOutOfBounds(const ChessPosition& pos);

    void movePiece(const ChessPosition& from, const ChessPosition& to);
    
    bool checkCollision(const ChessPosition& from, const ChessPosition& to, bool checkEnd);

    std::vector<ChessPosition> piecePositions(Piece::Type type, Piece::Side side);
    std::vector<ChessPosition> piecePositions(Piece::Side side);
    ChessPosition firstPiecePosition(Piece::Type type, Piece::Side side);
    ChessPosition firstPiecePosition(Piece::Side side);

    std::vector<ChessPosition> movePositions(const ChessPosition& from, const ChessPosition& to);

    std::vector<ChessPosition> pieceMoves(const ChessPosition& piecePos);

private:
    std::array<ChessPiece, board_width * board_height> mBoard;
};