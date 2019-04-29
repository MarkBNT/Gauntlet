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
	void setposition(int _x, int _y);
	void setTypeOfBullet(int _h, int _w); 
	bool vectBalitas(); 
	void setActive(bool activado);
	
	void setDirectionOfBullet(int direction); 
	void movimientosDelArma(); 

private:
	int x, y, h ,w ,directionOfBullet, timing;
	bool active , up, down , left ,right; 


};

