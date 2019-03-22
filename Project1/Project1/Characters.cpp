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

void Characters::moove(int _x, int _y , int graphicX, int graphicY)
{
	
	Videos::getInstance()->drawPlayer("./Graphics/entities.png", _x, _y, graphicX, graphicY); 


}



