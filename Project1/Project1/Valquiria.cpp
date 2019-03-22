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
	moove(20,20,20,20); 

}

void Valquiria::render()
{
	Videos::getInstance()->clearWindow(); 

	Videos::getInstance()->update(); 
}
