#include "Bullet.h"
#include "Videos.h"
#include "Defines.h"
#include "Defines.h"

Bullet::Bullet()
{

	active = false;
	timing = 5;

}


Bullet::~Bullet()
{
}

void Bullet::init()
{
	active = false;
}

void Bullet::update()
{
}

void Bullet::render()
{
	Videos::getInstance()->drawPlayer("./Graphics/entities.png",x,y,h,w);
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



void Bullet::setDirectionOfBullet(int direction)
{
	directionOfBullet = direction; 
}

void Bullet::movimientosDelArma()
{
	if (timing <= 0)
	{
		
		if (directionOfBullet == 1)
		{
			y--;
				
		}
		else if (directionOfBullet == 2)
		{
			y++;

		}
		else if (directionOfBullet == 20)
		{
			x++;
		}
		else if (directionOfBullet == 10)
		{
			x--;
		}
		else if (directionOfBullet == 11)
		{
			x--;
			y--;
		}
		else if (directionOfBullet == 12)
		{
			x--;
			y++;
		}
		else if (directionOfBullet == 22)
		{
			x++;
			y++;
		}
		else if (directionOfBullet == 21)
		{
			x++;
			y--;
		}
		else {
			active = false; 
		}
		timing = 5;
	}
	timing--;

	if (x < 0)
	{
		active = false;
	}
	if (x > SCREEN_WIDTH)
	{
		active = false; 
	}
	if (y < 0)
	{
		active = false;
	}
	if (y > SCREEN_HEIGHT)
	{
		active = false;
	}
}




