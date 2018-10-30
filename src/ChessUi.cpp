#include "ChessUi.hpp"

ChessUi::ChessUi(olc::PixelGameEngine* mEngine, ChessGame& game) : Ui(mEngine), mGame(game) {
    mBoardBorderSz = 8;
    mWhiteTile = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_tile.png");
    mBlackTile = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_tile.png");
    mBoardBorder = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/board.png");
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
}

ChessUi::ChessUi(Ui& ui, ChessGame& game) : Ui(ui), mGame(game) {
    mBoardBorderSz = 8;
    mWhiteTile = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_tile.png");
    mBlackTile = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_tile.png");
    mBoardBorder = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/board.png");
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
}


void ChessUi::drawChessBoard(int x, int y) {
    mEngine->DrawSprite(x, y, mBoardBorder.get());
    for (int forY = 0; forY < 8; forY++) {
        for (int forX = 0; forX < 8; forX++) {
            if (forX % 2 == 0) {
                if (forY % 2 == 0) {
                    mEngine->DrawSprite(x + forX * mWhiteTile->width + mBoardBorderSz, y + forY * mWhiteTile->height + mBoardBorderSz, mWhiteTile.get());
                }
                else {	
                    mEngine->DrawSprite(x + forX * mBlackTile->width + mBoardBorderSz, y + forY * mBlackTile->height + mBoardBorderSz, mBlackTile.get());
                }
            }
            else {
                if (forY % 2 == 0) {
                    mEngine->DrawSprite(x + forX * mBlackTile->width + mBoardBorderSz, x+ forY * mBlackTile->height + mBoardBorderSz, mBlackTile.get());
                }
                else {
                    mEngine->DrawSprite(y + forX * mWhiteTile->width + mBoardBorderSz, y + forY * mWhiteTile->height + mBoardBorderSz, mWhiteTile.get());
                }
            }
            if (mGame.getPieceAt(forX,forY).type() != Piece::Type::Tile) {
                mEngine->SetPixelMode(olc::Pixel::ALPHA);
                ChessPiece temp = mGame.getPieceAt(forX, forY);
                mEngine->DrawSprite(x + forX * mWhiteTile->width + mBoardBorderSz, y + forY * mWhiteTile->height + mBoardBorderSz, mChessPieces[temp.type() + 1 + temp.side() * 6 - 1].get());
                mEngine->SetPixelMode(olc::Pixel::NORMAL);
            }
        }
    }
    for (int forX = 0; forX < ChessBoard::board_width; forX++) {
        mEngine->DrawString(x + forX * mWhiteTile->width + mWhiteTile->width / 2 + mBoardBorderSz, y - mWhiteTile->height / 2 - mBoardBorderSz, std::string(1, ('A' + (char)forX)));
        mEngine->DrawString(x + forX * mWhiteTile->width + mWhiteTile->width / 2 + mBoardBorderSz, y + mWhiteTile->height * 8 + mWhiteTile->height / 2 + mBoardBorderSz, std::string(1, ('A' + (char)forX)));
    }
    for (int forY = 0; forY < ChessBoard::board_height; forY++) {
        mEngine->DrawString(x - mWhiteTile->height / 2 - mBoardBorderSz, y + forY * mWhiteTile->width + mWhiteTile->width / 2 + mBoardBorderSz, std::string(1, ('8' - (char)forY)));
        mEngine->DrawString(x + mWhiteTile->height * 8 + mWhiteTile->height / 2 + mBoardBorderSz, y + forY * mWhiteTile->width + mWhiteTile->width / 2 + mBoardBorderSz, std::string(1, ('8'- (char)forY)));
    }
}


std::string ChessUi::getChessPositionAtMouse(int boardStartX, int boardStartY) {
    int mouseX = (int)mEngine->GetMouseX(), mouseY = (int)mEngine->GetMouseY();
    for (int y = 0; y < ChessBoard::board_height; y++) {
        for (int x = 0; x < ChessBoard::board_width; x++) {
            if (mouseY >= y * mWhiteTile->height + mBoardBorderSz + boardStartY && mouseY <= y * mWhiteTile->height + mBoardBorderSz + mWhiteTile->height + boardStartY)
                if (mouseX >= x * mWhiteTile->width + mBoardBorderSz + boardStartX && mouseX <= x * mWhiteTile->width + mBoardBorderSz + mWhiteTile->width + boardStartX)
                    return ChessPosition::toMove(x, y);
        }
    }
    return "";
}