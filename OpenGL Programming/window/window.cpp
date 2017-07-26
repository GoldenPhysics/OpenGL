#include "window.h"
#include <iostream>

window::window()
{
	set_context(3, 3); // OpenGL 3.3
	init_window();
	set_title("OpenGL");
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
}

void window::set_resolution(int w, int h)
{
	SDL_SetWindowSize(m_window, w, h);
}

void window::set_title(const char *title)
{
	SDL_SetWindowTitle(m_window, title);
}

void window::clear_render(SDL_Renderer *ren)
{
	SDL_SetRenderDrawColor(ren, 240, 240, 240, 255);
	SDL_RenderClear(ren);
}

void window::init_window()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL could not be initialized: %s", SDL_GetError());
	}
	else
	{
		SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_OPENGL, &m_window, &m_renderer);
		
		// Make the context for the window the same that is created in set_context()
		m_context = SDL_GL_CreateContext(m_window);
		if (m_context == nullptr)
			std::cerr << "OpenGL context could not be opened" << std::endl;

		// Set up the GLEW library
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			std::cerr << "GLEW could not be initialized" << std::endl;
	}
}
