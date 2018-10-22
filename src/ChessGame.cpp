#include "ChessGame.hpp"

ChessGame::ChessGame() {
    mPlayerOne = Player("White");
    mPlayerTwo = Player("Black");
    mPlayerTurn = mPlayerOne.name();
    mBoard = std::make_unique<ChessBoard>();
}

ChessGame::ChessGame(std::string moveList) {
    mPlayerOne = Player("White");
    mPlayerTwo = Player("Black");
    mPlayerTurn = mPlayerOne.name();
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
        if (mBoard->isValidMove(posFrom, posTo)) {
            mBoard->movePiece(from, to);
            mMoveList.push_back(std::make_pair(posFrom, posTo));
            rotateTurn();
        }
    }
}


bool ChessGame::isPlayerTurn(const ChessPosition& from) {
    if (mPlayerTurn == mPlayerOne.name()) {
        if (mBoard->at(from).side() == Piece::Side::White) {
            return true;
        }
    }
    else if (mBoard->at(from).side() == Piece::Side::Black) {
        return true;
    }
    return false;
}

void ChessGame::rotateTurn() { 
    if (mPlayerTurn == mPlayerOne.name()) {
        mPlayerTurn = mPlayerTwo.name();
    }
    else {
        mPlayerTurn = mPlayerOne.name();
    }
}

void ChessGame::action(const std::string& from, const std::string& to) {
    ChessPosition fromPos(from), toPos(to);
    if (isPlayerTurn(fromPos)) {
        if (isCheck()) {
            std::cout << mPlayerOne.name() << "is in check" << std::endl;
            if (isCheckMate()) {
                std::cout << mPlayerTurn << "Has been checkMated" << std::endl;
            }
        }
        else {
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
                eat(from, to);
            }
        }
    }
    else {
        std::cout << "Not players turn" << std::endl;
    }
    //Prompt incorrect turn?
}

void ChessGame::eat(const std::string& from, const std::string& to) {
    if (ChessPosition::isValidPos(from) && ChessPosition::isValidPos(to)) {
        ChessPosition posFrom(from), posTo(to);
        if (mBoard->isValidEat(posFrom, posTo)) {
            mBoard->movePiece(from, to);
            mMoveList.push_back(std::make_pair(posFrom, posTo));
            rotateTurn();
        }
    }
}

bool ChessGame::isCheck() {
    if (playersTurn() == mPlayerOne.name()) {
        ChessPosition whiteKingPos = mBoard->firstPiecePosition(Piece::Type::King, Piece::Side::White);
        for (auto blackPos : mBoard->piecePositions(Piece::Side::Black)) {
            if (mBoard->isValidEat(blackPos, whiteKingPos))
                return true;
        }
        return false;
    }
    else {
        ChessPosition blackKingPos = mBoard->firstPiecePosition(Piece::Type::King, Piece::Side::Black);
        for (auto whitePos : mBoard->piecePositions(Piece::Side::White)) {
            if (mBoard->isValidEat(whitePos, blackKingPos))
                return true;
        }
        return false;
    }
}

bool ChessGame::isCheckMate() {
    std::vector<ChessPosition> kingMoves;
    std::vector<ChessPosition> opponentPositions;
    //First position is the contestor position and second one is which position is contested
    std::vector<std::pair<ChessPosition, ChessPosition>> contestedKingMoves; 
    std::vector<ChessPosition> contestedPositions;
    //Check if check can be negetated by moving the king
    if (playersTurn() == mPlayerOne.name()) {
        kingMoves = mBoard->pieceMoves(mBoard->firstPiecePosition(Piece::Type::King, Piece::Side::White));
        opponentPositions = mBoard->piecePositions(Piece::Side::Black);
        for (auto opponent : opponentPositions) {
            for (auto kingPosition : kingMoves) {
                if (mBoard->isValidMove(opponent, kingPosition)) {
                    contestedKingMoves.push_back(std::make_pair(opponent, kingPosition));
                    if (std::find(contestedPositions.begin(), contestedPositions.end(), kingPosition) == contestedPositions.end()) {
                        contestedPositions.push_back(kingPosition);
                    }
                }
            }
        }
        //if the check can not be negetated by moving the king see if blocking the route is possible
        if (kingMoves.size() == contestedPositions.size()) {
            std::vector<ChessPosition> allyPositions = mBoard->piecePositions(Piece::Side::White);
            std::vector<std::pair<ChessPosition, std::vector<ChessPosition>>> contestorMoves;
            for (auto contestor : contestedKingMoves) {
                contestorMoves.push_back(std::make_pair(contestor.first, mBoard->movePositions(contestor.first, contestor.second)));
            }
            int contestorsMovesBlocked = 0;
            bool blockedContestorMove = false;
            for (auto contestor : contestorMoves) {
                for (auto blockablePosition : contestor.second) {
                    for (auto ally : allyPositions) {
                        if (mBoard->at(ally).type() == Piece::Type::King) break;
                        if (mBoard->isMoveBlockable(ally, blockablePosition)) {
                            contestorsMovesBlocked++;
                            blockedContestorMove = true;
                            break;
                        }
                    }
                    if (blockedContestorMove) {
                        blockedContestorMove = false;
                        break;
                    }
                }
            }
            //If the moves can not be contested by moving allied pieces attempt to eat the contesting pieces
            if (contestorsMovesBlocked != static_cast<int>(contestorMoves.size())) {
                int contestorsEaten = 0;
                for (auto contestor : contestorMoves) {
                    for (auto ally : allyPositions) {
                        if (mBoard->isValidEat(ally, contestor.first)) {
                            contestorsEaten++;
                            break;
                        }
                    }
                }
                if (contestorsEaten == static_cast<int>(contestorMoves.size()))
                    return false;
                return true;
            }
        }
        return false;
    }
    else {
        
        return false;
    }
}