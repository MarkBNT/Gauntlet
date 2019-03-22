#include "Video.h"

Video* Video::instancia = NULL;




Video::Video() 
{
	
	SDL_Init(SDL_INIT_VIDEO);


}

Video::~Video()
{
}

Video * Video::getInstance()
{
	if (instancia == NULL)
	{
		instancia = new Video();
	}
	return instancia;
}

void Video::createWindow()
{
	
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	LoadContent();
	
	screenSurface = SDL_GetWindowSurface(window);

	
}

int Video::setWidht()
{


	return SCREEN_WIDTH;
}

int Video::setHeight()
{
	return SCREEN_HEIGHT;
}

void Video::update()
{

	//SDL_FillRect(screenSurface, &Coso1, SDL_MapRGB(screenSurface->format, rojo, verde, azul));

	SDL_UpdateWindowSurface(window);

	//SDL_UpdateTexture(Cielo, NULL, , 300);
	
}

void Video::quit()
{

	SDL_DestroyWindow(window);

	SDL_Quit();

}

void Video::Inputs()
{



}

bool Video::LoadContent()
{
	int w = 0, h = 0;
	Cielo = IMG_LoadTexture(renderer, "Cielo.png");
	SDL_QueryTexture(Cielo, NULL, NULL, &w, &h);
	RectCielo.x = 0; RectCielo.y = 0; RectCielo.w = w; RectCielo.h = h;
	



	return 1;
}
