#include <stdio.h>
#include "window/window.h"
#include "input/input.h"

int main(int argc, char *argv[])
{
	window win;

	while (true)
	{
		input::handle_input(win);
		SDL_GL_SwapWindow(win.m_window); // This handles swapping buffers
	}

	return 0;
}