#include "Ui.hpp"

Ui::Ui() {
	sAppName = "Console Chess";
}

Ui::~Ui() {
    delete mWhiteTile;
    delete mBlackTile;
    delete mBoardBorder;
}

bool Ui::OnUserCreate() {
    mWhiteTile = new olc::Sprite("D:/Ohjelmointi/ConsoleChess/images/white_tile.png");
    mBlackTile = new olc::Sprite("D:/Ohjelmointi/ConsoleChess/images/black_tile.png");
    mBoardBorder = new olc::Sprite("D:/Ohjelmointi/ConsoleChess/images/board.png");
    mBoardBorderSz = ((mBoardBorder->width - (mWhiteTile->width * 8)) / 2);
    game = new ChessGame();
    return true;
}

bool Ui::OnUserUpdate(float fElapsedTime)  {
    drawChessBoard(50, 50);
    return true;
}

void Ui::drawChessBoard(int x, int y) {
    DrawSprite(x, y, mBoardBorder);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    DrawSprite(x + i * mWhiteTile->width + mBoardBorderSz, y + j * mWhiteTile->height + mBoardBorderSz, mWhiteTile);
                    DrawString(x + i * mWhiteTile->width + (mWhiteTile->width / 2) + mBoardBorderSz, y + j * mWhiteTile->height + (mWhiteTile->height / 2)+ mBoardBorderSz, std::string(1, game->getPieceAt(i,j)), olc::DARK_CYAN);
                }
                else {	
                    DrawSprite(x + i * mBlackTile->width + mBoardBorderSz, y + j * mBlackTile->height + mBoardBorderSz, mBlackTile);
                    DrawString(x + i * mWhiteTile->width + (mWhiteTile->width / 2) + mBoardBorderSz, y + j * mWhiteTile->height + (mWhiteTile->height / 2)+ mBoardBorderSz, std::string(1, game->getPieceAt(i,j)), olc::DARK_CYAN);
                }
            }
            else {
                if (j % 2 == 0) {
                    DrawSprite(x + i * mBlackTile->width + mBoardBorderSz, x+ j * mBlackTile->height + mBoardBorderSz, mBlackTile);
                    DrawString(x + i * mWhiteTile->width + (mWhiteTile->width / 2) + mBoardBorderSz, y + j * mWhiteTile->height + (mWhiteTile->height / 2)+ mBoardBorderSz, std::string(1, game->getPieceAt(i,j)), olc::DARK_CYAN);
                }
                else {
                    DrawSprite(y + i * mWhiteTile->width + mBoardBorderSz, y + j * mWhiteTile->height + mBoardBorderSz, mWhiteTile);
                    DrawString(x + i * mWhiteTile->width + (mWhiteTile->width / 2) + mBoardBorderSz, y + j * mWhiteTile->height + (mWhiteTile->height / 2) + mBoardBorderSz, std::string(1, game->getPieceAt(i,j)), olc::DARK_CYAN);
                }
            }
        }
    }
}