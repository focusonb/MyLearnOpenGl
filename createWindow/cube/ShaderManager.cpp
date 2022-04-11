#include "ShaderManager.h"
#include <glad/glad.h>

void ShaderManager::setModelMatrix(const glm::mat4& mat)
{
	glUniformMatrix4fv(m_modelLoc, 1, GL_FALSE, glm::value_ptr(mat));
}

void ShaderManager::setViewMatrix(const glm::mat4& mat)
{
	glUniformMatrix4fv(m_viewLoc, 1, GL_FALSE, glm::value_ptr(mat));
}

void ShaderManager::setProjectionMatrix(const glm::mat4& mat)
{
	glUniformMatrix4fv(m_projectionLoc, 1, GL_FALSE, glm::value_ptr(mat));
}

void ShaderManager::setUniformVec3(const glm::vec3 & vec, const char * uniform)
{
	int uniformId = glGetUniformLocation(m_shaderProgram, uniform);
	glUniform3fv(uniformId, 1, &vec[0]);
}

void ShaderManager::setUniformFloat1(const float & value, const char * uniform)
{
	int uniformId = glGetUniformLocation(m_shaderProgram, uniform);
	glUniform1fv(uniformId, 1, &value);
}

const unsigned int ShaderManager::getShaderProgramId() const
{
	return m_shaderProgram;
}
