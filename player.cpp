#include "player.h"

Playerr::Playerr()
{
}

Playerr::~Playerr()
{
}

Playerr::Playerr(glm::vec3 pos1, glm::vec3 pos2)
{
	initCam1(pos1);
	initCam2(pos2);
}

void Playerr::CopyPosition()
{

}

void Playerr::initCam1(glm::vec3 pos)
{
	camera1 = new Camera(pos);
}

void Playerr::initCam2(glm::vec3 pos)
{
	camera2 = new Camera(pos);
}

void Playerr::setCam1(glm::mat4 * proj, Shader* shad, glm::mat4 * view, const unsigned int wid, const unsigned int hei)
{

	*proj = glm::perspective(glm::radians(camera1->Zoom), (float)wid / (float)(hei / 1.3), 0.1f, 100.0f);
	shad->setMat4("projection", *proj);
	*view = camera1->GetViewMatrix();
	shad->setMat4("view", *view);
}

void Playerr::setCam2(glm::mat4 * proj, Shader* shad, glm::mat4 * view, const unsigned int wid, const unsigned int hei)
{
	camera2->setPitch(-90.0f);
	camera2->setYaw(180.0f);
	*proj = glm::perspective(glm::radians(camera2->Zoom), ((float)(hei)-(float)(hei / 1.3)) / ((float)(hei)-(float)(hei / 1.3)), 0.1f, 100.0f);
	shad->setMat4("projection", *proj);
	*view = camera2->GetViewMatrix();
	shad->setMat4("view", *view);
}

void Playerr::setPosition(glm::vec3 pos)
{
	Position = pos;
	updatePosition();
}

void Playerr::updatePosition()
{
	camera1->setX(Position.x);
	camera1->setZ(Position.z);
	camera2->setX(Position.x);
	camera2->setZ(Position.z);
	updateVert();
}

void Playerr::updateVert()
{


	miniMapCursor = new Box(glm::vec3(camera2->getX(), 11.2f, camera2->getZ()), glm::vec3(0.30f, 0.30f, 0.30f));
	 
}
void Playerr::drawPoint(Shader * colorShader, unsigned int * VBO, unsigned int * VAO)
{
	updateVert();

	glBufferData(GL_ARRAY_BUFFER, sizeof(miniMapCursor->vertices), miniMapCursor->vertices, GL_STATIC_DRAW);

	miniMapCursor->Draw(colorShader, VBO, VAO);
}
