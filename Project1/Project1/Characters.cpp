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
	isIdle = false; 
	timeToSwich = 3;
	pointToControl = timeToSwich; 
}


Characters::~Characters()
{
}

void Characters::init()
{
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	graficox = 0;
	speed = 6;
	up = false;
	down = false;
	left = false;
	right = false;
	isIdle = false; 
	timeToSwich = 3;
	pointToControl = timeToSwich;


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
		graficoy = 29 + MARGEN;
	}
	else if (Personaje == 2)
	{
		graficoy = 58 + MARGEN;
	} 
	else
	{
		graficoy = 87 + MARGEN;
	}
}

void Characters::setCharacterX()
{
	
	if (up == true)
	{
		if (!isIdle)
		{
			hazCalculos(8);
		}
		else {
			hazCalculos(16);

		}

		if (right == true)
		{
			if (!isIdle)
			{
				hazCalculos(9);
			}
			else {
				hazCalculos(17);

			}
		}
		if (left == true)
		{
			if (!isIdle)
			{
				hazCalculos(15);
			}
			else {
				hazCalculos(23);

			}
		}
	}
	
	else if (down == true)
	{
		if (!isIdle)
		{
			hazCalculos(12);
		}
		else {
			hazCalculos(20);

		}
		if (left == true)
		{
			if (!isIdle)
			{
				hazCalculos(12);
			}
			else {
				hazCalculos(21);

			}
		}
		if (right == true)
		{
			if (!isIdle)
			{
				hazCalculos(11);
			}
			else {
				hazCalculos(19);

			}
		}
	}
	else if (right == true)
	{
		if (!isIdle)
		{
			hazCalculos(10);
		}
		else {
			hazCalculos(18);

		}
	
	}
	else if (left == true)
	{
		if (!isIdle)
		{
			hazCalculos(14);
		}
		else {
			hazCalculos(22);

		}
		
	}

	// situar las posiciones de los players

}

void Characters::hazCalculos(int numero)
{
	graficox = numero * (MARGEN + CUTX);
	if (timeToSwich <=0 )
	{

		if (isIdle)
		{
			isIdle = false;

		}
		else
		{
			isIdle = true;
		}
		timeToSwich = pointToControl;
	}
	timeToSwich -= 1;
	
}




