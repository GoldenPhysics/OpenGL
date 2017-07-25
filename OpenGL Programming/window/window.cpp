#include "window.h"

window::window()
{
	this->init_window();
}

void window::set_context(unsigned int major, unsigned int minor)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
}

void window::set_resolution(int w, int h)
{
	SDL_SetWindowSize(this->m_window, w, h);
}

void window::set_title(const char *title)
{
	SDL_SetWindowTitle(this->m_window, title);
}

void window::clear_render(SDL_Renderer *ren)
{
	SDL_SetRenderDrawColor(ren, 240, 240, 240, 255);
	SDL_RenderClear(ren);
}

bool window::init_window()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL could not be initialized: %s", SDL_GetError());
		return false;
	}
	else
	{
		SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN, &this->m_window, &this->m_renderer);
		return true;
	}
}
