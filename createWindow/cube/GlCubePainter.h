#pragma once
#include "GlPainter.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum class CorlorChess { white,black};

using GlSize = int;
using PointGl = std::pair<GlSize, GlSize>;

class GlCubePainter : public GlPainter
{
public:
	GlCubePainter(int widthWindow, int heightWindow, CorlorChess color = CorlorChess::white);
	GlCubePainter(const PointGl& point, int width, CorlorChess color, int widthWindow, int heightWindow);
	void draw() const override;
	void setWindowSize(const int widthWindow, const int heightWindow);
	void setSize(const int& size) override {};
	
	void addOne(const PointGl& point, int width);
	void setModelMatrix(const glm::mat4& mat);
	void setViewMatrix(const glm::mat4& mat);
	void setProjectionMatrix(const glm::mat4& mat);
	void setUniformVec3(const glm::vec3& vec, const char* uniform);
	void setUniformFloat1(const float& value, const char* uniform);

protected:
	bool configureShader(CorlorChess color);

private:
	GLuint VAO, VAO1, VBO, VBO1;
	unsigned int shaderProgram;
	unsigned int texture1;
	int m_widthWindow;
	int m_heightWindow;

	list<GLuint> m_vao;
	list<GLuint> m_vao1;

	int m_modelLoc;
	int m_viewLoc;
	int m_projectionLoc;
};