#ifndef FACE_H
#define FACE_H
#include "shader.h"
#include <GL/glm/glm.hpp>
#include <GL/glm/gtc/matrix_transform.hpp>
#include <GL/glm/gtc/type_ptr.hpp>



class FaceXY 
{
public:
	FaceXY();
	~FaceXY();
	FaceXY(const FaceXY&);
	FaceXY(glm::vec3 position, glm::vec3 size);
	float vertices[48];
	float mapVertices[30];
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
private: 	
	glm::vec3 Position;
	glm::vec3 EndPosition;
	glm::vec3 Size;
	void setVertices();

};

class FaceZY 
{

public:
	FaceZY();
	~FaceZY();
	FaceZY(const FaceZY&);
	FaceZY(glm::vec3 position, glm::vec3 size);
	float vertices[48];
	float mapVertices[30];
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
private:
	glm::vec3 Position;
	glm::vec3 EndPosition;
	glm::vec3 Size;
	void setVertices();
};

class FaceXZ
{

public:
	FaceXZ();
	~FaceXZ();
	FaceXZ(const FaceXZ&);
	FaceXZ(glm::vec3 position, glm::vec3 size);
	float vertices[48];
	float mapVertices[30];
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
private:
	glm::vec3 Position;
	glm::vec3 EndPosition;
	glm::vec3 Size;
	void setVertices();
};




#endif
