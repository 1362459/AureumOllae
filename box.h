#ifndef BOX_H

#define BOX_H
#include "shader.h"
#include <GL/glm/glm.hpp>
#include <GL/glm/gtc/matrix_transform.hpp>
#include <GL/glm/gtc/type_ptr.hpp>

class Box
{
public:
	Box();
	Box(glm::vec3 position, glm::vec3 size);
	~Box();
	void setXPos(const float& x);
	void setYPos(const float& y);
	void setZPos(const float& z);
	void setPos(glm::vec3 position);
	float getXPos();
	float getYPos();
	float getZPos();
	float getXEndPos();
	float getYEndPos();
	float getZEndPos();
	void Draw(Shader * shad, unsigned int* VBO, unsigned int* VAO);
	float vertices[288];
	float itemVertices[288];

	float mapVertices[180];

private:
	glm::vec3 Position;
	glm::vec3 EndPosition;
	glm::vec3 Size;
	void setVertices();
};


#endif