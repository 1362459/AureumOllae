#include <iostream>
#include <string>
#include "Light.h"
int Light::id = 0;
Light::Light():
	pointLightPosition(glm::vec3(0.0f, 0.0f, 0.0f))
{
	id++;
}

Light::Light(glm::vec3 position):
pointLightPosition(position)
{
	id++;
}

Light::Light(const Light & _copy) :
	pointLightPosition(_copy.pointLightPosition)
{
	name = "pointLights." + std::to_string(id);
	id++;
}

Light::~Light()
{
}

Light & Light::operator=(const Light &_copy)
{
	this->pointLightPosition = _copy.pointLightPosition;
	return *this;
}



void Light::setLight(Shader* textureShader)
{
	textureShader->setVec3(name+".position", pointLightPosition);
	textureShader->setVec3(name+".ambient", 0.05f, 0.05f, 0.05f);
	textureShader->setVec3(name + ".diffuse", 0.8f, 0.8f, 0.8f);
	textureShader->setVec3(name + ".specular", 1.0f, 1.0f, 1.0f);
	textureShader->setFloat(name + ".constant", 1.0f);
	textureShader->setFloat(name + ".linear", 0.09);
	textureShader->setFloat(name + ".quadratic", 0.032);
}


void Light::drawLight()
{

}
