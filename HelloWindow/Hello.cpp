#include <iostream>
#include <sstream>
#include <fstream>
#include <streambuf>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void
key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

int
main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow( 800, 600, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	glViewport( 0, 0, 800, 600);

	glfwSetKeyCallback(window, key_callback);

	std::ifstream t("basic.vert");
	std::stringstream vertexShaderSource;
	vertexShaderSource << t.rdbuf();
	const GLchar * vertexShaderSourceGLC = vertexShaderSource.str().c_str();
	
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSourceGLC, NULL);
	glCompileShader(vertexShader);
	

	GLfloat vertices[] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.0f, 0.5f
	};
	
	//generate VBO
	GLuint VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		//main part of the update loop
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(window);
	}
	
	glfwTerminate();
	return 0;
}

void
key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
