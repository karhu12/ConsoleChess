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
    
    const ChessPiece& at(int x, int y) const {
        return mBoard[board_height * y + x];
    }

    const ChessPiece& at(const ChessPosition& pos) const {
        return mBoard[board_height * pos.y() + pos.x()];
    }

    const ChessPiece& at(int i) const {
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
    
    static bool isValidPos(int x, int y);

    static bool isPosOutOfBounds(const ChessPosition& pos);

    void movePiece(const ChessPosition& from, const ChessPosition& to);

private:
    std::array<ChessPiece, board_width * board_height> mBoard;
    bool checkCollision(const ChessPosition& from, const ChessPosition& to, Piece::MoveType moveType); 
};