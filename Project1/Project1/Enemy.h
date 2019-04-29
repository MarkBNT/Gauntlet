#pragma once
#include "mundo.h"
class Enemy :
	public mundo
{
public:
	Enemy();
	~Enemy();
	void init(); 
	void update(); 
	void render(); 
	void typeEnemy(); 


private: 
	int _x, _y, _w, _h; 
	int playerx, playery; 

	
};

