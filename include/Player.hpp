#pragma once
#include <string>
#include <ChessPiece.hpp>

class Player {
public:
    Player() = default;
    Player(const std::string& name, Piece::Side side) : mName(name), mSide(side) {}
    std::string name() const { return mName; }
    Piece::Side side() const { return mSide; }

private:
    std::string mName;
    Piece::Side mSide;
};