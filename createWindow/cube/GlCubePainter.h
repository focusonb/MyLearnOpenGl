#pragma once
#include "GlPainter.h"
#include "../ShaderReader/MyShader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
using std::unique_ptr;

class ShaderBuilder;

using GlSize = int;
using PointGl = std::pair<GlSize, GlSize>;

class GlCubePainter : public GlPainter
{
public:
	GlCubePainter(int widthWindow, int heightWindow);
	GlCubePainter(const PointGl& point, int width, int widthWindow, int heightWindow);
	~GlCubePainter() {
		delete m_shaderManager;
	}
	
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
	bool configureShader();

private:
	GLuint m_VAO, m_VBO;
	unsigned int shaderProgram;
	unsigned int m_texture0;
	unsigned int m_texture1;
	int m_widthWindow;
	int m_heightWindow;

	list<GLuint> m_vao;
	list<GLuint> m_vao1;

	ShaderBuilder* m_shaderManager;
	unique_ptr<MyShader> m_myShader;
};