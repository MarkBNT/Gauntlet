#pragma once
#include"Includes.h"

class Videos
{
private:
	Videos();
	static Videos* instancia;
	std::string Path;
	std::vector<std::string> FileName; 
	std::string extension;
	SDL_Window* window;
	SDL_Renderer * renderer;
	SDL_Rect *destination;
	SDL_Rect * src;
	void setImages(); // cargara todas las imagenes 

public:
	~Videos();
	
	SDL_Window* SetWindow();

	SDL_Renderer* SerRender(); 
	void clearWindow(); 

	static Videos * getInstance();

	void init();


	void update();

	void render();

	void drawPlayer(const char * path, int x, int y, int _posX, int _posY); 
	void getImages();
	void quit();
	void Draw(const char * path, int x, int y, int h, int w);




};

