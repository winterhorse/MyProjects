#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>

//����һ��������������
class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord) {
		this->pos = pos;
		this->texCoord = texCoord;
	}

	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec2* GetTexCoord() { return &texCoord; }

private:
	glm::vec3 pos;
	glm::vec2 texCoord;
};


//����
class Mesh
{
public:
	Mesh(Vertex* vertices, GLuint numVertices);

	void Draw();

	~Mesh();


private:
	enum{
		POSITION_VB,
		TEXCOORD_VB,
		NUM_BUFFERS
	};
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	GLuint m_drawCount; //��Ҫ���ƶ������
};

