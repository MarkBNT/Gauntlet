#pragma once
#include "Includes.h"

class Video
{
private: 
	Video();
	static Video* instancia;
	SDL_Window *window = NULL;
	SDL_Surface* screenSurface = NULL;
	
	
	SDL_Rect Coso1;
	
	//juego 
	SDL_Event Event;
	SDL_Renderer *renderer;
	SDL_Texture *Cielo;
	SDL_Rect Personaje, RectCielo;

	//fjuego

	float rojo;
	float verde;
	float azul;
	

public:
	~Video();

	static Video *getInstance();

	void createWindow();

	int setWidht();

	int setHeight();

	void update();

	void quit();

	void Inputs();

	bool LoadContent();



};

