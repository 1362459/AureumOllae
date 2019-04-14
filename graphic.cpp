#include "graphic.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


using namespace irrklang;
Graphic::Graphic()
{
	
	player1 = Playerr(glm::vec3(0.5f, 2.0f, 3.0f), glm::vec3(0.0f, 15.7f, -0.5f));
	player1.initEQ(glm::vec3(0.0f, 0.0f, 0.0f));
	
	faceonMap3 = FaceZY(glm::vec3(5.0f, -5.0f, -20.0f), glm::vec3(2.0f, 10.0f, 40.0f));
	faceonMap4 = FaceZY(glm::vec3(5.0f, -5.0f, -20.0f), glm::vec3(2.0f, 10.0f, 40.0f));
	Sword = Box(glm::vec3(4.5f, -1.5f, 0.0f), glm::vec3(0.1f, 1.0f, 1.0f));
	Sword1 = Box(glm::vec3(4.5f, 0.0f, 0.0f), glm::vec3(0.1f, 1.0f, 1.0f));
	Sword2 = Box(glm::vec3(4.5f, -1.5f, 1.5f), glm::vec3(0.1f, 1.0f, 1.0f));
	Sword3 = Box(glm::vec3(4.5f, 0.0f, 1.5f), glm::vec3(0.1f, 1.0f, 1.0f));
	Red = FaceZY(glm::vec3(4.5f, 0.0f, -7.0f), glm::vec3(0.15f, 1.2f, 0.15f));
	Green = FaceZY(glm::vec3(4.5f, 0.0f, -6.6f), glm::vec3(0.15f, 1.2f, 0.15f));
	Blue = FaceZY(glm::vec3(4.5f, 0.0f, -6.2f), glm::vec3(0.15f, 1.2f, 0.15f));


}

