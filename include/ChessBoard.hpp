#pragma once
#include <ChessPiece.hpp>
#include <array>
#include <utility>
#include <memory>

class ChessBoard {
public:
    ChessBoard();
    static constexpr int board_width = 8;
    static constexpr int board_height = 8;
    const ChessPiece& at(int x, int y) {
        return mBoard[board_height * y + x];
    }
    const ChessPiece& at(int i) {
        return mBoard[i];
    } 

private:
    std::array<ChessPiece, board_width * board_height> mBoard;
};