#pragma once
#include <iostream>
#include <ChessBoard.hpp>
#include <utility>
#include <vector>


class ChessGame {
public:
    ChessGame();
    //To-do initialize one instance of a game with move strings eg. A8 A7 which means moved A8 to A7
    //ChessGame(std::string moveList);
    //static std::vector<std::pair<ChessPosition, ChessPosition>>parseStringToMoveList(std::string moveList);
    void move(const std::string& from, const std::string& to);
    void draw() {
        for (int i = 0; i < ChessBoard::board_height*ChessBoard::board_width; i++) {
            std::cout << mBoard->at(i).typeToChar() << (i != 0 && (i + 1) % ChessBoard::board_width == 0 ? "\n" : " ");
        }
    }
    const std::vector<std::pair<ChessPosition, ChessPosition>>& moveList() const { return mMoveList; }


private:
    ChessBoard *mBoard;
    std::vector<std::pair<ChessPosition, ChessPosition>> mMoveList;
    std::string mPlayerOne, mPlayerTwo;
    std::string mPlayerTurn;
};