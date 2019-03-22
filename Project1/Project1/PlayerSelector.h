#pragma once
#include "Includes.h"
class PlayerSelector :
	public Scene
{
public:
	PlayerSelector();
	~PlayerSelector();
	void init(); 
	void update(); 
	void render(); 
private:
	void gerrero(bool activo);
	void valquiria(bool activo);
	void mago(bool activo);
	void elfo(bool activo);
	bool _G, _V, _M, _E;
	std::vector<bool> PersonajeSeleccionado; 
	void ResetAll();
	
	int _Personaje; 
};