void Graphic::initMap(GameManager & test)
{

		player1.initCam1(glm::vec3(test.playerPositionY*1.0f, 1.5f, test.playerPositionX*1.0f));
		player1.initCam2(glm::vec3(test.playerPositionY*1.0f, 16.5f, test.playerPositionX*1.0f));
		
		std::vector <glm::vec3*> PosXYSet;
		std::vector <glm::vec3*> PosZYSet;


		glm::vec3 XYPosition(0.0f, 0.0f, 0.0f);
		glm::vec3 ZYPosition(0.0f, 0.0f, 0.0f);

		xmap = test.mapa->xIndex;

		ymap = test.mapa->yIndex;
		test.boardMap->testShow();
		if (test.boardMap->objectsMap)
		{
			for (int i = 0; i < xmap; i++)
			{

				if (test.boardMap->objectsMap[i]!= NULL)
				{
					for (int j = 0; j < ymap; j++)
					{
						if (test.boardMap->objectsMap[i][j])
						{
							if (test.boardMap->objectsMap[i][j]->whatAmI() == '#')
							{
								Items.push_back(new Box(glm::vec3(j*1.0f, 0.0f, i*1.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
							}
							if (test.boardMap->objectsMap[i][j]->whatAmI() == 'E')
							{
								Lights.push_back(new Light(glm::vec3(j*1.0f, 3.0f, i*1.0f)));
							}
						}

					}
				}
			}

		}
		// Sprawdzanie czy pozycja ju¿ zaklepana



		tab = new int*[xmap + 1];
		xyBinPosition = new bool*[xmap + 1];
		zyBinPosition = new bool*[xmap + 1];
		for (int i = 0; i < xmap + 1; i++)
		{
			tab[i] = new int[ymap + 1];
			xyBinPosition[i] = new bool[ymap + 1];
			zyBinPosition[i] = new bool[ymap + 1];

			for (int j = 0; j < ymap + 1; j++)
			{
				if (i == xmap || j == ymap)
				{
					tab[i][j] = 0;
				}
				else
				{
					tab[i][j] = test.mapa->map[i][j];
				}
				xyBinPosition[i][j] = false;
				zyBinPosition[i][j] = false;
			}
		}
		int faceOnX = 0;
		int faceOnZ = 0;	

		faceXZVector.push_back(new Box(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3((xmap + 1)*1.0f, 0.0f, (ymap + 1)*1.0f)));
		faceXZVector.push_back(new Box(glm::vec3(0.0f, 10.0f, 0.0f), glm::vec3((xmap + 1)*1.0f, 0.0f, (ymap + 1)*1.0f)));
		//std::cout << "\n";

		for (int i = 0; i < xmap; i++)
		{
			for (int j = 0; j < ymap; j++)
			{
				if (tab[i][j] == 1 && xyBinPosition[i][j] == false)
				{
					if (tab[i][j + 1] == 1)
					{
						if (faceOnX == 0)
						{
							XYPosition = glm::vec3(j*1.0f, 0.0f, i*1.0f);
						}
						faceOnX++;

						xyBinPosition[i][j] = true;
					}
					else
					{
						if (faceOnX > 0)
						{
							faceXYVector.push_back(new Box(XYPosition, glm::vec3(faceOnX*1.0f, 10.0f, 0.01f)));
							/*std::cout << "x: " << XYPosition.x << " y: " << XYPosition.y << " z: " << XYPosition.z << " FaceOnX: " << faceOnX << std::endl;
							*/faceOnX = 0;

							xyBinPosition[i][j] = true;
						}
					}
					if (tab[i + 1][j] == 0 && tab[i][j + 1] == 0 && tab[i][j - 1])
					{
						tab[i][j] = 0;
					}
					if (tab[i][j] == 1 && tab[i + 1][j] == 1)
					{
						for (int k = i; k < xmap; k++)
						{
							if (tab[k][j] == 0)
							{
								break;
							}
							if (tab[k][j] == 1 && tab[k + 1][j] == 1 && zyBinPosition[k][j] == false)
							{
								if (faceOnZ == 0)
								{
									ZYPosition = glm::vec3(j*1.0f, 0.0f, i*1.0f);
								}
								faceOnZ++;
								zyBinPosition[k][j] = true;
							}
							else
							{
								if (faceOnZ > 0 && zyBinPosition[k][j] == false)
								{
									faceZYVector.push_back(new Box(ZYPosition, glm::vec3(0.01f, 10.0f, faceOnZ*1.0f)));
									/*std::cout << "x: " << ZYPosition.x << " y: " << ZYPosition.y << " z: " << ZYPosition.z << " FaceOnZ: " << faceOnZ << std::endl;
									*/faceOnZ = 0;
									zyBinPosition[k][j] = true;
								}
							}
							if (k == i)
							{
								tab[k][j] = 0;
							}
							else
							{
								if (tab[k][j + 1] == 0 && tab[k][j - 1] == 0 && tab[k + 1][j] == 0)
								{
									tab[k][j] = 0;
								}

							}
						}
						tab[i][j] = 0;
					}
				}

			}
		}



}

void Graphic::initTextures(Shader * textureShader, Shader * texShader)
{
	

	SoundEngine = createIrrKlangDevice();
	SoundEngine->play2D("Engine/audio/breakout.mp3", GL_TRUE);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);/*
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);*/

	/*glGenVertexArrays(2, &colorVAO);
	glGenBuffers(2, &colorVBO);
	glBindVertexArray(colorVAO);
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO);*/

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// note that we update the lamp's position attribute's stride to reflect the updated buffer data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	woutVBO = VBO;
	glGenVertexArrays(1, &woutVAO);
	glBindVertexArray(woutVAO);


	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	
	glGenTextures(1, &wallTextureXY);
	glBindTexture(GL_TEXTURE_2D, wallTextureXY);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// load image, create texture and generate mipmaps
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "wallTextureXY loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	textureShader->use();
	textureShader->setInt("wallTextureXY", 0);
	texShader->use();
	texShader->setInt("wallTextureXY", 0);





	// texture 1
	// ---------
	glGenTextures(1, &wallTextureZY);
	glBindTexture(GL_TEXTURE_2D, wallTextureZY);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width1, height1, nrChannels1;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char *data1 = stbi_load("container2.jpg", &width1, &height1, &nrChannels1, 0);

	if (data1)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width1, height1, 0, GL_RGB, GL_UNSIGNED_BYTE, data1);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "wallTextureZY loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data1);

	textureShader->use();
	textureShader->setInt("wallTextureZY", 1);
	texShader->use();
	texShader->setInt("wallTextureZY", 1);

	glGenTextures(1, &floorTexture);
	glBindTexture(GL_TEXTURE_2D, floorTexture);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width2, height2, nrChannels2;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char *data2 = stbi_load("floor.jpg", &width2, &height2, &nrChannels2, 0);

	if (data2)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, data2);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "floorTexture loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data2);

	textureShader->use();
	textureShader->setInt("floorTexture", 2);
	texShader->use();
	texShader->setInt("floorTexture", 2);




	glGenTextures(1, &playerTex);
	glBindTexture(GL_TEXTURE_2D, playerTex);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width3, height3, nrChannels3;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char *data3 = stbi_load("player.png", &width3, &height3, &nrChannels3, 0);

	if (data3)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width3, height3, 0, GL_RGB, GL_UNSIGNED_BYTE, data3);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "playerTexture loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data3);

	textureShader->use();
	textureShader->setInt("playerTex", 3);
	texShader->use();
	texShader->setInt("playerTex", 3);




	glGenTextures(1, &eqTexture);
	glBindTexture(GL_TEXTURE_2D, eqTexture);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width4, height4, nrChannels4;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char *data4 = stbi_load("papyrus.jpg", &width4, &height4, &nrChannels4, 0);

	if (data4)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width4, height4, 0, GL_RGB, GL_UNSIGNED_BYTE, data4);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "eqTexture loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data4);

	textureShader->use();
	textureShader->setInt("eqTexture", 4);
	texShader->use();
	texShader->setInt("eqTexture", 4);


	glGenTextures(1, &ceilingTexture);
	glBindTexture(GL_TEXTURE_2D, ceilingTexture);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// load image, create texture and generate mipmaps
	int width5, height5, nrChannels5;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char *data5 = stbi_load("ceil.jpeg", &width5, &height5, &nrChannels5, 0);

	if (data5)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width5, height5, 0, GL_RGB, GL_UNSIGNED_BYTE, data5);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "ceilTexture loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data5);

	textureShader->use();
	textureShader->setInt("ceilingTexture", 5);
	texShader->use();
	texShader->setInt("ceilingTexture", 5);



	glGenTextures(1, &swordTex);
	glBindTexture(GL_TEXTURE_2D, swordTex);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// load image, create texture and generate mipmaps
	int width6, height6, nrChannels6;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char *data6 = stbi_load("sword.jpg", &width6, &height6, &nrChannels6, 0);

	if (data6)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width6, height6, 0, GL_RGB, GL_UNSIGNED_BYTE, data6);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "swordTexture loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data6);

	textureShader->use();
	textureShader->setInt("swordTex", 6);
	texShader->use();
	texShader->setInt("swordTex", 6);


	glGenTextures(1, &redTexture);
	glBindTexture(GL_TEXTURE_2D, redTexture);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width7, height7, nrChannels7;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char *data7 = stbi_load("red.jpg", &width7, &height7, &nrChannels7, 0);

	if (data7)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width7, height7, 0, GL_RGB, GL_UNSIGNED_BYTE, data7);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "redTexture loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data7);


	textureShader->use();
	textureShader->setInt("redTexture", 7);
	texShader->use();
	texShader->setInt("redTexture", 7);

	glGenTextures(1, &greenTexture);
	glBindTexture(GL_TEXTURE_2D, greenTexture);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width8, height8, nrChannels8;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char *data8 = stbi_load("green.jpg", &width8, &height8, &nrChannels8, 0);

	if (data8)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width8, height8, 0, GL_RGB, GL_UNSIGNED_BYTE, data8);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "greenTexture loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data8);



	textureShader->use();
	textureShader->setInt("greenTexture", 8);
	texShader->use();
	texShader->setInt("greenTexture", 8);




	glGenTextures(1, &blueTexture);
	glBindTexture(GL_TEXTURE_2D, blueTexture);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width9, height9, nrChannels9;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char *data9 = stbi_load("blue.jpg", &width9, &height9, &nrChannels9, 0);

	if (data9)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width9, height9, 0, GL_RGB, GL_UNSIGNED_BYTE, data9);
		glGenerateMipmap(GL_TEXTURE_2D);
		std::cout << "blueTexture loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data9);


	textureShader->use();
	textureShader->setInt("blueTexture", 9);
	texShader->use();
	texShader->setInt("blueTexture", 9);

	textureShader->use();
	pointLightPositions[0] = glm::vec3(0.7f, 0.2f, 2.0f);
	pointLightPositions[1] = glm::vec3(2.3f, -3.3f, -4.0f);
		pointLightPositions[2] = glm::vec3(-4.0f, 2.0f, -12.0f);
		pointLightPositions[3] = glm::vec3(0.0f, 0.0f, -3.0f);

}







