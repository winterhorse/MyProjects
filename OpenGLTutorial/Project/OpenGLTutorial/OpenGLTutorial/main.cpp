
#include <GL/glew.h>
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

#define SCR_WIDTH  800
#define SCR_HEIGHT 600

int main(int argc, char** argv){

	Display display(800, 600, "OpenGLTutorial");
	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3( 0.0f,  0.5f, 0.0f), glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec2(1.0, 0.0))
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	Shader shader("basicShader");
	Texture texture("wall.jpg");

	Transform transform;

	Camera camera(glm::vec3(0.0, 0.0, -2.0), glm::radians(90.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.01f, 1000.0f);

	float counter = 0.0f;

	while (!display.IsClosed()){
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		float sinCounter = sinf(counter);

		transform.GetPos()->x = sinCounter;
		transform.GetPos()->z = sinCounter;
		//transform.GetScale()->y = sinCounter;
		//transform.GetScale()->z = sinCounter;

		//transform.GetRot()->x = sinCounter*10;
		//transform.GetRot()->y = sinCounter * 10;

		shader.Bind();		
		texture.Bind();

		shader.Update(transform, camera);

		mesh.Draw();

		display.Update();

		counter += 0.001f;
	}

	return 0;
}