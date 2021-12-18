#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

struct Texture2D
{
	unsigned int ID;
	Texture2D(const char* texturePath, int& width, int& height, int& nrChannels, GLenum format, GLint WRAP_S, GLint WRAP_T, GLint MIN_FILTER, GLint MAX_FILTER);
};

Texture2D::Texture2D(const char* texturePath, int& width, int& height, int& nrChannels, GLenum format = GL_RGB, GLint WRAP_S = GL_REPEAT, GLint WRAP_T = GL_REPEAT, GLint MIN_FILTER = GL_LINEAR_MIPMAP_LINEAR, GLint MAX_FILTER = GL_LINEAR)
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, WRAP_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, WRAP_T);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, MIN_FILTER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, MAX_FILTER);

	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture\n";
	}
	stbi_image_free(data);
}

#endif // !TEXTURE_H

