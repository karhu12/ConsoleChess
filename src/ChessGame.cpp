#include "ChessGame.hpp"

ChessGame::ChessGame() {
    mPlayerOne = "White";
    mPlayerTwo = "Black";
    mPlayerTurn = mPlayerOne;
    mBoard = std::make_unique<ChessBoard>();
}

ChessGame::ChessGame(std::string moveList) {
    mPlayerOne = "White";
    mPlayerTwo = "Black";
    mPlayerTurn = mPlayerOne;
    mBoard = std::make_unique<ChessBoard>();

    std::istringstream ss{moveList};
    using StrIt = std::istream_iterator<std::string>;
    std::vector<std::string> moves{StrIt{ss}, StrIt{}};

    int movesVerified = 0;
    while (movesVerified < static_cast<int>(moves.size()) && movesVerified + 1 != static_cast<int>(moves.size())) {
        action(moves[movesVerified], moves[movesVerified + 1]);
        movesVerified += 2;
    }
}

void ChessGame::move(const std::string& from, const std::string& to) {
    if (ChessPosition::isValidPos(from) && ChessPosition::isValidPos(to)) {
        ChessPosition posFrom(from), posTo(to);
        if (isPlayerTurn(posFrom)) {
            if (mBoard->isValidMove(posFrom, posTo)) {
                mBoard->movePiece(from, to);
                mMoveList.push_back(std::make_pair(posFrom, posTo));
                rotateTurn();
            }
        }
    }
}


bool ChessGame::isPlayerTurn(const ChessPosition& from) {
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
    ChessPosition fromPos(from), toPos(to);
    if (isPlayerTurn(fromPos)) {
        if (mBoard->at(fromPos).side() == Piece::Side::None) {
            std::cout << "Cannot do actions to tiles" << std::endl;
        }
        else if (mBoard->at(fromPos).side() == mBoard->at(toPos).side()) {
            std::cout << "Cannot eat/move to your own piece" << std::endl;
        }
        else if (mBoard->at(toPos).side() == Piece::Side::None) {
            std::cout << "Move" << std::endl;
            move(from, to);
        }
        else if (mBoard->at(fromPos).side() != mBoard->at(toPos).side()) {
            std::cout << "Eat" << std::endl;
            //eat
        }
    }
    else {
        std::cout << "Not players turn" << std::endl;
    }
    //Prompt incorrect turn?
}