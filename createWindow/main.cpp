#ifdef _DEBUG
#pragma comment(lib, "glfw3d.lib")
#else
#pragma comment(lib, "glfw3.lib")
#endif
#pragma comment(lib, "opengl32.lib")
#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Windows.h>
#include <iostream>


#include "ShaderReader/FIleManager/FileManagerControler.h"
#include "ShaderReader/MyShader.h"



#include "TextureManager/TextureManager.h"
#include "GlfwConfigure/GlfwConfigure.h"
#include "cube/GlCubePainter.h"
#include "CallBack/callback.h"
#include "cube/setCube.h"

int main() {
	GlfwConfigure* myConfig = GlfwConfigure::getInstance();
	GLFWwindow* window = myConfig->getGlfWindowHandle();
	
	auto cubePainter = creatCube();

	float count = 0;
	glm::mat4 model(1.0f);
	while (!glfwWindowShouldClose(window))
	{
		Sleep(30);
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		count = 1.0;
		model = glm::rotate(model, glm::radians(count), glm::vec3(1.0f, 1.0f, 1.0f));

		cubePainter->setModelMatrix(model);
		cubePainter->draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	GlPainter::deleteVertexArrays();
	GlPainter::deleteBuffers();
	glfwTerminate();
	return 0;
}