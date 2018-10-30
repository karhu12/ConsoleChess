#pragma once
#include <ChessBoard.hpp>
#include <Player.hpp>
#include <Input.hpp>
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
    ChessGame(const Player& white, const Player& black);
    ChessGame(std::string moveList);

    const ChessPiece& getPieceAt(int x, int y) { return mBoard.at(x,y); }

    void start();

    std::string moveAction(const std::string& from, const std::string& to);
    const std::vector<std::pair<ChessPosition, ChessPosition>>& moveList() const { return mMoveList; }

    Piece::Side playersTurn() const { return mPlayerTurn; }

    bool isCheck();
    bool isCheckMate();

    std::string winner() const { 
        if (!mGameStatus) {
            if (mPlayerTurn == mWhitePlayer.side()) {
                return mWhitePlayer.name();
            }
            else {
                return mBlackPlayer.name();
            }
        }
        return "";
    }


private:
    ChessBoard mBoard;
    std::vector<std::pair<ChessPosition, ChessPosition>> mMoveList;
    Player mWhitePlayer, mBlackPlayer;
    Piece::Side mPlayerTurn;
    bool mGameStatus;
    int mTurn;

    void rotateTurn();

    bool isPlayerTurn(const ChessPosition& from);

    bool move(const std::string& from, const std::string& to);
    
    bool eat(const std::string& from, const std::string& to);

};