void Graphic::Draw(int& widx, int& heiy, int SCR_WIDTH, int SCR_HEIGHT, Shader * textureShader, Shader * lampShader, Shader * texShader)
{


	// activate shader
	textureShader->use();
	textureShader->setVec3("viewPos", player1.camera1->Position);
	textureShader->setFloat("material.shininess", 64.0f);



	

	/*
		  Here we set all the uniforms for the 5/6 types of lights we have. We have to set them manually and index
		  the proper PointLight struct in the array to set each uniform variable. This can be done more code-friendly
		  by defining light types as classes and set their values in there, or by using a more efficient uniform approach
		  by using 'Uniform buffer objects', but that is something we'll discuss in the 'Advanced GLSL' tutorial.
	   */
	//  //  directional light
	//textureShader->setVec3("dirLight.direction", 2.0f, 2.0f, 2.0f);
	//textureShader->setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
	//textureShader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
	//textureShader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
	//// point light 1
	for (int i = 0; i < Lights.size(); i++)
	{
		textureShader->setVec3("pointLights["+std::to_string(i)+"].position", Lights[i]->pointLightPosition);
		textureShader->setVec3("pointLights[" + std::to_string(i) + "].ambient", 0.05f, 0.05f, 0.05f);
		textureShader->setVec3("pointLights[" + std::to_string(i) + "].diffuse", 0.8f, 0.8f, 0.8f);
		textureShader->setVec3("pointLights[" + std::to_string(i) + "].specular", 1.0f, 1.0f, 1.0f);
		textureShader->setFloat("pointLights[" + std::to_string(i) + "].constant", 1.0f);
		textureShader->setFloat("pointLights[" + std::to_string(i) + "].linear", 0.9);
		textureShader->setFloat("pointLights[" + std::to_string(i) + "].quadratic", 0.032);
	}

	//// point light 2
	//textureShader->setVec3("pointLights[1].position", pointLightPositions[1]);
	//textureShader->setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
	//textureShader->setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
	//textureShader->setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
	//textureShader->setFloat("pointLights[1].constant", 1.0f);
	//textureShader->setFloat("pointLights[1].linear", 0.09);
	//textureShader->setFloat("pointLights[1].quadratic", 0.032);
	//// point light 3
	//textureShader->setVec3("pointLights[2].position", pointLightPositions[2]);
	//textureShader->setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
	//textureShader->setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
	//textureShader->setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
	//textureShader->setFloat("pointLights[2].constant", 1.0f);
	//textureShader->setFloat("pointLights[2].linear", 0.09);
	//textureShader->setFloat("pointLights[2].quadratic", 0.032);
	//// point light 4
	//textureShader->setVec3("pointLights[3].position", pointLightPositions[3]);
	//textureShader->setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
	//textureShader->setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
	//textureShader->setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
	//textureShader->setFloat("pointLights[3].constant", 1.0f);
	//textureShader->setFloat("pointLights[3].linear", 0.09);
	//textureShader->setFloat("pointLights[3].quadratic", 0.032);
	//// spotLight













	//for (unsigned int i = 0; i < Lights.size(); i++)
	//{
	//	Lights[i]->setLight(textureShader);
	//}
	// spotLight
	textureShader->setVec3("spotLight.position", player1.camera1->Position);
	textureShader->setVec3("spotLight.direction", player1.camera1->Front);
	textureShader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
	textureShader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
	textureShader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
	textureShader->setFloat("spotLight.constant", 1.0f);
	textureShader->setFloat("spotLight.linear", 0.045);
	textureShader->setFloat("spotLight.quadratic", 0.0075);
	textureShader->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
	textureShader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

	glViewport(0, (float)heiy - (float)heiy / 1.3, widx, (float)heiy / 1.3);
	glm::mat4 projection;
	glm::mat4 view;
	player1.setCam1(&projection, textureShader, &view, SCR_WIDTH, SCR_HEIGHT);

	glBindTexture(GL_TEXTURE_2D, wallTextureXY);

	for (int i = 0; i < faceXYVector.size(); i++)
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(faceXYVector[i]->vertices), faceXYVector[i]->vertices, GL_STATIC_DRAW);
		faceXYVector[i]->Draw(textureShader, &VBO, &VAO);
	}

	glBindTexture(GL_TEXTURE_2D, wallTextureZY);
	for (int i = 0; i < faceZYVector.size(); i++)
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(faceZYVector[i]->vertices), faceZYVector[i]->vertices, GL_STATIC_DRAW);
		faceZYVector[i]->Draw(textureShader, &VBO, &VAO);
	}
	glBindTexture(GL_TEXTURE_2D, swordTex);
	for (int i = 0; i < Items.size(); i++)
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(Items[i]->itemVertices), Items[i]->itemVertices, GL_STATIC_DRAW);
		Items[i]->Draw(textureShader, &VBO, &VAO);
	}

	glBindTexture(GL_TEXTURE_2D, floorTexture);

	glBufferData(GL_ARRAY_BUFFER, sizeof(faceXZVector[0]->vertices), faceXZVector[0]->vertices, GL_STATIC_DRAW);
	faceXZVector[0]->Draw(textureShader, &VBO, &VAO);

	glBindTexture(GL_TEXTURE_2D, ceilingTexture);
	glBufferData(GL_ARRAY_BUFFER, sizeof(faceXZVector[1]->vertices), faceXZVector[1]->vertices, GL_STATIC_DRAW);
	faceXZVector[1]->Draw(textureShader, &VBO, &VAO);

