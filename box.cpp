#include "box.h"
#include <GL/glad/glad.h>
#include <GL/GLFW/glfw3.h>

Box::Box():
Position(glm::vec3(0.0, 0.0, 0.0)),
Size(glm::vec3(1.0, 1.0, 1.0))
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

Box::Box(glm::vec3 position, glm::vec3 size):
	Position(position),
	Size(size)
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

Box::~Box()
{
}

void Box::setXPos(const float & x)
{
	Position.x = x;
	EndPosition.x = Position.x + Size.x;
	setVertices();
}

void Box::setYPos(const float & y)
{
	Position.y = y;
	EndPosition.y = Position.y + Size.y;
	setVertices();
}

void Box::setZPos(const float & z)
{
	Position.z = z;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

void Box::setPos(glm::vec3 position)
{
	Position = position;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

float Box::getXPos()
{
	return Position.x;
	setVertices();
}

float Box::getYPos()
{
	return Position.y;
	setVertices();
}

float Box::getZPos()
{
	return Position.z;
	setVertices();
}

float Box::getXEndPos()
{
	return EndPosition.x;
}

float Box::getYEndPos()
{
	return EndPosition.y;
}

float Box::getZEndPos()
{
	return EndPosition.z;
}

void Box::setVertices()
{
	float vertices1[]=
	{
	Position.x, Position.y, Position.z, 0.0f,  0.0f,  -1.0f,  0.0f, 0.0f,
	EndPosition.x, Position.y, Position.z, 0.0f,  0.0f, -1.0f,  0.2f * (EndPosition.x - Position.x), 0.0f,
	EndPosition.x, EndPosition.y, Position.z, 0.0f,  0.0f, -1.0f,  0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	EndPosition.x,  EndPosition.y, Position.z, 0.0f,  0.0f, -1.0f,  0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	Position.x,  EndPosition.y, Position.z, 0.0f,  0.0f, -1.0f,  0.0f, 0.2f * (EndPosition.y - Position.y),
	Position.x, Position.y, Position.z, 0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

	Position.x, Position.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  0.0f, 0.0f,
	EndPosition.x, Position.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  0.2f * (EndPosition.x - Position.x), 0.0f,
	EndPosition.x, EndPosition.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	EndPosition.x,  EndPosition.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	Position.x,  EndPosition.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  0.0f, 0.2f * (EndPosition.y - Position.y),
	Position.x, Position.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  0.0f, 0.0f,

	Position.x,  EndPosition.y,  EndPosition.z, -1.0f,  0.0f,  0.0f,   0.0f, 0.2f*(EndPosition.y - Position.y),
	Position.x,  EndPosition.y, Position.z, -1.0f,  0.0f,  0.0f, 0.2f * (EndPosition.z - Position.z),  0.2f * (EndPosition.y - Position.y),
	Position.x, Position.y, Position.z, -1.0f,  0.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x, Position.y, Position.z, -1.0f,  0.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x, Position.y,  EndPosition.z, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	Position.x,  EndPosition.y,  EndPosition.z, -1.0f,  0.0f,  0.0f, 0.0f, 0.2f * (EndPosition.y - Position.y),

	EndPosition.x,  EndPosition.y,  EndPosition.z, 1.0f,  0.0f,  0.0f,   0.0f, 0.2f*(EndPosition.y - Position.y),
	EndPosition.x,  EndPosition.y, Position.z, 1.0f,  0.0f,  0.0f, 0.2f * (EndPosition.z - Position.z),  0.2f * (EndPosition.y - Position.y),
	EndPosition.x, Position.y, Position.z, 1.0f,  0.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.0f,
	EndPosition.x, Position.y, Position.z, 1.0f,  0.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.0f,
	EndPosition.x, Position.y,  EndPosition.z, 1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	EndPosition.x,  EndPosition.y,  EndPosition.z, 1.0f,  0.0f,  0.0f, 0.0f, 0.2f * (EndPosition.y - Position.y),

	Position.x, Position.y, Position.z, 0.0f, -1.0f,  0.0f, 0.0f,  0.2f * (EndPosition.x - Position.x),
	EndPosition.x, Position.y, Position.z, 0.0f, -1.0f,  0.0f, 0.2f * (EndPosition.z - Position.z),  0.2f * (EndPosition.x - Position.x),
	EndPosition.x, Position.y,  EndPosition.z, 0.0f, -1.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.0f,
	EndPosition.x, Position.y,  EndPosition.z, 0.0f, -1.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x, Position.y,  EndPosition.z, 0.0f, -1.0f,  0.0f, 0.0f, 0.0f,
	Position.x, Position.y, Position.z, 0.0f, -1.0f,  0.0f, 0.0f,  0.2f * (EndPosition.x - Position.x),

	Position.x,  EndPosition.y, Position.z, 0.0f,  1.0f,  0.0f, 0.0f, 0.2f * (EndPosition.x - Position.x),
	EndPosition.x,  EndPosition.y, Position.z, 0.0f,  1.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.2f * (EndPosition.x - Position.x),
	EndPosition.x,  EndPosition.y,  EndPosition.z, 0.0f, 1.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.0f,
	EndPosition.x,  EndPosition.y,  EndPosition.z, 0.0f, 1.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x,  EndPosition.y,  EndPosition.z, 0.0f, 1.0f,  0.0f,  0.0f, 0.0f,
	Position.x,  EndPosition.y, Position.z, 0.0f, 1.0f,  0.0f, 0.0f, 0.2f * (EndPosition.x - Position.x)

	};
	for(int i = 0; i<288; i++)
	vertices[i] = vertices1[i];



	float vertices2[] =
	{
	Position.x, Position.y, Position.z,    0.0f, 0.0f,
	EndPosition.x, Position.y, Position.z,   0.2f * (EndPosition.x - Position.x), 0.0f,
	EndPosition.x, EndPosition.y, Position.z,     0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	EndPosition.x,  EndPosition.y, Position.z,    0.2f * (EndPosition.x - Position.x),0.2f * (EndPosition.y - Position.y),
	Position.x,  EndPosition.y, Position.z,  0.0f, 0.2f * (EndPosition.y - Position.y),
	Position.x, Position.y, Position.z,   0.0f, 0.0f,

	Position.x, Position.y,  EndPosition.z,  0.0f, 0.0f,
	EndPosition.x, Position.y,  EndPosition.z,  0.2f * (EndPosition.x - Position.x), 0.0f,
	EndPosition.x,  EndPosition.y,  EndPosition.z, 0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	EndPosition.x,  EndPosition.y,  EndPosition.z,  0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	Position.x,  EndPosition.y,  EndPosition.z, 0.0f, 0.2f * (EndPosition.y - Position.y),
	Position.x,  Position.y,  EndPosition.z,  0.0f, 0.0f,

	Position.x,  EndPosition.y,  EndPosition.z,    0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x,  EndPosition.y, Position.z,  0.2f * (EndPosition.z - Position.z), 0.2f*(EndPosition.y - Position.y),
	Position.x, Position.y, Position.z, 0.0f,0.2f*(EndPosition.y - Position.y),
	Position.x, Position.y, Position.z,  0.0f, 0.2f*(EndPosition.y - Position.y),
	Position.x, Position.y,  EndPosition.z,  0.0f, 0.0f,
	Position.x,  EndPosition.y,  EndPosition.z,  0.2f * (EndPosition.z - Position.z), 0.0f,

	EndPosition.x,  EndPosition.y,  EndPosition.z,  0.2f * (EndPosition.z - Position.z), 0.0f,
	EndPosition.x,  EndPosition.y, Position.z,  0.2f * (EndPosition.z - Position.z),0.2f*(EndPosition.y - Position.y),
	EndPosition.x, Position.y, Position.z,  0.0f, 0.2f*(EndPosition.y - Position.y),
	EndPosition.x, Position.y, Position.z,  0.0f, 0.2f*(EndPosition.y - Position.y),
	EndPosition.x, Position.y,  EndPosition.z,  0.0f, 0.0f,
	EndPosition.x,  EndPosition.y,  EndPosition.z,  0.2f * (EndPosition.z - Position.z), 0.0f,

	Position.x, Position.y, Position.z,  0.0f,  0.2f * (EndPosition.x - Position.x),
	EndPosition.x, Position.y, Position.z,  0.2f * (EndPosition.z - Position.z),  0.2f * (EndPosition.x - Position.x),
	EndPosition.x, Position.y,  EndPosition.z,  0.2f * (EndPosition.z - Position.z), 0.0f,
	EndPosition.x, Position.y,  EndPosition.z,  0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x, Position.y,  EndPosition.z, 0.0f, 0.0f,
	Position.x, Position.y, Position.z,  0.0f,  0.2f * (EndPosition.x - Position.x),

	Position.x,  EndPosition.y, Position.z, 0.0f, 0.2f * (EndPosition.x - Position.x),
	EndPosition.x,  EndPosition.y, Position.z, 0.2f * (EndPosition.z - Position.z), 0.2f * (EndPosition.x - Position.x),
	EndPosition.x,  EndPosition.y,  EndPosition.z,  0.2f * (EndPosition.z - Position.z), 0.0f,
	EndPosition.x,  EndPosition.y,  EndPosition.z,  0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x,  EndPosition.y,  EndPosition.z,  0.0f, 0.0f,
	Position.x,  EndPosition.y, Position.z, 0.0f, 0.2f * (EndPosition.x - Position.x)

	};
	for (int i = 0; i < 180; i++)
		mapVertices[i] = vertices2[i];

	float vertices3[] =
	{
	Position.x, Position.y, Position.z, 0.0f,  0.0f,  -1.0f,  0.0f, 0.0f,
	EndPosition.x, Position.y, Position.z, 0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
	EndPosition.x, EndPosition.y, Position.z, 0.0f,  0.0f, -1.0f, 1.0f, 1.0f,
	EndPosition.x,  EndPosition.y, Position.z, 0.0f,  0.0f, -1.0f, 1.0f, 1.0f,
	Position.x,  EndPosition.y, Position.z, 0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
	Position.x, Position.y, Position.z, 0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

	Position.x, Position.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  0.0f, 0.0f,
	EndPosition.x, Position.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  1.0f, 0.0f,
	EndPosition.x, EndPosition.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  1.0f, 1.0f,
	EndPosition.x,  EndPosition.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  1.0f, 1.0f,
	Position.x,  EndPosition.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  0.0f, 1.0f,
	Position.x, Position.y, EndPosition.z, 0.0f,  0.0f, 1.0f,  0.0f, 0.0f,

	Position.x,  EndPosition.y,  EndPosition.z, -1.0f,  0.0f,  0.0f,   0.0f, 1.0f,
	Position.x,  EndPosition.y, Position.z, -1.0f,  0.0f,  0.0f, 1.0f,  1.0f,
	Position.x, Position.y, Position.z, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
	Position.x, Position.y, Position.z, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
	Position.x, Position.y,  EndPosition.z, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	Position.x,  EndPosition.y,  EndPosition.z, -1.0f,  0.0f,  0.0f, 0.0f,1.0f,

	EndPosition.x,  EndPosition.y,  EndPosition.z, 1.0f,  0.0f,  0.0f,   0.0f, 1.0f,
	EndPosition.x,  EndPosition.y, Position.z, 1.0f,  0.0f,  0.0f, 1.0f,  1.0f,
	EndPosition.x, Position.y, Position.z, 1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
	EndPosition.x, Position.y, Position.z, 1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
	EndPosition.x, Position.y,  EndPosition.z, 1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	EndPosition.x,  EndPosition.y,  EndPosition.z, 1.0f,  0.0f,  0.0f, 0.0f, 1.0f,

	Position.x, Position.y, Position.z, 0.0f, -1.0f,  0.0f, 0.0f,  1.0f,
	EndPosition.x, Position.y, Position.z, 0.0f, -1.0f,  0.0f, 1.0f,  1.0f,
	EndPosition.x, Position.y,  EndPosition.z, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
	EndPosition.x, Position.y,  EndPosition.z, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
	Position.x, Position.y,  EndPosition.z, 0.0f, -1.0f,  0.0f, 0.0f, 0.0f,
	Position.x, Position.y, Position.z, 0.0f, -1.0f,  0.0f, 0.0f,  1.0f,

	Position.x,  EndPosition.y, Position.z, 0.0f,  1.0f,  0.0f, 0.0f , 1.0f,
	EndPosition.x,  EndPosition.y, Position.z, 0.0f,  1.0f,  0.0f, 1.0f, 1.0f,
	EndPosition.x,  EndPosition.y,  EndPosition.z, 0.0f, 1.0f,  0.0f, 1.0f, 0.0f,
	EndPosition.x,  EndPosition.y,  EndPosition.z, 0.0f, 1.0f,  0.0f, 1.0f, 0.0f,
	Position.x,  EndPosition.y,  EndPosition.z, 0.0f, 1.0f,  0.0f,  0.0f, 0.0f,
	Position.x,  EndPosition.y, Position.z, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f

	};
	for (int i = 0; i < 288; i++)
		itemVertices[i] = vertices3[i];

}

void Box::Draw(Shader* shad, unsigned int * VBO, unsigned int * VAO)
{




		glBindVertexArray(*VAO);

		// calculate the model matrix for each object and pass it to shader before drawing
		glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		float angle = 20.0f * 0;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		shad->setMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);



}



