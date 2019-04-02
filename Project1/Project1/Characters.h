#pragma once
//#include "Includes.h"
#include<iostream>
#include<vector>
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
	virtual void setCharacterX(); 

private: 
	int x, y , graficox , graficoy,player ,speed, timeToSwich , pointToControl; 
	bool up, down, left, right, isIdle; // son para controlar las variables que se usan 

	void hazCalculos(int numero);

protected: 

	//virtual void setVariables(int graphicX, int graphicY);
	


};

