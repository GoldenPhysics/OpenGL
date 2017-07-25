#include "input.h"

void input::handle_input(window &win)
{
	if (SDL_PollEvent(&win.m_event))
	{
		if (win.m_event.type == SDL_QUIT || win.m_event.key.keysym.sym == SDLK_ESCAPE) win.~window();
		else if (win.m_event.type == SDL_KEYDOWN && win.m_event.key.repeat == 0)
		{
			if (win.m_event.key.keysym.sym == SDLK_r)
				win.clear_render(win.m_renderer);
		}
	}
}
