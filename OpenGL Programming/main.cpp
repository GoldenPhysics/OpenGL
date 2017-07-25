#include "window/window.h"
#include "input/input.h"

int main(int argc, char *argv[])
{
	window win;

	// Clear renderer
	SDL_SetRenderDrawColor(win.m_renderer, 240, 240, 240, 255);
	SDL_RenderClear(win.m_renderer);

	while (1)
	{
		input::handle_input(win);
		SDL_GL_SwapWindow(win.m_window); // This handles swapping buffers
	}

	return 0;
}