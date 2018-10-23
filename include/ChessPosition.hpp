#pragma once
#include <string>

class ChessPosition {
public:
    ChessPosition() { mX = 0; mY = 0; mMove = "A8"; }
    ChessPosition(int index);
    ChessPosition(int xPos, int yPos);
    ChessPosition(const std::string& pos);

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

    static bool isValidPos(const std::string& pos);

    void setPos(int index);
    void setPos(int xPos, int yPos);
    void setPos(const std::string& pos);

private:
    int mX, mY;
    std::string mMove;
    static const std::string moves[2][8];
};