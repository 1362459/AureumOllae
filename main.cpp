#include <GL/glad/glad.h>
#include <GL/GLFW/glfw3.h>
#include <GL/glm/glm.hpp>
#include <GL/glm/gtc/matrix_transform.hpp>
#include <GL/glm/gtc/type_ptr.hpp>

#include "playerr.h"
#include "shader.h"
#include "camera.h"
#include "engine.h"
#include "face.h"
#include <time.h>
#include <vector>
#include <algorithm>
#include <iostream>


unsigned long long timeCount = 0;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void framebuffer_size_callback1(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 700;

// camera
//Camera camera(glm::vec3(0.0f, 0.0f, -0.5f));
//Camera camera2(glm::vec3(0.0f, 6.7f, -0.5f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

// Player


Graphic game;

int main()
{

	
	GameManager test;
	test.init("Engine/map.ppm");

	game.initMap(test);

	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif


	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Aureum Ollae", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	Shader textureShader("C:/Users/Przemo/source/repos/Aureum Ollae/Aureum Ollae/texture.vs", "C:/Users/Przemo/source/repos/Aureum Ollae/Aureum Ollae/texture.fs");
	Shader multiLightShader("C:/Users/Przemo/source/repos/Aureum Ollae/Aureum Ollae/multilights.vs", "C:/Users/Przemo/source/repos/Aureum Ollae/Aureum Ollae/multilights.fs");
	Shader LampShader("C:/Users/Przemo/source/repos/Aureum Ollae/Aureum Ollae/lamp.vs", "C:/Users/Przemo/source/repos/Aureum Ollae/Aureum Ollae/lamp.fs");

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	// build and compile our shader zprogram
	// ------------------------------------
	game.initTextures(&multiLightShader, &textureShader);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	


	int widx, heiy;
	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		timeCount++;
		
		glfwGetWindowSize(window, &widx, &heiy);
		// per-frame time logic
		// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// input
		// -----
		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		game.Draw(widx, heiy, SCR_WIDTH, SCR_HEIGHT, &multiLightShader, &LampShader, &textureShader);


		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		

		processInput(window);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;


}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		game.player1.camera1->ProcessKeyboard(FORWARD, deltaTime*2.0f);
		
		


		for (int i = 0; i < game.faceXYVector.size(); i++)
		{
			if (game.player1.camera1->getX() >= game.faceXYVector[i]->getXPos() - 0.1f && game.player1.camera1->getX() <= game.faceXYVector[i]->getXEndPos() + 0.1f
				&& game.player1.camera1->getZ() >= game.faceXYVector[i]->getZPos() - 0.1f && game.player1.camera1->getZ() <= game.faceXYVector[i]->getZEndPos() + 0.1f)
			{
				game.player1.camera1->ProcessKeyboard(BACKWARD, deltaTime*2.0f);
				break;
			}
		}
		for (int i = 0; i < game.faceZYVector.size(); i++)
		{
			//std::cout << i;
			if (game.player1.camera1->getX() > game.faceZYVector[i]->getXPos() - 0.1f && game.player1.camera1->getX() <= game.faceZYVector[i]->getXEndPos() + 0.1f
				&& game.player1.camera1->getZ() >= game.faceZYVector[i]->getZPos() - 0.1f && game.player1.camera1->getZ() <= game.faceZYVector[i]->getZEndPos() + 0.1f)
			{
				game.player1.camera1->ProcessKeyboard(BACKWARD, deltaTime*2.0f);
				break;
			}
		}


		if (timeCount % 40 == 0)
			game.SoundEngine->play2D("Engine/audio/foot.wav", GL_FALSE);
		
		
		
		/*if (player1.camera1->getX() <= -0.40 || player1.camera1->getX() >= 4.90 || player1.camera1->getZ() <= -2.40 || player1.camera1->getZ() >= 0.40)
		{
			player1.camera1->ProcessKeyboard(BACKWARD, deltaTime);
		}*/
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		game.player1.camera1->ProcessKeyboard(BACKWARD, deltaTime*2.0f);

		for (int i = 0; i < game.faceXYVector.size(); i++)
		{
			if (game.player1.camera1->getX() >= game.faceXYVector[i]->getXPos() - 0.1f && game.player1.camera1->getX() <= game.faceXYVector[i]->getXEndPos() + 0.1f
				&& game.player1.camera1->getZ() >= game.faceXYVector[i]->getZPos() - 0.1f && game.player1.camera1->getZ() <= game.faceXYVector[i]->getZEndPos() + 0.1f)
			{
				game.player1.camera1->ProcessKeyboard(FORWARD, deltaTime*2.0f);
				break;
			}
		}
		for (int i = 0; i < game.faceZYVector.size(); i++)
		{
			//std::cout << i;
			if (game.player1.camera1->getX() > game.faceZYVector[i]->getXPos() - 0.1f && game.player1.camera1->getX() <= game.faceZYVector[i]->getXEndPos() + 0.1f
				&& game.player1.camera1->getZ() >= game.faceZYVector[i]->getZPos() - 0.1f && game.player1.camera1->getZ() <= game.faceZYVector[i]->getZEndPos() + 0.1f)
			{
				game.player1.camera1->ProcessKeyboard(FORWARD, deltaTime*2.0f);
				break;
			}
		}
		if (timeCount % 40 == 0)
			game.SoundEngine->play2D("Engine/audio/foot.wav", GL_FALSE);
		/*if (player1.camera1->getX() <= -0.40 || player1.camera1->getX() >= 4.90 || player1.camera1->getZ() <= -2.40 || player1.camera1->getZ() >= 0.40)
		{
			player1.camera1->ProcessKeyboard(FORWARD, deltaTime);
		}*/
	}
		
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		game.player1.camera1->ProcessKeyboard(LEFT, deltaTime);
		for (int i = 0; i < game.faceXYVector.size(); i++)
		{
			if (game.player1.camera1->getX() >= game.faceXYVector[i]->getXPos() - 0.1f && game.player1.camera1->getX() <= game.faceXYVector[i]->getXEndPos() + 0.1f
				&& game.player1.camera1->getZ() >= game.faceXYVector[i]->getZPos() - 0.1f && game.player1.camera1->getZ() <= game.faceXYVector[i]->getZEndPos() + 0.1f)
			{
				game.player1.camera1->ProcessKeyboard(RIGHT, deltaTime);
				break;
			}
		}
		for (int i = 0; i < game.faceZYVector.size(); i++)
		{
			//std::cout << i;
			if (game.player1.camera1->getX() > game.faceZYVector[i]->getXPos() - 0.1f && game.player1.camera1->getX() <= game.faceZYVector[i]->getXEndPos() + 0.1f
				&& game.player1.camera1->getZ() >= game.faceZYVector[i]->getZPos() - 0.1f && game.player1.camera1->getZ() <= game.faceZYVector[i]->getZEndPos() + 0.1f)
			{
				game.player1.camera1->ProcessKeyboard(RIGHT, deltaTime);
				break;
			}
		}
		if (timeCount % 40 == 0)
			game.SoundEngine->play2D("Engine/audio/foot.wav", GL_FALSE);


		//if (player1.camera1->getX() <= -0.40 || player1.camera1->getX() >= 4.90 || player1.camera1->getZ() <= -2.40 || player1.camera1->getZ() >= 0.40)
		//{
		//	player1.camera1->ProcessKeyboard(RIGHT, deltaTime);
		//}
	}
		
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		game.player1.camera1->ProcessKeyboard(RIGHT, deltaTime);
		bool back = 0;
		for (int i = 0; i < game.faceXYVector.size(); i++)
		{
			if (game.player1.camera1->getX() >= game.faceXYVector[i]->getXPos()-0.1f && game.player1.camera1->getX() <= game.faceXYVector[i]->getXEndPos()+ 0.1f
				&& game.player1.camera1->getZ() >= game.faceXYVector[i]->getZPos()- 0.1f && game.player1.camera1->getZ() <= game.faceXYVector[i]->getZEndPos()+ 0.1f)
			{
				game.player1.camera1->ProcessKeyboard(LEFT, deltaTime);
					break;
			}
		}
		for (int i = 0; i < game.faceZYVector.size(); i++)
		{
			//std::cout << i;
			if (game.player1.camera1->getX() > game.faceZYVector[i]->getXPos()- 0.1f && game.player1.camera1->getX() <= game.faceZYVector[i]->getXEndPos()+0.1f
				&& game.player1.camera1->getZ() >= game.faceZYVector[i]->getZPos()- 0.1f && game.player1.camera1->getZ() <= game.faceZYVector[i]->getZEndPos()+ 0.1f)
			{
				game.player1.camera1->ProcessKeyboard(LEFT, deltaTime);
					break;
			}
		}
		if (timeCount % 40 == 0)
			game.SoundEngine->play2D("Engine/audio/foot.wav", GL_FALSE);
		
	}




	game.player1.setPosition(game.player1.camera1->getPos());

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.


	glViewport(0, height - height / 1.3, width, height / 1.3);
}
void framebuffer_size_callback1(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.


	glViewport(width - (height - height / 1.3), 0, height - height / 1.3, height - height / 1.3);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	game.player1.camera1->ProcessMouseMovement(xoffset, 0.0);
	//player1.eqcamera->ProcessMouseMovement(xoffset, 0.0);

}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	//player1.camera1->ProcessMouseScroll(yoffset);
}




