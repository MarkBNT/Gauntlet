#pragma once
#include"Includes.h"

class Inputs
{
public:
	~Inputs();
	static Inputs * getInstance(); 
	void capturaTeclas(); 
	bool meVoy();
	bool up();
	bool down(); 
	void resetTeclas();
	bool space(); 
	void changeRip();
	bool left(); 
	bool right(); 
	bool qKey(); 

	


private:

	void cambiaEstado(int estado, bool cambia);
	std::vector<bool> teclas;
	static Inputs * Instancia;
	Inputs();
	int key;
	

protected:
	bool A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, n1, n2, n3, n4, n5, n6, n7, n8, n9, n0, enter, slash, upKey, RightKey, Leftkey, downKey, ControlKey, ShiftKey, ripKey,SpaceKey;
};

