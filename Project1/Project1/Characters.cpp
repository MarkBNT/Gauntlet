#include "Characters.h"

//#include "Videos.h"
#include "Inputs.h"
#include "Defines.h"

Characters::Characters()
{
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT/2; 
	graficox = 0; 
	speed = 6;
	up = false; 
	down = false; 
	left = false; 
	right = false;
}


Characters::~Characters()
{
}

void Characters::init()
{
}

void Characters::update()
{

	   	 
	if ((Inputs::getInstance()->wKey() == true) || (Inputs::getInstance()->up() == true))
	{
		y-= speed; 
		if (y < 0)
		{
			y = 0;
		}
		up = true; 
	}
	else
	{
		up = false;
	}
	if ((Inputs::getInstance()->sKey() == true)||(Inputs::getInstance()->down() == true))
	{
		y += speed; 
		if (y >( SCREEN_HEIGHT - CUTY))
		{
			y = SCREEN_HEIGHT - CUTY;
		}
		down = true; 
	}
	else
	{
		down = false;
	}
	if ((Inputs::getInstance()->aKey() == true)||(Inputs::getInstance()->left() == true))
	{ 
		x -= speed;
		if (x < 0)
		{
			x = 0; 
		}
		left = true;

	}
	else
	{
		left = false;
	}
	if ((Inputs::getInstance()->dKey() == true)||(Inputs::getInstance()->right() == true))
	{
		x += speed; 
		if (x > (SCREEN_WIDTH  - CUTX))
		{
			x = SCREEN_WIDTH - CUTX;
		}
		right = true; 
	}
	else
	{
		right = false; 
	}
	setCharacterX();
	
	player = TypePlayerControler::getInstance()->getPlayer();
}

void Characters::render()
{
	setCharacterY(player);
	moove();
}

void Characters::moove()
{
	
	Videos::getInstance()->drawPlayer("./Graphics/entities.png", x, y, graficox, graficoy);


}


void Characters::setCharacterY(int Personaje)
{
	if (Personaje == 0 )
	{
		graficoy = 0; 
	}
	else if (Personaje == 1)
	{
		graficoy = 29;
	}
	else if (Personaje == 2)
	{
		graficoy = 58;
	} 
	else
	{
		graficoy = 87; 
	}
}

void Characters::setCharacterX()
{
	// situar las posiciones de los players

}




