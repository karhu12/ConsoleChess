#pragma once
#include <ChessBoard.hpp>
#include <Player.hpp>
#include <iostream>
#include <utility>
#include <vector>
#include <iterator>
#include <sstream>
#include <memory>


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

    bool isCheck();
    bool isCheckMate();


private:
    std::unique_ptr<ChessBoard> mBoard;
    std::vector<std::pair<ChessPosition, ChessPosition>> mMoveList;
    Player mPlayerOne, mPlayerTwo;
    std::string mPlayerTurn;

    void rotateTurn();

    bool isPlayerTurn(const ChessPosition& from);
};