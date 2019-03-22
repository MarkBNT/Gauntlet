#pragma once
#include "Includes.h"

class MainScene :
	public Scene
{
public:

	MainScene();
	~MainScene();
	void init(); 
	void update(); 
	void render();

private: 
	int _UpDown;
	bool fTime; 
	std::string escene; 

	char *Play, *Resume, *Exit;

	void play(bool activo);
	void resume(bool activo);
	void options(bool activo);
	void exit(bool activo); 

	std::vector<bool> whereIm; // indica donde estara el selector ; 

	std::string p, r  ,e;
	
};

