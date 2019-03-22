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

void Characters::moove(int _x, int _y)
{
	
	Videos::getInstance()->drawPlayer("./Graphics/entities.png", _x, _y, 0, 0); 


}



