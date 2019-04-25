#include "Bullet.h"
#include "Videos.h"
#include "Defines.h"


Bullet::Bullet()
{
	active = false;

}


Bullet::~Bullet()
{
}

void Bullet::init()
{

}

void Bullet::update()
{
}

void Bullet::render()
{
	Videos::getInstance()->drawPlayer("./Graphics/entities.png",x,y,h,w);
}

void Bullet::insertBullets(Bullet disparo)
{
	balas.push_back(&disparo);
}

void Bullet::setposition(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Bullet::setTypeOfBullet(int _h, int _w)
{
	h = _h;
	w = _w; 
}

bool Bullet::vectBalitas()
{
	return active;
}

void Bullet::setActive(bool activado)
{
	active = activado;
}




