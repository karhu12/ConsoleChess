#include "ChessGame.hpp"

ChessGame::ChessGame() {
    mPlayerOne = "White";
    mPlayerTwo = "Black";
    mPlayerTurn = mPlayerOne;
    mBoard = new ChessBoard();
}

ChessGame::ChessGame(std::string moveList) {
    mPlayerOne = "White";
    mPlayerTwo = "Black";
    mPlayerTurn = mPlayerOne;
    mBoard = new ChessBoard();

    std::istringstream ss{moveList};
    using StrIt = std::istream_iterator<std::string>;
    std::vector<std::string> moves{StrIt{ss}, StrIt{}};

    int movesVerified = 0;
    while (movesVerified < static_cast<int>(moves.size()) && movesVerified + 1 != static_cast<int>(moves.size())) {
        move(moves[movesVerified], moves[movesVerified + 1]);
        movesVerified += 2;
    }
}

void ChessGame::move(const std::string& from, const std::string& to) {
    if (ChessPosition::isValidPos(from) && ChessPosition::isValidPos(to)) {
        ChessPosition posFrom(from), posTo(to);
        if (isPlayerAllowedMove(posFrom)) {
            if (mBoard->isValidMove(posFrom, posTo)) {
                mBoard->movePiece(from, to);
                mMoveList.push_back(std::make_pair(posFrom, posTo));
                rotateTurn();
            }
        }
    }
}


bool ChessGame::isPlayerAllowedMove(const ChessPosition& from) {
    if (mPlayerTurn == mPlayerOne) {
        if (mBoard->at(from).side() == Piece::Side::White) {
            return true;
        }
    }
    if (mBoard->at(from).side() == Piece::Side::Black) {
        return true;
    }
    return false;
}

void ChessGame::rotateTurn() { 
    if (mPlayerTurn == mPlayerOne) {
        mPlayerTurn = mPlayerTwo;
    }
    else {
        mPlayerTurn = mPlayerOne;
    }
}

void ChessGame::action(const std::string& from, const std::string& to) {
    
}