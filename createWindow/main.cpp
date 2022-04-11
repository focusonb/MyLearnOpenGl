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

int main() {
	GlfwConfigure* myConfig = GlfwConfigure::getInstance();
	GLFWwindow* window = myConfig->getGlfWindowHandle();
	GlCubePainter cubePainter(WINDOWS_WIDTH, WINDOWS_HEIGHT, CorlorChess::black);
	cubePainter.addOne(PointGl(0, 0), 1000);

	glm::mat4 model(1.0f);
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	cubePainter.setModelMatrix(model);

	glm::mat4 view(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.5f));
	//view = glm::rotate(view, glm::radians(30.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	cubePainter.setViewMatrix(view);

	cubePainter.setProjectionMatrix(glm::perspective(glm::radians(45.0f)
		, 800.0f / 800.0f, 0.1f, 100.0f));

	
	cubePainter.setUniformVec3(glm::vec3 (0.4, 0.1, 0.1), "material.ambient");
	cubePainter.setUniformVec3(glm::vec3 (0.4, 0.1, 0.1), "material.diffuse");
	cubePainter.setUniformVec3(glm::vec3 (0.5, 0.5, 0.5), "material.specular");
	cubePainter.setUniformFloat1(32.0, "material.shininess");
	cubePainter.setUniformVec3(glm::vec3 (0.0, 0.0, 5.0), "light.position");
	cubePainter.setUniformVec3(glm::vec3 (0.2, 0.2, 0.2), "light.ambient");
	cubePainter.setUniformVec3(glm::vec3 (0.5, 0.5, 0.5), "light.diffuse");
	cubePainter.setUniformVec3(glm::vec3 (1.0, 1.0, 1.0), "light.specular");


	//glEnable(GL_DEPTH_TEST);
	float count = 0;
	while (!glfwWindowShouldClose(window))
	{
		Sleep(30);
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		count = 1.0;
		model = glm::rotate(model, glm::radians(count), glm::vec3(1.0f, 1.0f, 1.0f));
		cubePainter.setModelMatrix(model);

		cubePainter.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	GlPainter::deleteVertexArrays();
	GlPainter::deleteBuffers();
	glfwTerminate();
	return 0;
}