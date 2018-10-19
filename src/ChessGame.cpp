#include "ChessGame.hpp"

ChessGame::ChessGame() {
    mPlayerOne = "White";
    mPlayerTwo = "Black";
    mPlayerTurn = mPlayerOne;
    mBoard = new ChessBoard();
}

/* 
ChessGame::ChessGame(std::string moveList) {
    
}

std::vector<std::pair<ChessPosition, ChessPosition>> ChessGame::parseStringToMoveList(std::string moveList) {

}*/

void ChessGame::move(const std::string& from, const std::string& to) {
    if (ChessPosition::isValidPos(from) && ChessPosition::isValidPos(to)) {
        ChessPosition posFrom(from), posTo(to);
        if (mBoard->isValidMove(posFrom, posTo, mBoard->at(posFrom))) {
            mBoard->movePiece(from, to);
            mMoveList.push_back(std::make_pair(posFrom, posTo));
        }
    }
}