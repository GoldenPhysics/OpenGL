#pragma once

#include <GL/glew.h>
#include <iostream>
namespace square
{
	int vertex_shader;
	int fragment_shader;
	int shader_program;
	unsigned int VBO, VAO, EBO;

	int success_flag;

	float vertices[] = {
		0.5f, 0.5f, 0.0f,	// top right
		0.5f, -0.5f, 0.0f,	// bottom right
		-0.5f, -0.5f, 0.0f,	// bottom left
		-0.5f, 0.5f, 0.0f	// top left
	};
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
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

	void draw()
	{
		
	}

	void setup()
	{
		// Vertex Shader
		square::vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(square::vertex_shader, 1, &(square::vertex_shader_source), 0);
		glCompileShader(square::vertex_shader);

		glGetShaderiv(square::vertex_shader, GL_COMPILE_STATUS, &square::success_flag);
		std::cout << "Vert Shader Status: " << square::success_flag << std::endl;

		// Fragment shader
		square::fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(square::shader_program, 1, &(fragment_shader_source), 0);
		glCompileShader(square::shader_program);

		glGetShaderiv(square::shader_program, GL_COMPILE_STATUS, &square::success_flag);
		std::cout << "Frag Shader Status: " << square::success_flag << std::endl;

		// Shader program
		square::shader_program = glCreateProgram();
		glAttachShader(square::shader_program, square::vertex_shader);
		glAttachShader(square::shader_program, square::fragment_shader);
		glLinkProgram(square::shader_program);

		glGetProgramiv(square::shader_program, GL_LINK_STATUS, &square::success_flag);
		std::cout << "Shader Program Status: " << square::success_flag << std::endl;

		// Delete the old shaders after they have been linked into program
		glDeleteShader(square::vertex_shader);
		glDeleteShader(square::fragment_shader);

		glGenVertexArrays(1, &square::VAO);
		glGenBuffers(1, &square::VBO);
		glGenBuffers(1, &square::EBO);

		// Bind square::VAO first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
		glBindVertexArray(square::VAO);

		glBindBuffer(GL_ARRAY_BUFFER, square::VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(square::vertices), square::vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, square::EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(square::indices), square::indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
};