/*
	glBindTexture(GL_TEXTURE_2D, wallTextureZY);
	player1.drawPoint(textureShader, &VBO, &VAO);*/

	lampShader->use();
	lampShader->setMat4("projection", projection);
	lampShader->setMat4("view", view);

	//// we now draw as many light bulbs as we have point lights.
	//glBindVertexArray(lightVAO);
	//for (unsigned int i = 0; i < Lights.size(); i++)
	//{

	//	glm::mat4 model = glm::mat4(1.0f);
	//	model = glm::translate(model, Lights[i]->pointLightPosition);
	//	model = glm::scale(model, glm::vec3(0.02f)); // Make it a smaller cube
	//	lampShader->setMat4("model", model);
	//	glDrawArrays(GL_TRIANGLES, 0, 36);
	//}




	texShader->use();
	widMap2 = (float)heiy - (float)heiy / 1.3;
	heiMap2 = (float)heiy - (float)heiy / 1.3;
	xMap2 = (float)widx - ((float)heiy - (float)heiy / 1.3);
	yMap2 = 0.0;

	glViewport(xMap2, yMap2, widMap2, heiMap2);

	glm::mat4 projection2;
	glm::mat4 view2;
	player1.setCam2(&projection2, texShader, &view2, SCR_WIDTH, SCR_HEIGHT);

	// render boxes
	glBindTexture(GL_TEXTURE_2D, wallTextureXY);
	for (int i = 0; i < faceXYVector.size(); i++)
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(faceXYVector[i]->mapVertices), faceXYVector[i]->mapVertices, GL_STATIC_DRAW);
		faceXYVector[i]->Draw(texShader, &woutVBO, &woutVAO);
	}
	glBindTexture(GL_TEXTURE_2D, wallTextureZY);
	for (int i = 0; i < faceZYVector.size(); i++)
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(faceZYVector[i]->mapVertices), faceZYVector[i]->mapVertices, GL_STATIC_DRAW);
		faceZYVector[i]->Draw(texShader, &woutVBO, &woutVAO);
	}
	glBindTexture(GL_TEXTURE_2D, swordTex);
	for (int i = 0; i < Items.size(); i++)
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(Items[i]->mapVertices), Items[i]->mapVertices, GL_STATIC_DRAW);
		Items[i]->Draw(texShader, &woutVBO, &woutVAO);
	}

	glBindTexture(GL_TEXTURE_2D, floorTexture);

	glBufferData(GL_ARRAY_BUFFER, sizeof(faceXZVector[0]->mapVertices), faceXZVector[0]->mapVertices, GL_STATIC_DRAW);
	faceXZVector[0]->Draw(texShader, &woutVBO, &woutVAO);


	// bind textures on corresponding texture units
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, playerTex);
	player1.drawPoint(texShader, &woutVBO, &woutVAO);

	glm::mat4 projection3;
	glm::mat4 view3;
	float widMap3, heiMap3, xMap3, yMap3;
	xMap3 = 0.0f;
	yMap3 = 0.0f;
	widMap3 = widx - widMap2;
	heiMap3 = heiMap2;

	glBindTexture(GL_TEXTURE_2D, eqTexture);
	glViewport(xMap3, yMap3, widMap3, heiMap3);
	player1.setEQ(&projection3, texShader, &view3, widMap3, heiMap3, xMap3, yMap3);

	glBufferData(GL_ARRAY_BUFFER, sizeof(faceonMap3.mapVertices), faceonMap3.mapVertices, GL_STATIC_DRAW);
	faceonMap3.Draw(texShader, &woutVBO, &woutVAO);

	glBindTexture(GL_TEXTURE_2D, swordTex);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Sword.mapVertices), Sword.mapVertices, GL_STATIC_DRAW);
	Sword.Draw(texShader, &woutVBO, &woutVAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Sword1.mapVertices), Sword1.mapVertices, GL_STATIC_DRAW);
	Sword1.Draw(texShader, &woutVBO, &woutVAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Sword2.mapVertices), Sword2.mapVertices, GL_STATIC_DRAW);
	Sword2.Draw(texShader, &woutVBO, &woutVAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Sword3.mapVertices), Sword3.mapVertices, GL_STATIC_DRAW);
	Sword3.Draw(texShader, &woutVBO, &woutVAO);

	glBindTexture(GL_TEXTURE_2D, greenTexture);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Green.mapVertices), Green.mapVertices, GL_STATIC_DRAW);
	Green.Draw(texShader, &woutVBO, &woutVAO);


	glBindTexture(GL_TEXTURE_2D, redTexture);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Red.mapVertices), Red.mapVertices, GL_STATIC_DRAW);
	Red.Draw(texShader, &woutVBO, &woutVAO);


	glBindTexture(GL_TEXTURE_2D, blueTexture);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Blue.mapVertices), Blue.mapVertices, GL_STATIC_DRAW);
	Blue.Draw(texShader, &woutVBO, &woutVAO);


	//glBufferData(GL_ARRAY_BUFFER, sizeof(faceonMap4.vertices), faceonMap4.vertices, GL_STATIC_DRAW);
	//faceonMap4.Draw(&textureShader, &VBO, &VAO);

}
