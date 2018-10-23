#pragma once
#include <ChessBoard.hpp>
#include <Player.hpp>
#include <iostream>
#include <utility>
#include <vector>
#include <iterator>
#include <sstream>
#include <memory>
#include <algorithm>


class ChessGame {
public:
    ChessGame();
    ChessGame(std::string moveList);

    void action(const std::string& from, const std::string& to);

    bool move(const std::string& from, const std::string& to);
    
    bool eat(const std::string& from, const std::string& to);

    void draw() {
        std::cout << "A B C D E F G H" << std::endl;
        std::cout << "---------------" << std::endl;
        for (int i = 0; i < ChessBoard::board_height*ChessBoard::board_width; i++) {
            std::cout << mBoard->at(i).typeToChar() << (i != 0 && (i + 1) % ChessBoard::board_width == 0 ? " | " + std::to_string(8 - (i / 8)) + "\n" : " ");
        }
        std::cout << std::endl;
    }

    const std::vector<std::pair<ChessPosition, ChessPosition>>& moveList() const { return mMoveList; }

    Piece::Side playersTurn() const { return mPlayerTurn; }

    bool isCheck();
    bool isCheckMate();


private:
    std::unique_ptr<ChessBoard> mBoard;
    std::vector<std::pair<ChessPosition, ChessPosition>> mMoveList;
    Player mWhitePlayer, mBlackPlayer;
    Piece::Side mPlayerTurn;

    void rotateTurn();

    bool isPlayerTurn(const ChessPosition& from);
};