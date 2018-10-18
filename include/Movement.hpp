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

    int x() const { return mXMove; }
    int y() const { return mYMove; }
    Piece::MoveType type() const;
    static const std::vector<Movement> LShapeMoves;


private:
    int mXMove, mYMove;
};