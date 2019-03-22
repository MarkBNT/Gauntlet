#include "sdl.h"
#include <iostream>

int main(int archc, char* rgs[])
{
	
	int lol = 255;
	float contador = 0;
	
		SDL_Window* window = NULL;
		SDL_Surface* screenSurface = NULL;
		//SDL_Surface *s;

		SDL_Init(SDL_INIT_VIDEO);
		window = SDL_CreateWindow("SDL Tutorial",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			1800, 720,
			SDL_WINDOW_SHOWN);
			
	while (true)
	{
		std::cout << lol<<"    "<< contador << std::endl;

		screenSurface = SDL_GetWindowSurface(window);
		lol = (127.5f *sin(contador)) + 127.5f;
		
		contador += 0.05f;

		SDL_FillRect(screenSurface, NULL ,SDL_MapRGB(screenSurface->format,lol,0,0));

		SDL_UpdateWindowSurface(window);

		SDL_Delay(20);
		

	}
		SDL_DestroyWindow(window);

	

		
		SDL_Quit();

	return 0;
}