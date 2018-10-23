#pragma once
#include <olcPixelGameEngine.h>

class Ui : public olc::PixelGameEngine
	{
	public:
		Ui()
		{
			sAppName = "Example";
		}

	public:
		bool OnUserCreate() override
		{
			// Called once at the start, so create things here
			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			// called once per frame, draws random coloured pixels
			for (int x = 0; x < ScreenWidth(); x++)
				for (int y = 0; y < ScreenHeight(); y++)
					Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand()% 255));
			return true;
		}
	};