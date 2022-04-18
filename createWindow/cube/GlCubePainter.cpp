#include "GlCubePainter.h"
#include <glad/glad.h>
#include <glfw3.h>




#include "../ShaderReader/MyShader.h"
#include "../TextureManager/TextureManager.h"
#include "../GlfwConfigure//GlfwConfigure.h"
#include "../ShaderReader/ShaderBuilder.h"

#include <iostream>
using std::cout;
using std::endl;


static const char* vertextShaderPath = "shader/squareShader/vertextShaderSquare.txt";
static const char* fragmentShaderPath = "shader/squareShader/fragmentShaderSquare.txt";

static const char* MY_IMAGE_PATH_1 = "image/container.png";
static const char* MY_IMAGE_PATH_2 = "image/container_specular.png";

static const int verticesNum = 288;
static const double circleVertices[verticesNum] = {
 -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};


GlCubePainter::GlCubePainter(int widthWindow, int heightWindow)
	:m_widthWindow(widthWindow), m_heightWindow(heightWindow), m_shaderManager(new ShaderBuilder(vertextShaderPath, fragmentShaderPath))
{
	m_myShader = m_shaderManager->getMyShader();
	if (configureShader() == false) {
		cout << "configureShader failed" << endl;
	};
}

GlCubePainter::GlCubePainter(const PointGl& point, int width, int widthWindow, int heightWindow)
	:m_widthWindow(widthWindow), m_heightWindow(heightWindow), m_shaderManager(new ShaderBuilder(vertextShaderPath, fragmentShaderPath))
{
	m_myShader = m_shaderManager->getMyShader();
	addOne(point, width);
	if (configureShader() == false) {
		cout << "configureShader failed" << endl;
	};
}

void GlCubePainter::draw() const
{
	// bind textures on corresponding TEXTURE units
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_texture1);

	glUseProgram(shaderProgram);
	for (auto it : m_vao) {
		glBindVertexArray(it);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

}

void GlCubePainter::setWindowSize(const int widthWindow, const int heightWindow)
{
	m_widthWindow = widthWindow;
	m_heightWindow = heightWindow;
}

void GlCubePainter::addOne(const PointGl& point, int width)
{
	float k = static_cast<float>(width) / static_cast<float>(m_widthWindow);
	float offsetX = 2.0*static_cast<float>(point.first)/ static_cast<float>(m_widthWindow);
	float offsetY = 2.0*static_cast<float>(point.second) / static_cast<float>(m_heightWindow);


	volatile float tmp;
	int index;
	static float tmpVertices[verticesNum] = { 0 };
	for (int i = 0; i < (verticesNum / 6); ++i) {
		for (int j = 0; j < 6; ++j) {
			index = i * 6 + j;
			tmpVertices[index] = static_cast<float>(circleVertices[index]);
		}
	}

	for (int i = 0; i < (verticesNum/6); ++i) {
		for (int j = 0; j < 6; ++j) {
			switch (j) {
			case 0: {
				tmp = tmpVertices[i * 6 + j];
				tmpVertices[i * 6 + j] = tmp*k + offsetX;
				break;
			}
			case 1: {
				tmp = tmpVertices[i * 6 + j];
				tmpVertices[i * 6 + j] = tmp*k + offsetY;
				break;
			}
			}
		}
	}

	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	//VBO
	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(circleVertices), circleVertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tmpVertices), tmpVertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	m_vao.push_back(m_VAO);
	GlPainter::vao.push_back(m_VAO);
	GlPainter::vao.push_back(m_VBO);
}

void GlCubePainter::setModelMatrix(const glm::mat4& mat)
{
	m_myShader->setModelMatrix(mat);
}

void GlCubePainter::setViewMatrix(const glm::mat4& mat)
{
	m_myShader->setViewMatrix(mat);
}

void GlCubePainter::setProjectionMatrix(const glm::mat4& mat)
{
	m_myShader->setProjectionMatrix(mat);
}

void GlCubePainter::setUniformVec3(const glm::vec3 & vec, const char * uniform)
{
	m_myShader->setUniformVec3(vec, uniform);
}

void GlCubePainter::setUniformFloat1(const float & value, const char * uniform)
{
	m_myShader->setUniformFloat1(value, uniform);
}

bool GlCubePainter::configureShader()
{
	if (m_myShader->configure() == false)
		return false;

	//get shader program
	shaderProgram = m_myShader->getShaderProgram();

	glEnable(GL_DEPTH_TEST);
	glUseProgram(shaderProgram);

	//load texture0 Data
	TextureManager textureManager(GL_RGBA);
	if (textureManager.loadImage(MY_IMAGE_PATH_1, m_texture0) == false)
		return false;
	m_myShader->setUniformInt1(0, "material.diffuse");

	if (textureManager.loadImage(MY_IMAGE_PATH_2, m_texture1) == false)
		return false;
	m_myShader->setUniformInt1(1, "material.specular");
	return true;
}
