#include "Characters.h"

#include "Video.h"

Characters::Characters()
{
}


Characters::~Characters()
{
}

void Characters::init()
{
}

void Characters::update()
{
}

void Characters::render()
{
}

void Characters::moove(int _x, int _y, int graphicX, int graphicY)
{
	
	Videos::getInstance()->drawPlayer("./Graphics/entities.png", _x, _y, graphicX, graficoy);


}

//void Characters::setVariables(int graphicX, int graphicY)
//{
//	graficox = graphicX; 
//	graficoy = graphicY; 
//
//}

void Characters::setCharacter(int Personaje)
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




