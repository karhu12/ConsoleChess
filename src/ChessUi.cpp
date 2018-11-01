#include "ChessUi.hpp"

ChessUi::ChessUi(olc::PixelGameEngine* mEngine, ChessGame& game) : Ui(mEngine), mGame(game) {
    mSprites["White Tile"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_tile.png");
    mSprites["Black Tile"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_tile.png");
    mSprites["Board"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/board.png");
    mSprites["Black King"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_king.png");
    mSprites["Black Queen"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_queen.png");
    mSprites["Black Rook"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_rook.png");
    mSprites["Black Bishop"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_bishop.png");
    mSprites["Black Knight"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_knight.png");
    mSprites["Black Pawn"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/black_pawn.png");
    mSprites["White King"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_king.png");
    mSprites["White Queen"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_queen.png");
    mSprites["White Rook"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_rook.png");
    mSprites["White Bishop"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_bishop.png");
    mSprites["White Knight"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_knight.png");
    mSprites["White Pawn"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/white_pawn.png");

    mElements["Board"] = Element(0, 0, mSprites["Board"].get(), "Board");
    for (char l = 'A'; l <= 'H'; l++) {
        for (char n = '8'; n >= '1'; n--) {
            std::string chPosStr = std::string() + l + n;
            ChessPosition chPos(chPosStr);
            mElements[chPos.move()] = Element(chPos.x() * TileSize + BorderSize, chPos.y() * TileSize + BorderSize, mSprites[tileColorAt(chPos.move())].get(), chPos.move());
        }
    }
}

void ChessUi::draw(int x, int y) {
    int pieces = 0;
    //Temporary solution to keep track of the pieces on ui
    //We load the chess piece elements to the element map every time we make a draw call and remove them after using them to keep it dynamic
    for (char l = 'A'; l <= 'H'; l++) {
        for (char n = '8'; n >= '1'; n--) {
            std::string chPosStr = std::string() + l + n;
            ChessPosition chPos(chPosStr);
            ChessPiece pc = mGame.getPieceAt(chPos.x(), chPos.y());
            if (pc.type() != Piece::Type::Tile) {
                //Gets the name of piece eg. "Black Rook" which is used to load the sprite
                std::string pieceName = pc.sideToString() + " " + pc.typeToString();
                mElements["Piece" + std::to_string(pieces++)] = Element(chPos.x() * TileSize + BorderSize, chPos.y() * TileSize + BorderSize, mSprites[pieceName].get(), pieceName);
            }
        }
    }
    mOffsetX = x; mOffsetY = y;
    mEngine->SetPixelMode(olc::Pixel::ALPHA);
    drawElements(x, y);
    mEngine->SetPixelMode(olc::Pixel::NORMAL);
    while (pieces >= 0)
        mElements.erase("Piece" + std::to_string(pieces--));

    for (int forX = 0; forX < ChessBoard::board_width; forX++) {
        mEngine->DrawString(x + forX * TileSize + TileSize * 0.5 + BorderSize, y - TileSize * 0.5 - BorderSize, std::string(1, ('A' + (char)forX)));
        mEngine->DrawString(x + forX * TileSize + TileSize * 0.5 + BorderSize, y + TileSize * 8 + TileSize * 0.5 + BorderSize, std::string(1, ('A' + (char)forX)));
    }
    for (int forY = 0; forY < ChessBoard::board_height; forY++) {
        mEngine->DrawString(x - TileSize * 0.5 - BorderSize, y + forY * TileSize + TileSize * 0.5 + BorderSize, std::string(1, ('8' - (char)forY)));
        mEngine->DrawString(x + TileSize * 8 + TileSize * 0.5 + BorderSize, y + forY * TileSize + TileSize * 0.5 + BorderSize, std::string(1, ('8'- (char)forY)));
    }
}

std::string ChessUi::tileColorAt(const std::string& pos) {
    ChessPosition p(pos);
    if (p.y() % 2 == 0)
        return (p.x() % 2 == 0 ? "White Tile" : "Black Tile");
    else
        return (p.x() % 2 == 0 ? "Black Tile" : "White Tile"); 
}