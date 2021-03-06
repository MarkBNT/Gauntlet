#include "Characters.h"

//#include "Videos.h"
#include "Inputs.h"
#include "Defines.h"




Characters::Characters()
{
	firstTime = true; 
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT/2; 
	graficoy = 0;
	graficox = 0; 
	armaX = 0;
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
	graficoy = 0;
	graficox = 0;
	armaX = 0;
	speed = 6;
	up = false;
	down = false;
	left = false;
	right = false;
	isIdle = false; 
	timeToSwich = 3;
	pointToControl = timeToSwich;
	direct = 0; 
	balitas.resize(0);
	

}

void Characters::update()
{

	   	 
	if ((Inputs::getInstance()->wKey() == true) || (Inputs::getInstance()->up() == true))
	{
		y-= speed; 
		direct += 1;
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
		direct += 2;
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
		direct += 10;
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
		direct += 20;
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
	if (Inputs::getInstance()->space() == true)
	{

		/*Dispara();*/ 
		iShoot = true;
		
		for (int i = 0; i < balitas.size(); i++)
		{
			if (balitas[i]->vectBalitas() == false)
			{
				CalculosDeArma();
				balitas[i]->setActive(true);
				balitas[i]->setposition(x, y);
				balitas[i]->setTypeOfBullet(armaX, graficoy);
				balitas[i]->setDirectionOfBullet(direct);
				//std::cout << balitas[i];
				std::cout << "Bala" << i << std::endl;
				pasado = true; 
				std::cout << "He disparado en posicion = " << x << " , " << y << " , " << graficox << " , " << graficoy << "\n "   ;
			}
			if (pasado == true)
			{
				break; 
			}
		}
		pasado = false; 
	}
	setCharacterX();
	
	player = TypePlayerControler::getInstance()->getPlayer();
}

void Characters::render()
{
	setCharacterY(player);
	
	moove();
	iShoot = false; 
	direct = 0;
}



void Characters::moove()
{
	for (int i = 0; i < balitas.size(); i++)
	{
		if (balitas[i]->vectBalitas() == true)
		{
			balitas[i]->movimientosDelArma();
			balitas[i]->render();
		}
	}
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
		graficoy = 32 + (MARGEN*2);
	}
	else if (Personaje == 2)
	{
		graficoy = 64 + (MARGEN*4);
	} 
	else
	{
		graficoy = 96 + (MARGEN*8);
	}
	if (firstTime)
	{
		int numero = 25 * (MARGEN + CUTX);
		for (int i = 0; i < 25; i++)
		{
			Bullet *bala = new Bullet();
			bala->setTypeOfBullet(numero, graficoy);
			balitas.push_back(bala);
			
			
		}	
		firstTime = false; 
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

void Characters::CalculosDeArma()
{
	armaX = 24 * (MARGEN + CUTX);
}

int Characters::getX()
{
	return x;
}

int Characters::getY()
{
	return y;
}

int Characters::getGY()
{
	return graficoy;
}
void Characters::Dispara()
{
	

}



/*	if (up == true)
	{
		std::cout << "Dispara arma up \n"; 
		if (left == true)
		{
		std::cout << "Dispara arma horizontal left up \n"; 

		}
		if (right == true)
		{

		std::cout << "Dispara arma horizontal right up \n"; 
		}
	}
	if (down == true)
	{
		std::cout << "Disparo Abajo \n";
		if (left == true)
		{
			std::cout << "Dispara arma horizontal left down \n";

		}
		if (right == true)
		{

			std::cout << "Dispara arma horizontal right down \n";
		}
	}
	if (left==true)
	{
		std::cout << "Disparo izquierda \n";

	}
	if (right == true)
	{
		std::cout << "Disparo a la derecha \n"; 
	}

	////crear una clase de bullet para poder disparar bien y no se puto buguee 

	*/

