#pragma once
//#include "Includes.h"
#include "mundo.h"
#include<iostream>
#include<vector>
#include "Bullet.h"

class Characters:
	public mundo
{
public:
	Characters();
	~Characters();
	void init(); 
	void update(); 
	void render(); 
	int getX();
	int getY();	
	int getGY();
	void setCharacterX(); 
	void setCharacterY(int Personaje); 


private: 
	//variables
	int x, y , graficox , graficoy,player ,speed, timeToSwich , pointToControl , armaX , direct; 
	bool up, down, left, right, isIdle ,iShoot , firstTime, pasado; // son para controlar las variables que se usan 
	virtual void moove();
	std::vector<Bullet*> balitas;
	//fvariables; 
	void hazCalculos(int numero);
	void CalculosDeArma();
	void Dispara();
	

protected: 



	//virtual void setVariables(int graphicX, int graphicY);
	


};

