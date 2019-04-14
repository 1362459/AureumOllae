#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include <GL/glad/glad.h>
#include <GL/GLFW/glfw3.h>
#include <GL/glm/glm.hpp>
#include <GL/glm/gtc/matrix_transform.hpp>
#include <GL/glm/gtc/type_ptr.hpp>

#include <GL/irr/irrKlang.h>
#include <vector>
#include <algorithm>
#include "engine.h"
#include "face.h"
#include "playerr.h"
#include "shader.h"
#include "Light.h"

using namespace irrklang;
class Graphic
{
public:
	Graphic();
	~Graphic()
	{
		if (tab != NULL)
		{
			for (int i = 0; i < xmap + 1; i++)
			{
				delete tab[i];
			}
			delete tab;
		}
		if (xyBinPosition != NULL)
		{
			for (int i = 0; i < xmap + 1; i++)
			{
				delete xyBinPosition[i];
			}
			delete xyBinPosition;
		}
		if (zyBinPosition != NULL)
		{
			for (int i = 0; i < xmap + 1; i++)
			{
				delete zyBinPosition[i];
			}
			delete zyBinPosition;
		}
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);

	}


	std::vector<Light*> Lights;

	void initMap(GameManager& test);

	void initTextures(Shader * textureShader, Shader * texShader);


	void Draw(int&, int&, int, int, Shader * textureShader, Shader * lampShader, Shader * texShader);

	Playerr player1;


	std::vector <Box*> faceXYVector;
	
	std::vector <Box*> faceXZVector;
	
	std::vector <Box*> faceZYVector;

	Shader *textureShader;
	Shader *lampShader;
	Shader *multiLightShader;
	glm::vec3 pointLightPositions[4];
	//TEXTURES
	unsigned int wallTextureXY;
	unsigned int wallTextureZY;
	unsigned int floorTexture;
	unsigned int ceilingTexture;
	unsigned int playerTex;
	unsigned int eqTexture;
	unsigned int swordTex;
	unsigned int redTexture;
	unsigned int greenTexture;
	unsigned int blueTexture;
	ISoundEngine *SoundEngine;
	//TEXTURES

	unsigned int VBO, VAO, lightVAO, woutVBO, woutVAO;

private:

	std::vector<Box*> Items;
	FaceZY faceonMap3;
	FaceZY faceonMap4;
	Box Sword;
	Box Sword1;
	Box Sword2;
	Box Sword3;
	FaceZY Red;
	FaceZY Green;
	FaceZY Blue;



	float widMap2, heiMap2, xMap2, yMap2;

	float widMap3, heiMap3, xMap3, yMap3;

	int xmap;
	
	int ymap;
	
	int ** tab;
	
	bool ** xyBinPosition, ** zyBinPosition;
};

#endif