#pragma once

#include <SDL2/SDL.h>

// Class for window managment
class window
{
public:
	SDL_Window		*m_window = nullptr;
	SDL_Renderer	*m_renderer = nullptr;
	SDL_Event		m_event;

public:
	window();

	void set_context(unsigned int major, unsigned int minor);
	void set_resolution(int w, int h);
	void set_title(const char *title);
	void clear_render(SDL_Renderer *ren);

private:
	bool init_window();
};

