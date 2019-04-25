#pragma once
#include "mundo.h"
#include <vector>

class Bullet:
	public mundo
{
public:
	Bullet();
	~Bullet();
	void init();
	void update(); 
	void render(); 
	void insertBullets(Bullet disparo); 
	void setposition(int _x, int _y);
	void setTypeOfBullet(int _h, int _w); 
	bool vectBalitas(); 
	void setActive(bool activado);

private:
	std::vector<Bullet * > balas; 
	int x, y, h ,w; 
	bool active; 

};

