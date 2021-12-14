#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

struct Shader
{
	//Program ID
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);

	void use() { glUseProgram(ID); }
	
	void setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}
	void setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}
	void setVec2Int(const std::string& name, int v0, int v1) const
	{
		glUniform2i(glGetUniformLocation(ID, name.c_str()), v0, v1);
	}
	void setVec3Int(const std::string& name, int v0, int v1, int v2) const
	{
		glUniform3i(glGetUniformLocation(ID, name.c_str()), v0, v1, v2);
	}
	void setVec4Int(const std::string& name, int v0, int v1, int v2, int v3) const
	{
		glUniform4i(glGetUniformLocation(ID, name.c_str()), v0, v1, v2, v3);
	}
	void setIntPtr(const std::string& name, int count, int* value)
	{
		glUniform1iv(glGetUniformLocation(ID, name.c_str()), count, value);
	}
	void setIntVec2Ptr(const std::string& name, int count, int* value)
	{
		glUniform2iv(glGetUniformLocation(ID, name.c_str()), count, value);
	}
	void setIntVec3Ptr(const std::string& name, int count, int* value)
	{
		glUniform3iv(glGetUniformLocation(ID, name.c_str()), count, value);
	}
	void setIntVec4Ptr(const std::string& name, int count, int* value)
	{
		glUniform4iv(glGetUniformLocation(ID, name.c_str()), count, value);
	}
	void setUInt(const std::string& name, unsigned int value) const
	{
		glUniform1ui(glGetUniformLocation(ID, name.c_str()), value);
	}
	void setVec2UInt(const std::string& name, unsigned int v0, unsigned int v1) const
	{
		glUniform2ui(glGetUniformLocation(ID, name.c_str()), v0, v1);
	}
	void setVec3UInt(const std::string& name, unsigned int v0, unsigned int v1, unsigned int v2) const
	{
		glUniform3ui(glGetUniformLocation(ID, name.c_str()), v0, v1, v2);
	}
	void setVec4UInt(const std::string& name, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3) const
	{
		glUniform4ui(glGetUniformLocation(ID, name.c_str()), v0, v1, v2, v3);
	}
	void setUIntPtr(const std::string& name, int count, unsigned int* value)
	{
		glUniform1uiv(glGetUniformLocation(ID, name.c_str()), count, value);
	}
	void setUIntVec2Ptr(const std::string& name, int count, unsigned int* value)
	{
		glUniform2uiv(glGetUniformLocation(ID, name.c_str()), count, value);
	}
	void setUIntVec3Ptr(const std::string& name, int count, unsigned int* value)
	{
		glUniform3uiv(glGetUniformLocation(ID, name.c_str()), count, value);
	}
	void setUIntVec4Ptr(const std::string& name, int count, unsigned int* value)
	{
		glUniform4uiv(glGetUniformLocation(ID, name.c_str()), count, value);
	}
	void setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}
	void setVec2Float(const std::string& name, float v0, float v1) const
	{
		glUniform2f(glGetUniformLocation(ID, name.c_str()), v0, v1);
	}
	void setVec3Float(const std::string& name, float v0, float v1, float v2) const
	{
		glUniform3f(glGetUniformLocation(ID, name.c_str()), v0, v1, v2);
	}
	void setVec4Float(const std::string& name, float v0, float v1, float v2, float v3) const
	{
		glUniform4f(glGetUniformLocation(ID, name.c_str()), v0, v1, v2, v3);
	}
	void setFloatPtr(const std::string& name, float* value)
	{
		glUniform1fv(glGetUniformLocation(ID, name.c_str()), 1, value);
	}
	void setFloatVec2Ptr(const std::string& name, float* value)
	{
		glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, value);
	}
	void setFloatVec3Ptr(const std::string& name, float* value)
	{
		glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, value);
	}
	void setFloatVec4Ptr(const std::string& name, float* value)
	{
		glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, value);
	}
	void setFloatMatrix2fv(const std::string& name, const glm::mat2 &m)
	{
		glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &m[0][0]);
	}
	void setFloatMatrix3fv(const std::string& name, const glm::mat3 &m)
	{
		glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &m[0][0]);
	}
	void setFloatMatrix4fv(const std::string& name, const glm::mat4 &m)
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &m[0][0]);
	}
	void setFloatMatrix2x3fv(const std::string& name, const glm::mat2x3 &m)
	{
		glUniformMatrix2x3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &m[0][0]);
	}
	void setFloatMatrix3x2fv(const std::string& name, const glm::mat3x2 &m)
	{
		glUniformMatrix3x2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &m[0][0]);
	}
	void setFloatMatrix2x4fv(const std::string& name, const glm::mat2x4 &m)
	{
		glUniformMatrix2x4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &m[0][0]);
	}
	void setFloatMatrix4x2fv(const std::string& name, const glm::mat4x2 &m)
	{
		glUniformMatrix4x2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &m[0][0]);
	}
	void setFloatMatrix3x4fv(const std::string& name, const glm::mat3x4 &m)
	{
		glUniformMatrix3x4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &m[0][0]);
	}
	void setFloatMatrix4x3fv(const std::string& name, const glm::mat4x3 &m)
	{
		glUniformMatrix4x3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &m[0][0]);
	}
};

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	//Ensure ifstream objects can throw exceptions
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		//Open file
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		//read file's buffer contents into stream
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		//close file handlers
		vShaderFile.close();
		fShaderFile.close();
		//convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ\n";
	}
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	//compile shaders
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	//vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << '\n';
	}

	//fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << '\n';
	}

	//shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << '\n';
	}

	//delete shaders
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

#endif // !SHADER_H

