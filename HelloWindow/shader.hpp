#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader {

public:
	GLuint Program;

	Shader(const GLchar* vertexPath,
		   const GLchar* fragmentPath);

	void Use();
};
#endif	// __SHADER_H_INCLUDED__
