#include "sdl.h"
#include <iostream>

int main(int archc, char* rgs[])
{
	
	float rojo = 255;
	float verde = 0;
	float azul = 0; 

	bool _r, _v, _a;

	_r = false;
	_v = false;
	_a = false;

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


		_r = true;
			
		screenSurface = SDL_GetWindowSurface(window);
	while (true)
	{
		
		std::cout << rojo << "   " << verde << "   " << azul << std::endl;

	


		
		if (_r == true)
		{

			rojo -= 1;
			azul += 1;
			_v = false;
			_a = false;

			if ((rojo <= 0)&&(azul >= 255))
			{
				_a = true;
				_r = false;
				rojo = 0;
				azul = 255;
			}

		}
		if (_a == true) 
		{
			azul -= 1;
			verde += 1;
			_v = false;
			_r = false;
			if ((azul <= 0)&&(verde >= 255))
			{
				_a = false;
				_v = true;
				verde = 255;
				azul = 0;

			}
		}
		if (_v ==true)
		{

			verde -= 1;
			rojo += 1;
			_a = false;
			_r = false;

			if ((verde <= 0)&&(rojo >= 255))
			{

				_r = true;
				_v = false;
				verde = 0;
				rojo = 255;

			}
		}

		SDL_FillRect(screenSurface, NULL ,SDL_MapRGB(screenSurface->format,rojo,verde,azul));

		SDL_UpdateWindowSurface(window);

		SDL_Delay(20);

	}
		SDL_DestroyWindow(window);

	

		
		SDL_Quit();

	return 0;
}