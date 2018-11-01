#pragma once
#include <Ui.hpp>

class ChessUi : public Ui {
public:
    ChessUi(olc::PixelGameEngine* pge, ChessGame& game);

    void draw(int x = 0, int y = 0) override;

    std::string clickedElement() override {
        int mouseX = mEngine->GetMouseX();
        int mouseY = mEngine->GetMouseY();

        for (const auto& elem : mElements) {
            if (mouseX >= elem.second.x + mOffsetX && mouseX < elem.second.x + mOffsetX + TileSize) {
                if (mouseY >= elem.second.y + mOffsetY && mouseY < elem.second.y + mOffsetY + TileSize)
                    return elem.second.name;
            }
        }
    }

    static constexpr int TileSize = 48;
    static constexpr int BorderSize = 8;


private:
    ChessGame& mGame;
    
    void drawChessBoard(int x, int y);

    void updateElementPositions();

    std::string tileColorAt(const std::string& pos);

    std::string getChessPositionAtMouse();
};