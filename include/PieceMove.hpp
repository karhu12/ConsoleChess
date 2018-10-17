#pragma once

class PieceMove {
public:
    PieceMove(int horizontalMovement, int verticalMovement) {
        mVerticalMovement = verticalMovement;
        mHorizontalMovement = horizontalMovement;
    }
    int horizontal() const { return mHorizontalMovement; }
    int vertical() const { return mVerticalMovement; }
    
private:
    int mVerticalMovement, mHorizontalMovement;
};