#include "Input.h"
#include <SDL.h>
#include <iostream>
Input::Input() : KeyUp(0)
			   , KeyDown(0)
			   , bXClicked(false)
			   , bKeyPressed(false)
			   , bLeftMouseButtonClicked(false)
			   , bRightMouseButtonClicked(false)
			   , bMiddleMouseButtonClicked(false)
			   , MousePositionX(0)
			   , MousePositionY(0)
			   , MouseMotionX(0)
			   , MouseMotionY(0)
{
}

void Input::Update()
{
	SDL_Event Event;
	
	MouseMotionX = 0;
	MouseMotionY = 0;

	MousePositionX = 0;
	MousePositionY = 0;

	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
			case SDL_KEYDOWN:
				KeyDown = Event.key.keysym.sym;
				std::cout << KeyDown << " key pressed" << std::endl;
				bKeyPressed = true;
				break;
			case SDL_KEYUP:
				if (bKeyPressed) bKeyPressed = false;
				std::cout << KeyUp << " key released" << std::endl;
				KeyUp = Event.key.keysym.sym;
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (Event.button.button)
				{
					case SDL_BUTTON_LEFT:
						bLeftMouseButtonClicked = true;
						break;
					case SDL_BUTTON_RIGHT:
						bRightMouseButtonClicked = true;
						break;
					case SDL_BUTTON_MIDDLE:
						bMiddleMouseButtonClicked = true;
						break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch (Event.button.button)
				{
					case SDL_BUTTON_LEFT:
						bLeftMouseButtonClicked = false;
						break;
					case SDL_BUTTON_RIGHT:
						bRightMouseButtonClicked = false;
						break;
					case SDL_BUTTON_MIDDLE:
						bMiddleMouseButtonClicked = false;
						break;
				}
				break;
			case SDL_MOUSEMOTION:
				MousePositionX = Event.motion.x;
				MousePositionY = Event.motion.y;
				MouseMotionX = Event.motion.xrel;
				MouseMotionY = Event.motion.yrel;
				break;
			case SDL_QUIT:
				bXClicked = true;
				break;
			default:
				break;
		}
	}
}
