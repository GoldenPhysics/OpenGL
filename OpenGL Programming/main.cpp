#include <iostream>

#include "window/window.h"
#include "input/input.h"

float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f,  0.5f, 0.0f
};

const char *vertex_shader_source = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char *fragment_shader_source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

int main(int argc, char *argv[])
{
	window win;

	// build and compile shaders
	unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_shader_source, nullptr);
	glCompileShader(vertex_shader);

	int success; // Flag variable for testing status
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	std::cout << "Vertex Shader Status: " << success << std::endl;

	unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_shader_source, nullptr);
	glCompileShader(fragment_shader);

	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	std::cout << "Fragment Shader Status: " << success << std::endl;

	// Linking the damn things
	unsigned int shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	std::cout << "Shader Program Status: " << success << std::endl;

	// Use the program and clean up after ourselves
	glDeleteShader(vertex_shader | fragment_shader);
	glUseProgram(shader_program);


	while (true)
	{
		input::handle_input(win);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		SDL_GL_SwapWindow(win.m_window); // This handles swapping buffers
	}

	return 0;
}