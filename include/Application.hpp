#pragma once
#include <olcPixelGameEngine.h>
#include <ChessGame.hpp>

class Ui;

class Application : public olc::PixelGameEngine {
public:
	Application();

	enum State { Login, Browse, Game };

public:
	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

	void getInput(std::string& target);

	void login();

	void offlineGame();

	

private:
	std::unique_ptr<ChessGame> mGame;
	std::unique_ptr<Ui> mUi;
	State mState;
};
