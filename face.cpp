#include "face.h"

FaceXY::FaceXY() : 
	Position(glm::vec3(0.0f, 0.0f, 0.0f)),
	Size(glm::vec3(0.0f, 0.0f, 0.0f))
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

FaceXY::~FaceXY()
{

}

FaceXY::FaceXY(const FaceXY &_cop)
{
	this->Position.x = _cop.Position.x;
	this->Position.y = _cop.Position.y;
	this->Position.z = _cop.Position.z;

	this->Size.x = _cop.Size.x;
	this->Size.y = _cop.Size.y;
	this->Size.z = _cop.Size.z;

	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
}

FaceXY::FaceXY(glm::vec3 position, glm::vec3 size) : 
	Position(position),
	Size(size)
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

void FaceXY::setXPos(const float & x)
{
	Position.x = x;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

void FaceXY::setYPos(const float & y)
{
	Position.y = y;	
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

void FaceXY::setZPos(const float & z)
{
	Position.z = z;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();

}

void FaceXY::setPos(glm::vec3 position)
{
	Position = position;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

float FaceXY::getXPos()
{
	return Position.x;
}

float FaceXY::getYPos()
{
	return Position.y;
}

float FaceXY::getZPos()
{
	return Position.z;
}

float FaceXY::getXEndPos()
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	return EndPosition.x;
}

float FaceXY::getYEndPos()
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	return EndPosition.y;
}

float FaceXY::getZEndPos()
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	return EndPosition.z;
}

void FaceXY::Draw(Shader * shad, unsigned int * VBO, unsigned int * VAO)
{
	glBindVertexArray(*VAO);
	// calculate the model matrix for each object and pass it to shader before drawing
	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	float angle = 20.0f * 0;
	model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
	shad->setMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}


void FaceXY::setVertices()
{
	float vertices1[] =
	{
	Position.x, Position.y, Position.z, 0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
	EndPosition.x, Position.y, Position.z, 0.0f,  0.0f, -1.0f,  0.2f * (EndPosition.x - Position.x), 0.0f,
	EndPosition.x, EndPosition.y, Position.z, 0.0f,  0.0f, -1.0f,  0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	EndPosition.x,  EndPosition.y, Position.z, 0.0f,  0.0f, -1.0f,  0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	Position.x,  EndPosition.y, Position.z, 0.0f,  0.0f, -1.0f,  0.0f, 0.2f * (EndPosition.y - Position.y),
	Position.x, Position.y, Position.z, 0.0f,  0.0f, -1.0f,  0.0f, 0.0f
	};
	float vertices2[] =
	{
	Position.x, Position.y, Position.z, 0.0f, 0.0f,
	EndPosition.x, Position.y, Position.z, 0.2f * (EndPosition.x - Position.x), 0.0f,
	EndPosition.x, EndPosition.y, Position.z, 0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	EndPosition.x,  EndPosition.y, Position.z,  0.2f * (EndPosition.x - Position.x), 0.2f * (EndPosition.y - Position.y),
	Position.x,  EndPosition.y, Position.z, 0.0f, 0.2f * (EndPosition.y - Position.y),
	Position.x, Position.y, Position.z, 0.0f, 0.0f
	};
	for (int i = 0; i < 48; i++)
		vertices[i] = vertices1[i];
	for (int i = 0; i < 30; i++)
		mapVertices[i] = vertices2[i];
}

FaceXZ::FaceXZ() :
	Position(glm::vec3(0.0f, 0.0f, 0.0f)),
	Size(glm::vec3(0.0f, 0.0f, 0.0f))
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

FaceXZ::~FaceXZ()
{

}

FaceXZ::FaceXZ(const FaceXZ &_cop)
{
	this->Position = _cop.Position;

	this->Size = _cop.Size;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
}

FaceXZ::FaceXZ(glm::vec3 position, glm::vec3 size) :
	Position(position),
	Size(size)
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

void FaceXZ::setXPos(const float & x)
{
	Position.x = x;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

void FaceXZ::setYPos(const float & y)
{
	Position.y = y;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

void FaceXZ::setZPos(const float & z)
{
	Position.z = z;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();

}

void FaceXZ::setPos(glm::vec3 position)
{
	Position = position;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

float FaceXZ::getXPos()
{
	return Position.x;
}

float FaceXZ::getYPos()
{
	return Position.y;
}

float FaceXZ::getZPos()
{
	return Position.z;
}

float FaceXZ::getXEndPos()
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	return EndPosition.x;
}

float FaceXZ::getYEndPos()
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	return EndPosition.y;
}

float FaceXZ::getZEndPos()
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	return EndPosition.z;
}

void FaceXZ::Draw(Shader * shad, unsigned int * VBO, unsigned int * VAO)
{
	glBindVertexArray(*VAO);
	// calculate the model matrix for each object and pass it to shader before drawing
	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	float angle = 20.0f * 0;
	model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
	shad->setMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}


