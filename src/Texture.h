#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "stb_image.h"

struct Texture2D
{
	unsigned int ID;
	Texture2D(const char* texturePath, GLint WRAP_S, GLint WRAP_T, GLint MIN_FILTER, GLint MAG_FILTER, bool flip);
};

Texture2D::Texture2D(const char *texturePath, GLint WRAP_S = GL_REPEAT, GLint WRAP_T = GL_REPEAT, GLint MIN_FILTER = GL_LINEAR_MIPMAP_LINEAR, GLint MAG_FILTER = GL_LINEAR, bool flip = false)
{
	int width, height, nrChannels;
	glGenTextures(1, &ID);

	stbi_set_flip_vertically_on_load(flip);
	unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
	if (data)
	{
		GLenum format;
		if (nrChannels == 1) format = GL_RED;
		else if (nrChannels == 3) format = GL_RGB;
		else if (nrChannels == 4) format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, ID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : WRAP_S);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : WRAP_T);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, MIN_FILTER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, MAG_FILTER);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Failed to load texture from path: " << texturePath << std::endl;
		stbi_image_free(data);
	}
}

#endif // !TEXTURE_H

