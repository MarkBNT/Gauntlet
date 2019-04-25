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

private:
	std::vector<Bullet * > balas; 
	int x, y; 

};

