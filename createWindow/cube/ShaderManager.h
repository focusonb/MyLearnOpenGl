#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class ShaderManager
{
public:
	void setModelMatrix(const glm::mat4& mat);
	void setViewMatrix(const glm::mat4& mat);
	void setProjectionMatrix(const glm::mat4& mat);
	void setUniformVec3(const glm::vec3& vec, const char* uniform);
	void setUniformFloat1(const float& value, const char* uniform);

	const unsigned int getShaderProgramId() const;
private:
	unsigned int m_shaderProgram;
	int m_modelLoc;
	int m_viewLoc;
	int m_projectionLoc;
};

