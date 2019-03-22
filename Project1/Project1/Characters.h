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
	virtual void moove(int _x, int _y, int graphicX, int graphicY);
	virtual void setCharacter(int Personaje); 

private: 
	int x, y , graficox , graficoy; 

protected: 

	//virtual void setVariables(int graphicX, int graphicY);
	


};

