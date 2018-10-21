#pragma once
#include <ChessBoard.hpp>
#include <utility>
#include <vector>

class ChessGame {
public:
    ChessGame();
    ChessGame(std::string moveList);
    static std::vector<std::pair<ChessPosition, ChessPosition>>parseStringToMoveList(std::string moveList);

private:
    ChessBoard *mBoard;
    std::vector<std::pair<ChessPosition, ChessPosition>> mMoveList;
};