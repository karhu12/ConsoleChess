#pragma once
#include <string>

class ChessPosition {
public:
    ChessPosition(int xPos, int yPos);
    ChessPosition(std::string pos);
    static std::string toMove(int xPos, int yPos);
    

private:
    int mX, mY;
    std::string mMove;
    static const std::string moves[2][8];
};