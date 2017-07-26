#include "window/window.h"
#include "input/input.h"
#include "tests/square.h"

int main(int argc, char *argv[])
{
	window win;

	square::setup();

	// Wireframe
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (true)
	{
		input::handle_input(win);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(square::shader_program);
		glBindVertexArray(square::VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		SDL_GL_SwapWindow(win.m_window); // This handles swapping buffers
	}

	return 0;
}