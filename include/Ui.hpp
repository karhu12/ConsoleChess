#pragma once
#include <olcPixelGameEngine.h>
#include <ChessGame.hpp>

class Ui : public olc::PixelGameEngine {
public:
	Ui();
	~Ui();

public:
	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

	void drawChessBoard(int x, int y);

	

private:
	ChessGame* game;
    olc::Sprite* mWhiteTile;
    olc::Sprite* mBlackTile;
    olc::Sprite* mBoardBorder;
	int mBoardBorderSz;
};
