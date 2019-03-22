#include "Valquiria.h"



Valquiria::Valquiria()
{
}


Valquiria::~Valquiria()
{
}

void Valquiria::init()
{
	std::cout << "Soy una valquiria \n"; 
}

void Valquiria::update()
{

}

void Valquiria::render()
{
	Videos::getInstance()->clearWindow(); 

	moove(20,20,0,0); 

	Videos::getInstance()->update(); 
}
