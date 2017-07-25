#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>

// Class for window managment
class window
{
public:
	SDL_Window		*m_window = nullptr;
	SDL_Renderer	*m_renderer = nullptr;
	SDL_Event		m_event;
	SDL_GLContext	m_context;

public:
	window();
	~window();

	void clear_render(SDL_Renderer *ren);

	// Setters
	void set_context(unsigned int major, unsigned int minor);
	void set_resolution(int w, int h);
	void set_title(const char *title);
	
private:
	void init_window();
};

