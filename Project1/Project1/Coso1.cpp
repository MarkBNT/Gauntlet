#include "sdl.h"
#include <iostream>

#define RECT_WIDTH 5
#define RECT_HEIGHT 5

const int SCREEN_WIDTH = 1800;
const int SCREEN_HEIGHT = 800;

int main(int archc, char* rgs[])
{

	float rojo = 255;
	float verde = 0;
	float azul = 0;

	SDL_Rect Coso1;
	Coso1.x = 0;
	Coso1.y = 0;
	Coso1.w = RECT_WIDTH;
	Coso1.h = RECT_HEIGHT;

	float contador = 0;

	int state = 0;
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	//SDL_Surface *s;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	screenSurface = SDL_GetWindowSurface(window);

	rojo = 0;
	verde = 0;
	azul = 0;
	bool SoloRojo = true;
	bool RojoYVerde = false;

	while (true)
	{
		rojo = rojo + 5;
		if (SoloRojo)
		{
			if (rojo >= 255)
			{
				verde = verde + 5;
				rojo = 0;
			}
			if (verde >= 255)
			{
				azul = azul + 5;
				verde = 0;

			}
			if (verde >= 255)
			{
				verde = 0;
				SoloRojo = false;
				RojoYVerde = true;
			}
		}
		if (RojoYVerde)
		{
			rojo = 0;
			verde = 255;
			if (rojo >= 255)
			{
				azul = azul + 1;
			}
			if (azul >= 255)
			{
				SoloRojo = true;
				RojoYVerde = false;
			}
		}


		switch (state)
		{
		case 0:

			Coso1.x += 5;
			Coso1.y += 5;

			if (Coso1.x + Coso1.w > SCREEN_WIDTH)
			{
				state = 1;
			}
			if (Coso1.y + Coso1.h > SCREEN_HEIGHT)
			{
				state = 2;
			}
			break;
		case 1:
			Coso1.x -= 5;
			Coso1.y += 5;

			if (Coso1.x < 0) {
				state = 0;
			}

			if (Coso1.y + Coso1.h > SCREEN_HEIGHT) {
				state = 3;
			}

			break;

		case 2:
			Coso1.x += 5;
			Coso1.y -= 5;

			if (Coso1.x + Coso1.w > SCREEN_WIDTH) {
				state = 3;
			}

			if (Coso1.y < 0) {
				state = 0;
			}

			break;

		case 3:
			Coso1.x -= 5;
			Coso1.y -= 5;

			if (Coso1.x < 0) {
				state = 2;
			}

			if (Coso1.y < 0) {
				state = 1;
			}

			break;

		default:
			break;
		}


		//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));

		SDL_FillRect(screenSurface, &Coso1, SDL_MapRGB(screenSurface->format, rojo, verde, azul));


		SDL_UpdateWindowSurface(window);


	}
	SDL_DestroyWindow(window);




	SDL_Quit();

	return 0;
}