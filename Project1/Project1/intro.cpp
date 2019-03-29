#include "intro.h"



intro::intro()
{
}


intro::~intro()
{
}

void intro::init()
{
	std::cout << "Esta es la Intro del Juego"; 
	Sound::getInstance()->loadMusic(0, 0);
}

void intro::update()
{
}

void intro::render()
{

	Videos::getInstance()->clearWindow();
	Videos::getInstance()->Draw("./Graphics/Gauntlet.png", SCREEN_WIDTH,SCREEN_HEIGHT, 0, 0);
	Videos::getInstance()->Draw("./Graphics/Inicio.png", 600, 40, (SCREEN_WIDTH/ 2) - (SCREEN_WIDTH / 6) , (SCREEN_HEIGHT/2)+ (SCREEN_HEIGHT/ 4));

	if ((Inputs::getInstance()->space() == true))
	{
	
		SceneDirector::getInstance()->changeScene(MAIN);


	}
	Videos::getInstance()->update(); 
}
