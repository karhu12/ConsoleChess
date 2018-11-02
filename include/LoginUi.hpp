#pragma once
#include <Ui.hpp>

class LoginUi : public Ui {
public:
    LoginUi(olc::PixelGameEngine* pge);

    void draw(int x, int y) override {
        drawElements();
        mEngine->DrawString(mEngine->ScreenWidth() * 0.26f, mEngine->ScreenHeight() * 0.95f, "< Created by Riku Kaipainen >");
    }

private:

};