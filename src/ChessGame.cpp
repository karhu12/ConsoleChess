#include "ChessGame.hpp"

ChessGame::ChessGame() {
    mWhitePlayer = Player("White", Piece::Side::White);
    mBlackPlayer = Player("Black", Piece::Side::Black);
    mPlayerTurn = mWhitePlayer.side();
    mBoard = std::make_unique<ChessBoard>();
}

ChessGame::ChessGame(std::string moveList) {
    mWhitePlayer = Player("White", Piece::Side::White);
    mBlackPlayer = Player("Black", Piece::Side::Black);
    mPlayerTurn = mWhitePlayer.side();
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

bool ChessGame::move(const std::string& from, const std::string& to) {
    if (ChessPosition::isValidPos(from) && ChessPosition::isValidPos(to)) {
        ChessPosition posFrom(from), posTo(to);
        if (mBoard->isValidMove(posFrom, posTo)) {
            mBoard->movePiece(from, to);
            if (isCheck()) {
                mBoard->movePiece(to, from);
            }
            else {
                mMoveList.push_back(std::make_pair(posFrom, posTo));
                rotateTurn();
                if (isCheck()) {
                    std::cout << "Opponent Checked" << std::endl;
                    if (isCheckMate()) {
                        std::cout << "Opponent check mated" << std::endl;
                    }
                }
                return true;
            }
        }
    }
    return false;
}


bool ChessGame::isPlayerTurn(const ChessPosition& from) {
    if (mPlayerTurn == mWhitePlayer.side()) {
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
    if (mPlayerTurn == mWhitePlayer.side()) {
        mPlayerTurn = mBlackPlayer.side();
    }
    else {
        mPlayerTurn = mWhitePlayer.side();
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
            std::cout << "Move from " << from << " To " << to << std::endl;
            if (!move(from, to)) std::cout << "Invalid move" << std::endl;
        }
        else if (mBoard->at(fromPos).side() != mBoard->at(toPos).side()) {
            std::cout << "Eat from " << from << " To " << to << std::endl;
            if (!eat(from, to)) std::cout << "Invalid eat" << std::endl;
        }
    }
    else {
        std::cout << "Not players turn" << std::endl;
    }
}

//Attempt to eat the piece from "to" position with piece at "from" position
bool ChessGame::eat(const std::string& from, const std::string& to) {
    if (ChessPosition::isValidPos(from) && ChessPosition::isValidPos(to)) {
        ChessPosition posFrom(from), posTo(to);
        if (mBoard->isValidEat(posFrom, posTo)) {
            ChessPiece temp = mBoard->at(to);
            mBoard->movePiece(from, to);
            if (isCheck()) {
                mBoard->movePiece(to, from);
                mBoard->at(to) = temp;
            }
            else {
                mMoveList.push_back(std::make_pair(posFrom, posTo));
                rotateTurn();
                if (isCheck()) {
                    std::cout << "Opponent Checked" << std::endl;
                    if (isCheckMate()) {
                        std::cout << "Opponent check mated" << std::endl;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

//Checks if the game is in check with current players turn
bool ChessGame::isCheck() {
    Piece::Side currentSide = playersTurn();
    Piece::Side opponentSide = (currentSide == Piece::Side::White ? Piece::Side::Black : Piece::Side::White);
    ChessPosition kingPos = mBoard->firstPiecePosition(Piece::Type::King, currentSide);
    for (auto opponentPos : mBoard->piecePositions(opponentSide)) {
        if (mBoard->isValidEat(opponentPos, kingPos))
            return true;
    }
    return false;
}

//Checks if the game is in check mate with current players turn
bool ChessGame::isCheckMate() {
    Piece::Side playerSide = playersTurn();
    Piece::Side opponentSide = (playerSide == Piece::Side::White ? Piece::Side::Black : Piece::Side::White);

    ChessPosition kingPosition = mBoard->firstPiecePosition(Piece::Type::King, playerSide);
    std::vector<ChessPosition> kingMoves;
    std::vector<ChessPosition> opponentPositions;

    //First position is the contestor position and second one is which position is contested
    std::vector<std::pair<ChessPosition, ChessPosition>> contestedKingMoves; 

    std::vector<ChessPosition> contestedPositions;
    //Check if check can be negetated by moving the king
    kingMoves = mBoard->pieceMovePositions(kingPosition);
    opponentPositions = mBoard->piecePositions(opponentSide);
    for (auto opponent : opponentPositions) {
        for (auto kingMove : kingMoves) {
            if (mBoard->isValidMove(opponent, kingMove, true)) {
                contestedKingMoves.push_back(std::make_pair(opponent, kingMove));
                //Compare if position has already been contested, if not add position to contested positions
                if (std::find(contestedPositions.begin(), contestedPositions.end(), kingMove) == contestedPositions.end()) {
                    contestedPositions.push_back(kingMove);
                }
            }
        }
    }
    //if the check can not be negetated by moving the king or the king has no moves then see if blocking the route is possible
    if (kingMoves.size() == contestedPositions.size()) {
        std::vector<ChessPosition> allyPositions = mBoard->piecePositions(playerSide);
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
                        if (mBoard->isValidMove(ally, blockablePosition)) {
                            ChessPiece temp = mBoard->at(blockablePosition);
                            mBoard->movePiece(ally, blockablePosition);
                            if (!isCheck()) {
                                blockedContestorMove = true;
                                contestorsMovesBlocked++;
                                mBoard->movePiece(blockablePosition, ally);
                                mBoard->at(blockablePosition) = temp;
                                break;
                            }
                            mBoard->movePiece(blockablePosition, ally);
                            mBoard->at(blockablePosition) = temp;
                        }
                    }
                }
                if (blockedContestorMove) {
                    blockedContestorMove = false;
                    break;
                }
            }
        }
        //If the moves can not be contested by moving allied pieces attempt to eat the contesting pieces
        if (contestorsMovesBlocked != static_cast<int>(contestorMoves.size()) || kingMoves.size() == 0) {
            //If the move has no moves it can be assumed that a knight has resulted the check
            if (kingMoves.size() == 0) {
                for (auto it : mBoard->piecePositions(Piece::Type::Knight, opponentSide)) {
                    if (mBoard->isValidEat(it, kingPosition)) {
                        contestorMoves.push_back(std::make_pair(it, std::vector<ChessPosition>{kingPosition}));
                    }
                }
            }
            int contestorsEaten = 0;
            for (auto contestor : contestorMoves) {
                for (auto ally : allyPositions) {
                    if (mBoard->isValidEat(ally, contestor.first)) {
                        ChessPiece temp = mBoard->at(contestor.first);
                        mBoard->movePiece(ally, contestor.first);
                        if (!isCheck()) {
                            contestorsEaten++;
                            break;
                        }
                        mBoard->movePiece(contestor.first, ally);
                        mBoard->at(contestor.first) = temp;
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