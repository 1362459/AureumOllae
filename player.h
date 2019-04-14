#ifndef PLAYER_H
#define PLAYER_H

#include "box.h"
#include "camera.h"
#include "shader.h"

class Playerr
{
public:

	Playerr();

	~Playerr();

	Playerr(glm::vec3 pos1, glm::vec3 pos2);

	void CopyPosition();

	Camera *camera1, *camera2;

	void initCam1(glm::vec3 pos);

	void initCam2(glm::vec3 pos);

	void setCam1(glm::mat4 * proj, Shader* shad, glm::mat4 * view, const unsigned int wid, const unsigned int hei);

	void setCam2(glm::mat4 * proj, Shader* shad, glm::mat4 * view, const unsigned int wid, const unsigned int hei);

	void setPosition(glm::vec3 pos);

	void updatePosition();

	void drawPoint(Shader * colorShader, unsigned int * VBO, unsigned int * VAO);

private:

	void updateVert();

	float vertices[15];

	glm::vec3 Position;

	Box * miniMapCursor;


};



#endif