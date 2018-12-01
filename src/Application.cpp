#include "Application.hpp"
#include "ChessUi.hpp"
#include "LoginUi.hpp"

Application::Application() {
    mState = State::Login;
	sAppName = "Console Chess";
}

bool Application::OnUserCreate() {
    mUi = std::make_unique<LoginUi>(this);
    return true;
}

bool Application::OnUserUpdate(float fElapsedTime)  {
    switch (mState) {
        case State::Login:
            login();
            break;
        case State::Browse:
            break;
        case State::Game:
            offlineGame();
            break;
        default:
            break;
    }
    return true;
}

void Application::getInput(std::string& target) {
    for (int i = 0; i <= olc::Key::Z; i++) {
        if (GetKey((olc::Key)i).bPressed)
            if (GetKey(olc::SHIFT).bHeld)
                target += (char)('A' + i);
            else
                target += (char)('a' + i);
    }
    for (int i = olc::Key::K0; i <= olc::Key::K9; i++) {
        if (GetKey((olc::Key)i).bPressed)
            target += (char)('0' + (i - olc::Key::K0));
    }
    if (GetKey(olc::SPACE).bPressed)
        target += " ";
    if (GetKey(olc::BACK).bPressed || GetKey(olc::DEL).bPressed)
        target.pop_back();
    
}

void Application::login() {
    mUi->draw();
    if (GetMouse(0).bPressed) {
        std::vector<Element> clicked = mUi->clickedElement();
        if (clicked.size() == 1) {
            if (clicked[0].name == "Play offline") {
                mUi->flush();
                mUi->showElement("Play online", false);
                mUi->showElement("Play offline", false);
                mUi->showElement("New Game");
                mUi->showElement("Load Game");
            }
            else if (clicked[0].name == "Play online") {
                mState = State::Browse;
            }
            else if (clicked[0].name == "New Game") {
                mState = State::Game;
                mGame = std::make_unique<ChessGame>(Player("Player", Piece::Side::White), Player("Opponent", Piece::Side::Black));
                mUi = std::make_unique<ChessUi>(this, *mGame);
            }
            else if (clicked[0].name == "Load Game") {
                mUi->flush();
                mUi->showElement("New Game", false);
                mUi->showElement("Load Game", false);
            }
        }
    }
}

void Application::offlineGame() {
    static std::string startPos, endPos;
    mUi->draw(50, 50);
    if (GetMouse(0).bPressed) {
        std::vector<Element> clicked = mUi->clickedElement();
        if (clicked.size() >= 1)
            startPos = clicked[0].name;
    }
    else if (GetMouse(0).bReleased) {
        std::vector<Element> clicked = mUi->clickedElement();
        if (clicked.size() >= 1) {
            endPos = clicked[0].name;
            if (startPos != endPos) {
                for (int y = 0; y < ScreenHeight(); y++)
                    for (int x = 0; x < ScreenWidth(); x++)
                        Draw(x, y, olc::BLACK);

                std::string move =  mGame->moveAction(startPos, endPos);
                DrawString(ScreenWidth() / 3, 5, move);
            }
        }
    }
}