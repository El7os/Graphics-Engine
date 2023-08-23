#include <iostream>

#include <SDL.h>
#include "Screen.h"
#include "Input.h"
#include "Shader.h"

int main(int Argc, char* Argv[])
{
	Screen& ScreenRef = Screen::GetInstance();
	Input& InputRef = Input::GetInstance();
	Shader& ShaderRef = Shader::GetInstance();
	if (!ScreenRef.Initialize())
	{
		std::cout << "Something Went Wrong With Initializtion Of The Screen ! ";
		return -1;
	}

	if (!ShaderRef.CreateProgram()) return 0;

	if (!ShaderRef.CreateShaders()) return 0;
	if (!ShaderRef.CompileShaders("Shaders\\Main.vert", Shader::ShaderType::Vertex)) return 0;
	if (!ShaderRef.CompileShaders("Shaders\\Main.frag", Shader::ShaderType::Fragment)) return 0;
	ShaderRef.AttachShaders();
	if (ShaderRef.LinkProgram()) return 0;
	bool Running = true;

	GLint ID = glGetUniformLocation(ShaderProgramID, "Time");
	if (ID == -1)
	{
		std::cout << "Could Not Find The Uniform Variable ! ";
	}
	glUniform1f(ID, 2.4f);
	while (Running)
	{
		ScreenRef.ClearScreen();
		InputRef.Update();
		
		Running = !InputRef.IsXClicked();

		
		ScreenRef.Render();
	}

	ShaderRef.DetachShaders();
	ShaderRef.DestroyShaders();
	ShaderRef.DestroyProgram();

	ScreenRef.Shutdown();



	return 0;


}