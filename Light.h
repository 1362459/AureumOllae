#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "shader.h"
#include <GL/glm/glm.hpp>
#include <GL/glm/gtc/matrix_transform.hpp>
#include <GL/glm/gtc/type_ptr.hpp>


class Light 
{
public:
	static int id;

	Light();

	Light(glm::vec3 position);

	Light(const Light& _copy);

	~Light();
	
	Light& operator= (const Light&);

	void drawLight();

	glm::vec3 pointLightPosition;

	void setLight(Shader* textureShader);

	std::string name;

};


#endif 