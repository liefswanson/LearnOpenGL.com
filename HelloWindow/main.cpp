#include <iostream>
#include <fstream>
#include "shader.hpp"
using namespace std;

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);



// The MAIN function, from here we start our application and run our Program/Game loop
int main(){
    // Init GLFW
    glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr); // Windowed
    glfwMakeContextCurrent(window);

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    // Initialize GLEW to setup the OpenGL Function pointers
    glewExperimental = GL_TRUE;
    glewInit();

    // Define the viewport dimensions
    glViewport(0, 0, 800, 600);

    Shader shaderProgram = Shader("basic.vert", "basic.frag");


    // Set up our vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] = {
       0.5f,  0.5f,	// tr (X,Y)
       0.5f, -0.5f, // tl (X,Y)
	  -0.5f, -0.5f, // bl (X,Y)
      -0.5f,  0.5f  // br (X,Y)
    };

	GLuint indices[] = {
		0, 1, 3
	};

    GLuint VAO, VBO, EBO;
	
	glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

    // Bind our Vertex Array Object first, then bind and set our buffers and pointers.
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);


    // Game loop
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while(!glfwWindowShouldClose(window))
    {
        // Check and call events
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw our first triangle
		shaderProgram.Use();
        glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);


        // Swap the buffers
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
    cout << key << endl;
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
