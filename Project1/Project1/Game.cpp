#include "Game.h"
TypePlayerControler * Player = TypePlayerControler::getInstance(); 

Game::Game()
{

	Player = 0; 
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
		TypePlayerControler::getInstance()->setPlayer(Player);
		firstRender = false;


		
	}
	if (Player == 0)
	{

		TypePlayerControler::getInstance()->updatePlayer(GERRERO); 
		
	}
	if (Player == 1)
	{

		TypePlayerControler::getInstance()->updatePlayer(VALQUIRIA); 
	}
	if (Player == 2)
	{
		TypePlayerControler::getInstance()->updatePlayer(MAGO);
	}
	if (Player == 3)
	{
		TypePlayerControler::getInstance()->updatePlayer(ELFO);
	}

	
}

void Game::render()
{

	Videos::getInstance()->clearWindow();
	if (Player == 0)
	{

		TypePlayerControler::getInstance()->renderPlayer(GERRERO);
	}
	if (Player == 1)
	{

		TypePlayerControler::getInstance()->renderPlayer(VALQUIRIA);
	}
	if (Player == 2)
	{
		TypePlayerControler::getInstance()->renderPlayer(MAGO);
	}
	if (Player == 3)
	{
		TypePlayerControler::getInstance()->renderPlayer(ELFO);
	}
	
	Videos::getInstance()->update(); 
}
void Game::PrimeraVez()
{
}

