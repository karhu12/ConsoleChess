#pragma once
#include <Ui.hpp>

class ChessUi : public Ui {
public:
    ChessUi(olc::PixelGameEngine* pge, ChessGame& game);
    ChessUi(Ui& ui, ChessGame& game);

    void draw(int x, int y) override {
        drawChessBoard(x, y);
    }

    void drawChessBoard(int x, int y);

    std::string getChessPositionAtMouse(int boardStartX, int boardStartY);

private:
    std::unique_ptr<olc::Sprite> mWhiteTile;
    std::unique_ptr<olc::Sprite> mBlackTile;
    std::unique_ptr<olc::Sprite> mBoardBorder;
	std::vector<std::unique_ptr<olc::Sprite>> mChessPieces;
    ChessGame& mGame;
	int mBoardBorderSz;
};