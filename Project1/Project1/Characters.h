#pragma once
//#include "Includes.h"
class Characters
{
public:
	Characters();
	virtual ~Characters();
	virtual void init(); 
	virtual void update(); 
	virtual void render(); 
	virtual void moove(int _x, int _y); 

private: 
	int x, y; 


};

