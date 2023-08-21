#pragma once
#include <SDL.h>
#include <string>
struct ColorDepth
{
	ColorDepth(int RedDepth, int BlueDept, int GreenDepth, int AlphaDepth, int BufferDepth)
		: Red(RedDepth)
		, Blue(BlueDept)
		, Green(GreenDepth)
		, Alpha(AlphaDepth)
		, Buffer(BufferDepth)
	{
	}

	int Red;
	int Green;
	int Blue;
	int Alpha;
	int Buffer;
};

class Screen
{
public:

	static inline Screen& GetInstance()
	{
		static Screen Instance;
		return Instance;
	}

	bool Initialize(std::string Title = "No Title"
		, ColorDepth Depth = ColorDepth(8, 8, 8, 8, 32)
		, int XLocation = SDL_WINDOWPOS_CENTERED
		, int YLocation = SDL_WINDOWPOS_CENTERED
		, int Width = 1280
		, int Height = 720
		, Uint32 Flags = SDL_WINDOW_OPENGL);

	void Shutdown();
	void ClearScreen();
	void Render();

private: 

	Screen() = default;
	Screen(Screen&&) = default; // Move Constructor
	Screen& operator=(Screen&&) = default; // Move Assignment Operator

	Screen(Screen const&) = delete; // Copy Constructor
	Screen& operator=(Screen const&) = delete; // Copy Assignment Operator


	SDL_Window* Window = nullptr; // Actual Window
	SDL_GLContext Context = nullptr; // Canvas
};