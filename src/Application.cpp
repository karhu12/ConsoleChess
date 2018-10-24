#include "Application.hpp"

Application::Application() {
	sAppName = "Console Chess";
    mGame = std::make_unique<ChessGame>();
}

bool Application::OnUserCreate() {
    mWhiteTile = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_tile.png");
    mBlackTile = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_tile.png");
    mBoardBorder = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/board.png");
    mBoardBorderSz = ((mBoardBorder->width - (mWhiteTile->width * 8)) / 2);
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_king.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_queen.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_rook.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_bishop.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_knight.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_pawn.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_king.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_queen.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_rook.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_bishop.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_knight.png"));
    mChessPieces.push_back(std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_pawn.png"));
    return true;
}

bool Application::OnUserUpdate(float fElapsedTime)  {
    drawChessBoard(50, 50);
    return true;
}

void Application::drawChessBoard(int x, int y) {
    DrawSprite(x, y, mBoardBorder.get());
    for (int forY = 0; forY < 8; forY++) {
        for (int forX = 0; forX < 8; forX++) {
            if (forX % 2 == 0) {
                if (forY % 2 == 0) {
                    DrawSprite(x + forX * mWhiteTile->width + mBoardBorderSz, y + forY * mWhiteTile->height + mBoardBorderSz, mWhiteTile.get());
                }
                else {	
                    DrawSprite(x + forX * mBlackTile->width + mBoardBorderSz, y + forY * mBlackTile->height + mBoardBorderSz, mBlackTile.get());
                }
            }
            else {
                if (forY % 2 == 0) {
                    DrawSprite(x + forX * mBlackTile->width + mBoardBorderSz, x+ forY * mBlackTile->height + mBoardBorderSz, mBlackTile.get());
                }
                else {
                    DrawSprite(y + forX * mWhiteTile->width + mBoardBorderSz, y + forY * mWhiteTile->height + mBoardBorderSz, mWhiteTile.get());
                }
            }
            if (mGame->getPieceAt(forX,forY).type() != Piece::Type::Tile) {
                SetPixelMode(olc::Pixel::ALPHA);
                ChessPiece temp = mGame->getPieceAt(forX, forY);
                DrawSprite(x + forX * mWhiteTile->width + mBoardBorderSz, y + forY * mWhiteTile->height + mBoardBorderSz, mChessPieces[temp.type() + 1 + temp.side() * 6 - 1].get());
                SetPixelMode(olc::Pixel::NORMAL);
            }
        }
    }
    for (int forX = 0; forX < ChessBoard::board_width; forX++) {
        DrawString(x + forX * mWhiteTile->width + mWhiteTile->width / 2 + mBoardBorderSz, y - mWhiteTile->height / 2 - mBoardBorderSz, std::string(1, ('A' + (char)forX)));
        DrawString(x + forX * mWhiteTile->width + mWhiteTile->width / 2 + mBoardBorderSz, y + mWhiteTile->height * 8 + mWhiteTile->height / 2 + mBoardBorderSz, std::string(1, ('A' + (char)forX)));
    }
    for (int forY = 0; forY < ChessBoard::board_height; forY++) {
        DrawString(x - mWhiteTile->height / 2 - mBoardBorderSz, y + forY * mWhiteTile->width + mWhiteTile->width / 2 + mBoardBorderSz, std::string(1, ('8' - (char)forY)));
        DrawString(x + mWhiteTile->height * 8 + mWhiteTile->height / 2 + mBoardBorderSz, y + forY * mWhiteTile->width + mWhiteTile->width / 2 + mBoardBorderSz, std::string(1, ('8'- (char)forY)));
    }
}