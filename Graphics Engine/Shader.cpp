#include "Shader.h"
#include <iostream>
#include <fstream>

Shader::Shader()
	: ShaderProgramID(0)
	, VertexShaderID(0)
	, FragmentShaderID(0)
{

}

bool Shader::CreateProgram()
{
	ShaderProgramID = glCreateProgram();
	if (!ShaderProgramID)
	{
		std::cout << "Error creating shader program" << std::endl;
		return false;
	}

	return true;
}

bool Shader::CreateShaders()
{
	VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if (!VertexShaderID || !FragmentShaderID)
	{
		std::cout << "Error creating shaders" << std::endl;
		return false;
	}

	return true;
}

bool Shader::CompileShaders(const std::string& FileName, ShaderType Type)
{
	std::fstream File;
	std::string Line;
	std::string SourceCode;
	GLuint ShaderID = Type == ShaderType::Vertex ? VertexShaderID : FragmentShaderID;

	File.open(FileName);

	if (!File)
	{
		std::cout << "Error Opening File" << std::endl;
		return false;
	}

	while(!File.eof())
	{
		std::getline(File, Line);
		SourceCode += Line + "\n";
	}
	File.close();

	const GLchar* SourceCodePtr = SourceCode.c_str();
	glShaderSource(ShaderID, 1, &SourceCodePtr, NULL);

	glCompileShader(ShaderID);
	
	GLint ErrorCode;
	glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &ErrorCode);
	if (ErrorCode != GL_TRUE)
	{
		GLchar ErrorBuffer[1000];
		GLsizei BufferSize = 1000;


		glGetShaderInfoLog(ShaderID, BufferSize, &BufferSize, ErrorBuffer);
		std::cout << "An error occured while compiling shader" << std::endl;
		std::cout << "\t" << ErrorBuffer << std::endl;

		return false;
	}
	std::cout << "Shader Compiled Successfully" << std::endl;

	return true;
}

void Shader::AttachShaders()
{
	glAttachShader(ShaderProgramID, VertexShaderID);
	glAttachShader(ShaderProgramID, FragmentShaderID);
}

bool Shader::LinkProgram()
{
	glLinkProgram(ShaderProgramID);
	glUseProgram(ShaderProgramID);

	GLint ErrorCode;
	glGetProgramiv(ShaderProgramID, GL_LINK_STATUS, &ErrorCode);
	if (ErrorCode != GL_TRUE)
	{
		GLchar ErrorBuffer[1000];
		GLsizei BufferSize = 1000;


		glGetProgramInfoLog(ShaderProgramID, BufferSize, &BufferSize, ErrorBuffer);
		std::cout << "An error occured while linking the program" << std::endl;
		std::cout << "\t" << ErrorBuffer << std::endl;

		return false;
	}
	std::cout << "Program Linked Successfully" << std::endl;

	return true;
}

void Shader::DetachShaders()
{
	glDetachShader(ShaderProgramID, VertexShaderID);
	glDetachShader(ShaderProgramID, FragmentShaderID);
}

void Shader::DestroyShaders()
{
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);
}

void Shader::DestroyProgram()
{
	glDeleteProgram(ShaderProgramID);
}
