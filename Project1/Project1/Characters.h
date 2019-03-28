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
	virtual void moove();
	virtual void setCharacterY(int Personaje); 

private: 
	int x, y , graficox , graficoy,player ,speed; 
	bool up, down, left, right; // son para controlar las variables que se usan 

protected: 

	//virtual void setVariables(int graphicX, int graphicY);
	


};

