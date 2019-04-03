#pragma once
//#include "Includes.h"
#include<iostream>
#include<vector>
#include "Bullet.h"
class Characters
{
public:
	Characters();
	virtual ~Characters();
	virtual void init(); 
	virtual void update(); 
	virtual void render(); 
	int getX();
	int getY();	
	int getGY();


private: 
	int x, y , graficox , graficoy,player ,speed, timeToSwich , pointToControl; 
	bool up, down, left, right, isIdle; // son para controlar las variables que se usan 
	virtual void moove();

	virtual void setCharacterX(); 
	void hazCalculos(int numero);
	void Dispara();
	

protected: 

	virtual void setCharacterY(int Personaje); 


	//virtual void setVariables(int graphicX, int graphicY);
	


};

