#include <iostream>

#include "window/window.h"
#include "input/input.h"

int main(int argc, char *argv[])
{
	window win;

	while (true)
	{
		input::handle_input(win);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		SDL_GL_SwapWindow(win.m_window); // This handles swapping buffers
	}

	return 0;
}