#pragma once
#include <string>
#include <vector>
#include <shader.h>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	std::string type;
};

class Mesh {
public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	Mesh() {}
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures) : vertices{ vertices }, indices{ indices }, textures{ textures } { setupMesh(); };
	void Draw(Shader& shader);
private:
	unsigned int VAO, VBO, EBO;
	void setupMesh();
};


class Model
{
public:
	std::string name;
	Shader associated_shader_program;
	Mesh associated_mesh;
	bool is_visible;
	Model() : name{ "" }, associated_shader_program{ Shader() }, associated_mesh{Mesh()}, is_visible(false) {}
	Model(std::string filepath);
	void setVisible(bool visible) { this->is_visible = visible; }
	void VisibleOn() { this->setVisible(true); }
	void VisibleOff() { this->setVisible(false); }
};

