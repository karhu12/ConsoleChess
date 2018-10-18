#include "ChessPosition.hpp"

const std::string ChessPosition::moves[2][8] = {
    { "A", "B", "C", "D", "E", "F", "G", "H" },
    { "8", "7", "6", "5", "4", "3", "2", "1" }
};

ChessPosition::ChessPosition(int xPos, int yPos) {
    mX = xPos;
    mY = yPos;
    mMove = toMove(mX, mY);
}

ChessPosition::ChessPosition(std::string pos) {
    mX = 0; mY = 0; mMove = "A8";
    if ( (pos[0] >= 'a' && pos[0] <= 'h') || (pos[0] >= 'A' && pos[0] <= 'H') ) {
        if (pos[1] >= '1' && pos[1] <= '8') {
            mMove = pos[0] + pos[1];        
        }
    }
    //get x and y position based of the string position
    for (int i = 0; i < 8; i++) {
        if (ChessPosition::moves[0][i].at(0) == pos[0]) {
            mX = i;
        }
        if (ChessPosition::moves[1][i].at(0) == pos[1]) {
            mY = i;
        }
    }
}

std::string ChessPosition::toMove(int xPos, int yPos) {
    return moves[0][xPos] + moves[1][yPos];
}