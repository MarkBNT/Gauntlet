#pragma once
#include "Characters.h"

class Bullet
{
public:
	Bullet();
	~Bullet();
	void init(); 
	void update();
	void render(); 
private:
	void getVariables();
	int x, y, graficoX, graficoY;
	

};

