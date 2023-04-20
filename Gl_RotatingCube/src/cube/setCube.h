#pragma once
#include <memory>
#include "GlCubePainter.h"
using std::unique_ptr;
unique_ptr<GlCubePainter> creatCube() {
	auto cubePainter = unique_ptr<GlCubePainter>(new GlCubePainter(WINDOWS_WIDTH, WINDOWS_HEIGHT));
	cubePainter->addOne(PointGl(0, 0), 1000);
	glm::mat4 model(1.0f);
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	cubePainter->setModelMatrix(model);

	glm::mat4 view(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.5f));
	//view = glm::rotate(view, glm::radians(30.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	cubePainter->setViewMatrix(view);

	cubePainter->setProjectionMatrix(glm::perspective(glm::radians(45.0f)
		, 800.0f / 800.0f, 0.1f, 100.0f));

	cubePainter->setUniformFloat1(32.0, "material.shininess");
	cubePainter->setUniformVec3(glm::vec3(0.0, 0.0, 5.0), "light.position");
	cubePainter->setUniformVec3(glm::vec3(0.2, 0.2, 0.2), "light.ambient");
	cubePainter->setUniformVec3(glm::vec3(0.5, 0.5, 0.5), "light.diffuse");
	cubePainter->setUniformVec3(glm::vec3(1.0, 1.0, 1.0), "light.specular");
	return cubePainter;
}