#pragma once

#include <string>
#include "glad.h"

class Shader
{

public : 

	enum class ShaderType : char
	{
		Vertex,
		Fragment
	};

	inline static Shader& GetInstance()
	{
		static Shader instance;
		return instance;
	}

	bool CreateProgram();
	bool CreateShaders();

	bool CompileShaders(const std::string& FileName, ShaderType Type);
	void AttachShaders();
	bool LinkProgram();

	void DetachShaders();
	void DestroyShaders();
	void DestroyProgram();

private :

	Shader();
	Shader(Shader&&) = default;
	Shader& operator=(Shader&&) = default;

	Shader(const Shader&) = delete;
	Shader& operator=(const Shader&) = delete;

	GLuint ShaderProgramID;
	GLuint VertexShaderID;
	GLuint FragmentShaderID;
};