#define OLC_PGE_APPLICATION
#include <Ui.hpp>

/*
Olc Pixel Game Engine used in this project.
Created by OneLoneCoder
*/

int main() {
    Ui ui;
    if (ui.Construct(512, 512, 1, 1))
        ui.Start();
    return 0;
}