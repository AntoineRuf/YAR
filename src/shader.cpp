#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "shader.h"
#include <glm/gtc/type_ptr.hpp>


Shader::Shader(std::string vertexShaderFilename, std::string fragmentShaderFilename){
    unsigned int vertexShaderId = createShader(vertexShaderFilename, GL_VERTEX_SHADER);
    unsigned int fragmentShaderId = createShader(fragmentShaderFilename, GL_FRAGMENT_SHADER);
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShaderId);
    glAttachShader(shaderProgram, fragmentShaderId);
    glLinkProgram(shaderProgram);
    programId = shaderProgram;
}

void Shader::use()
{
    glUseProgram(programId);
}

void Shader::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(programId, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(programId, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(programId, name.c_str()), value);
}

void Shader::setVec4Float(const std::string& name, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(programId, name.c_str()), x, y, z, w);
}

void Shader::setVec4Double(const std::string& name, double x, double y, double z, double w)
{
    glUniform4f(glGetUniformLocation(programId, name.c_str()), x, y, z, w);
}

void Shader::setMat4Float(const std::string& name, glm::mat4 mat)
{
    glUniformMatrix4fv(glGetUniformLocation(programId, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

unsigned int Shader::createShader(std::string filename, int shaderType) {
    std::ifstream shaderFile(filename);
    std::stringstream shaderBuffer;
    shaderBuffer << shaderFile.rdbuf();
    const std::string shaderSourceString = shaderBuffer.str();
    const char* shaderSource = shaderSourceString.c_str();
    unsigned int shaderId;
    shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &shaderSource, NULL);
    glCompileShader(shaderId);
    return shaderId;
}