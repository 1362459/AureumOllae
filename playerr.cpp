#include "playerr.h"

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
void Playerr::initEQ(glm::vec3 pos)
{
	eqcamera = new Camera(pos);
}

void Playerr::setCam1(glm::mat4 * proj, Shader* shad, glm::mat4 * view, const unsigned int wid, const unsigned int hei)
{

	*proj = glm::perspective(glm::radians(camera1->Zoom), (float)wid / (float)(hei / 1.3), 0.1f, 300.0f);
	shad->setMat4("projection", *proj);
	*view = camera1->GetViewMatrix();
	shad->setMat4("view", *view);
}

void Playerr::setCam2(glm::mat4 * proj, Shader* shad, glm::mat4 * view, const unsigned int wid, const unsigned int hei)
{
	camera2->setPitch(-90.0f);
	camera2->setYaw(180.0f);
	*proj = glm::perspective(glm::radians(camera2->Zoom), ((float)(hei)-(float)(hei / 1.3)) / ((float)(hei)-(float)(hei / 1.3)), 0.1f, 300.0f);
	shad->setMat4("projection", *proj);
	*view = camera2->GetViewMatrix();
	shad->setMat4("view", *view);
}
void Playerr::setEQ(glm::mat4 * proj, Shader* shad, glm::mat4 * view, const unsigned int wid, const unsigned int hei, const unsigned int xx, const unsigned int yy)
{
	*proj = glm::perspective(glm::radians(eqcamera->Zoom), ((float)wid / (float)(hei)), 0.1f, 100.0f);
	shad->setMat4("projection", *proj);
	*view = eqcamera->GetViewMatrix();
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
	float vertices1[] =
	{
	camera2->getX() - 0.15f, 11.2f, camera2->getZ() - 0.15f,  0.0f, 1.0f, 
	camera2->getX() + 0.15f, 11.2f, camera2->getZ() - 0.15f,  0.0f, 1.0f, 
	camera2->getX() + 0.15f, 11.2f,  camera2->getZ() + 0.15f,  0.0f, 1.0f, 
	camera2->getX() + 0.15f, 11.2f,  camera2->getZ() + 0.15f,  0.0f, 1.0f, 
	camera2->getX() - 0.15f, 11.2f,  camera2->getZ() + 0.15f,  0.0f, 1.0f,
	camera2->getX() - 0.15f, 11.2f, camera2->getZ() - 0.15f,  0.0f, 1.0f
	};
	for (int i = 0; i < 30; i++)
		vertices[i] = vertices1[i];
	 
}
void Playerr::drawPoint(Shader * colorShader, unsigned int * VBO, unsigned int * VAO)
{
	updateVert();

	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);

	glBindVertexArray(*VAO);
	// calculate the model matrix for each object and pass it to shader before drawing
	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	float angle = 20.0f * 0;
	model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
	colorShader->setMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
