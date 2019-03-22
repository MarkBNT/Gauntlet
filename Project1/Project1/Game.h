#pragma once
#include "Includes.h"

class Game :
	public Scene
{
public:
	Game();
	~Game();
	void init();
	void update(); 
	void render(); 
	void PrimeraVez(); 
private: 
	bool firstRender; 
	int Player; 
	
};

