#include "Bullet.h"
#include "Videos.h"
#include "Defines.h"


Bullet::Bullet()
{

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
	Videos::getInstance()->drawPlayer("./Graphics/entities.png", 0, 0, 0, 0);
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




