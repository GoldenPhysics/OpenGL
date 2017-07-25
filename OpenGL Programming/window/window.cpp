#include "window.h"

window::window()
{
	this->set_context(3, 2); // OpenGL 3.2
	this->init_window();
	this->set_title("OpenGL");
}

window::~window()
{
	SDL_GL_DeleteContext(m_context);
	SDL_Quit();
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
		SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL, &this->m_window, &this->m_renderer);
		
		// Make the context for the window the same that is created in set_context()
		this->m_context = SDL_GL_CreateContext(this->m_window);

		return true;
	}
}
