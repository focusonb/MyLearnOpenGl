#pragma once
#include "Myshader.h"
#include "FileManager/FileManagerControler.h"
#include "FIleManager/WFIleTextManager.h"
class ShaderManager {
public:
	ShaderManager() = delete;
	ShaderManager(const char* vertexPath, const char* fragmentPath)
		:m_vertexPath(vertexPath), m_fragmentPath(fragmentPath){
		FileManagerControler fileManagerControler(vertexPath);
		const char* vertexSource = (fileManagerControler.getFileManager())->outPut();
		FileManagerControler fileManagerControler2(fragmentPath);
		const char* fragmentSource = (fileManagerControler2.getFileManager())->outPut();
		m_shader = new MyShader(vertexSource, fragmentSource);
	}
	bool configure() {
		return m_shader->configure();
	}
	unsigned int getShaderProgramId() const {
		return m_shader->getShaderProgram();
	};
	~ShaderManager() {
		delete m_shader;
	}

private:
	MyShader* m_shader;
	const char* m_vertexPath;
	const char* m_fragmentPath;

};

