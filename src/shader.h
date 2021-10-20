#pragma once
#include <glm/glm.hpp>

#include <string>
class Shader
{
public:
	unsigned int programId;
	Shader() : programId{ 0 } {}
	Shader(std::string vertexShaderFilename, std::string fragmentShaderFilename);
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec4Float(const std::string& name, float x, float y, float z, float w);
	void setVec4Double(const std::string& name, double x, double y, double z, double w);
	void setMat4Float(const std::string& name, glm::mat4 mat);

private:
	unsigned int createShader(std::string filename, int shaderType);
};
