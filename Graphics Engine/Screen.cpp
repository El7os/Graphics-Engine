#include "Screen.h"

#include <Windows.h>
#include <gl/GL.h>

bool Screen::Initialize(std::string Title
	, ColorDepth Depth
	, int XLocation
	, int YLocation
	, int Width
	, int Height
	, Uint32 Flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) return false;

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, Depth.Red); // 8 bits for red
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, Depth.Blue); // 8 bits for blue
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, Depth.Green); // 8 bits for green
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, Depth.Alpha); // 8 bits for alpha
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, Depth.Buffer); // 32 bits for buffer

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Double Buffer
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY); // Compatibility Profile
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4); // Major Version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6); // Minor Version

	Window = SDL_CreateWindow(Title.c_str(), XLocation, YLocation, Width, Height, Flags); // Create Window
	
	if (!Window) { SDL_Quit(); return false;}

	Context = SDL_GL_CreateContext(Window); //Create Canvas
	if (!Context)
	{
		SDL_DestroyWindow(Window);
		SDL_Quit();
		return false;
	}
	
	return true;
}

void Screen::Shutdown()
{
	if (Context) SDL_GL_DeleteContext(Context); // Delete Canvas
	if (Window) SDL_DestroyWindow(Window); // Delete Window
	SDL_Quit(); // Quit SDL
}

void Screen::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear Screen
}

void Screen::Render()
{
	SDL_GL_SwapWindow(Window); // Swap Buffers
}