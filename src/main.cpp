#define OLC_PGE_APPLICATION
#include <ChessGame.hpp>
#include <Ui.hpp>

/*
Olc Pixel Game Engine used in this project.
Created by OneLoneCoder
*/

int main() {
    Ui ui;
    if (ui.Construct(256, 240, 4, 4))
        ui.Start();
    return 0;
}