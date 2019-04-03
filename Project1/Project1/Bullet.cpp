#include "Bullet.h"
Characters * personaje = new Characters();


Bullet::Bullet()
{
	
}


Bullet::~Bullet()
{
}

void Bullet::init()
{
	x = 0; 
	y = 0; 
	graficoX = 0; 
	graficoY = 0; 
	
}

void Bullet::update()
{
	graficoY = personaje->getGY();
	x = personaje->getX();
	y = personaje->getY();
}

void Bullet::render()
{
}
