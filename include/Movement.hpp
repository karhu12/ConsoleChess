#pragma once
#include <ChessPosition.hpp>
#include <ChessPiece.hpp>
#include <cmath>
#include <utility>

class Movement {
public:
    Movement(int xMove, int yMove) {
        mXMove = xMove;
        mYMove = yMove;
    }

    Movement(const ChessPosition& from, const ChessPosition& to) {
        mXMove = to.x() - from.x();
        mYMove = to.y() - from.y();
    }

    //Returns x/y movement to either positive or negative direction
    int x() const { return mXMove; }
    int y() const { return mYMove; }

    //Returns x/y movement switched to positive. eg. -2y would turn into 2. Useful when determining how much piece has moved in general.
    int xMovement() const { return sqrt(pow(mXMove, 2)); }
    int yMovement() const { return sqrt(pow(mYMove,2)); }
    Piece::MoveType type() const;
    static const std::vector<Movement> LShapeMoves;


private:
    int mXMove, mYMove;
};