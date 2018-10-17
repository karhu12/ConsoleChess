#pragma once
#include <ChessPiece.hpp>
#include <array>
#include <utility>
#include <memory>

class ChessBoard {
public:

    ChessBoard();
    ~ChessBoard();
    static constexpr int board_width = 8;
    static constexpr int board_height = 8;

private:
    std::array<std::unique_ptr<ChessPiece>, board_width * board_height> mBoard;
};