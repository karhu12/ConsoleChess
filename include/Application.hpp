#pragma once
#include <olcPixelGameEngine.h>
#include <ChessGame.hpp>

class Application : public olc::PixelGameEngine {
public:
	Application();

public:
	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

	void drawChessBoard(int x, int y);

	

private:
	std::unique_ptr<ChessGame> mGame;
    std::unique_ptr<olc::Sprite> mWhiteTile;
    std::unique_ptr<olc::Sprite> mBlackTile;
    std::unique_ptr<olc::Sprite> mBoardBorder;
	std::vector<std::unique_ptr<olc::Sprite>> mChessPieces;
	int mBoardBorderSz;
};
