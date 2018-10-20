#pragma once
#include <iostream>
#include <ChessBoard.hpp>
#include <utility>
#include <vector>
#include <iterator>
#include <sstream>


class ChessGame {
public:
    ChessGame();
    ChessGame(std::string moveList);

    void action(const std::string& from, const std::string& to);
    void move(const std::string& from, const std::string& to);
    void eat(const std::string& from, const std::string& to);

    void draw() {
        for (int i = 0; i < ChessBoard::board_height*ChessBoard::board_width; i++) {
            std::cout << mBoard->at(i).typeToChar() << (i != 0 && (i + 1) % ChessBoard::board_width == 0 ? "\n" : " ");
        }
        std::cout << std::endl;
    }

    const std::vector<std::pair<ChessPosition, ChessPosition>>& moveList() const { return mMoveList; }

    std::string playersTurn() const { return mPlayerTurn; }


private:
    ChessBoard *mBoard;
    std::vector<std::pair<ChessPosition, ChessPosition>> mMoveList;
    std::string mPlayerOne, mPlayerTwo;
    std::string mPlayerTurn;

    void rotateTurn();

    bool isPlayerAllowedMove(const ChessPosition& from);
};