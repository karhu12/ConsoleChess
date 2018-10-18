#pragma once
#include <string>

class ChessPosition {
public:
    ChessPosition(int xPos, int yPos);
    ChessPosition(std::string pos);
    static std::string toMove(int xPos, int yPos);
    int x() const { return mX; }
    int y() const { return mY; }
    std::string move() const { return mMove; }
    bool operator== (const ChessPosition& compare) const {
        if (this->x() == compare.x() && this->y() == compare.y()) {
            return true;
        }
        return false;
    }
    

private:
    int mX, mY;
    std::string mMove;
    static const std::string moves[2][8];
};