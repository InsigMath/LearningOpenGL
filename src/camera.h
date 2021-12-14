#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#define YAW			-90.0f
#define PITCH		0.0f
#define SPEED		2.5f
#define SENSITIVITY 0.1f
#define ZOOM		45.0f

enum Camera_Movement
{
	BACKWARD,
	FORWARD,
	LEFT,
	RIGHT
};

struct Camera
{
	//Camera attrivurt
};



#endif // !CAMERA_H