void FaceXZ::setVertices()
{
	float vertices1[] =
	{
	Position.x, Position.y, Position.z, 0.0f, -1.0f,  0.0f,  0.0f, 0.2f * (EndPosition.x - Position.x),
	EndPosition.x, Position.y, Position.z, 0.0f, -1.0f,  0.0f,  0.2f * (EndPosition.z - Position.z), 0.2f * (EndPosition.x - Position.x),
	EndPosition.x, Position.y,  EndPosition.z, 0.0f, -1.0f,  0.0f,   0.2f * (EndPosition.z - Position.z), 0.0f,
	EndPosition.x, Position.y,  EndPosition.z,  0.0f, -1.0f,  0.0f,  0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x, Position.y,  EndPosition.z, 0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
	Position.x, Position.y, Position.z,  0.0f, -1.0f,  0.0f, 0.0f, 0.2f * (EndPosition.x - Position.x)
	};	
	float vertices2[] =
	{
	Position.x, Position.y, Position.z,  0.0f, 0.2f * (EndPosition.x - Position.x),
	EndPosition.x, Position.y, Position.z,  0.2f * (EndPosition.z - Position.z), 0.2f * (EndPosition.x - Position.x),
	EndPosition.x, Position.y,  EndPosition.z,  0.2f * (EndPosition.z - Position.z), 0.0f,
	EndPosition.x, Position.y,  EndPosition.z,  0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x, Position.y,  EndPosition.z, 0.0f, 0.0f,
	Position.x, Position.y, Position.z, 0.0f, 0.2f * (EndPosition.x - Position.x)
	};
	for (int i = 0; i < 48; i++)
		vertices[i] = vertices1[i];
	for (int i = 0; i < 30; i++)
		mapVertices[i] = vertices2[i];
}

FaceZY::FaceZY() :
	Position(glm::vec3(0.0f, 0.0f, 0.0f)),
	Size(glm::vec3(0.0f, 0.0f, 0.0f))
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

FaceZY::~FaceZY()
{

}

FaceZY::FaceZY(const FaceZY &_cop)
{
	this->Position = _cop.Position;

	this->Size = _cop.Size;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
}

FaceZY::FaceZY(glm::vec3 position, glm::vec3 size) :
	Position(position),
	Size(size)
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

void FaceZY::setXPos(const float & x)
{
	Position.x = x;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

void FaceZY::setYPos(const float & y)
{
	Position.y = y;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

void FaceZY::setZPos(const float & z)
{
	Position.z = z;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();

}

void FaceZY::setPos(glm::vec3 position)
{
	Position = position;
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	setVertices();
}

float FaceZY::getXPos()
{
	return Position.x;
}

float FaceZY::getYPos()
{
	return Position.y;
}

float FaceZY::getZPos()
{
	return Position.z;
}

float FaceZY::getXEndPos()
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	return EndPosition.x;
}

float FaceZY::getYEndPos()
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	return EndPosition.y;
}

float FaceZY::getZEndPos()
{
	EndPosition.x = Position.x + Size.x;
	EndPosition.y = Position.y + Size.y;
	EndPosition.z = Position.z + Size.z;
	return EndPosition.z;
}

void FaceZY::Draw(Shader * shad, unsigned int * VBO, unsigned int * VAO)
{
	glBindVertexArray(*VAO);
	// calculate the model matrix for each object and pass it to shader before drawing
	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	float angle = 20.0f * 0;
	model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
	shad->setMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}


void FaceZY::setVertices()
{
	float vertices1[] =
	{
	Position.x,  EndPosition.y,  EndPosition.z, -1.0f,  0.0f,  0.0f,   0.0f, 0.2f*(EndPosition.y - Position.y),
	Position.x,  EndPosition.y, Position.z, -1.0f,  0.0f,  0.0f, 0.2f * (EndPosition.z - Position.z),  0.2f * (EndPosition.y - Position.y),
	Position.x, Position.y, Position.z, -1.0f,  0.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x, Position.y, Position.z, -1.0f,  0.0f,  0.0f, 0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x, Position.y,  EndPosition.z, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	Position.x,  EndPosition.y,  EndPosition.z, -1.0f,  0.0f,  0.0f, 0.0f, 0.2f * (EndPosition.y - Position.y)
	};
	float vertices2[] =
	{
	Position.x,  EndPosition.y,  EndPosition.z,  0.0f, 0.2f*(EndPosition.y - Position.y),
	Position.x,  EndPosition.y, Position.z, 0.2f * (EndPosition.z - Position.z),  0.2f * (EndPosition.y - Position.y),
	Position.x, Position.y, Position.z, 0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x, Position.y, Position.z, 0.2f * (EndPosition.z - Position.z), 0.0f,
	Position.x, Position.y,  EndPosition.z,  0.0f, 0.0f,
	Position.x,  EndPosition.y,  EndPosition.z, 0.0f, 0.2f * (EndPosition.y - Position.y)
	};
	for (int i = 0; i < 48; i++)
		vertices[i] = vertices1[i];
	for (int i = 0; i < 30; i++)
		mapVertices[i] = vertices2[i];
}
