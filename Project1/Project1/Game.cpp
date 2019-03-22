#include "Game.h"
TypePlayerControler * Player = TypePlayerControler::getInstance(); 

Game::Game()
{
}


Game::~Game()
{
}

void Game::init()
{
	std::cout << "Estamos Jugando" << std::endl;
	firstRender = true; 
}

void Game::update()
{
	if (firstRender == true)
	{
		Player = TypePlayerControler::getInstance()->getPlayer();
	}
	TypePlayerControler::getInstance()->updatePlayer(VALQUIRIA); 
	//std::cout << "Estamos Jugando" << std::endl;
}

void Game::render()
{
	if (firstRender == true)
	{
		 
		Videos::getInstance()->clearWindow();
		Videos::getInstance()->Draw("./Graphics/Sinior.png", 200, 100, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 7);
		firstRender = false; 
		Videos::getInstance()->update(); 
	}
	TypePlayerControler::getInstance()->renderPlayer(VALQUIRIA);
}

