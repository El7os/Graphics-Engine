#include <iostream>

#include <SDL.h>
#include "Screen.h"
#include "Input.h"

int main(int Argc, char* Argv[])
{
	Screen& ScreenRef = Screen::GetInstance();
	Input& InputRef = Input::GetInstance();

	if (!ScreenRef.Initialize())
	{
		std::cout << "Something Went Wrong With Initializtion Of The Screen ! ";
		return -1;
	}
	bool Running = true;

	while (Running)
	{
		ScreenRef.ClearScreen();
		InputRef.Update();
		
		Running = !InputRef.IsXClicked();

		
		ScreenRef.Render();
	}

	ScreenRef.Shutdown();



	return 0;


}