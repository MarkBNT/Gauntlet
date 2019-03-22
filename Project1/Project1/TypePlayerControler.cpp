#include "TypePlayerControler.h"
//Players
#include "Gerrero.h"
#include "Elfo.h"
#include "Mago.h"
#include "Valquiria.h"
//FPlayers

TypePlayerControler * TypePlayerControler::Instancia = NULL; 

void TypePlayerControler::changePlayer(PlayerEnum playerType, bool reinit)
{

}

TypePlayerControler::TypePlayerControler()
{
	init(); 
}

int TypePlayerControler::getPlayer()
{
	return player;
}


TypePlayerControler::~TypePlayerControler()
{
}

TypePlayerControler * TypePlayerControler::getInstance()
{
	if (Instancia == NULL)
	{
		Instancia = new TypePlayerControler(); 
	}
	return Instancia;
}

void TypePlayerControler::setPlayer(int plyer)
{

	player = plyer; 
}

void TypePlayerControler::init()
{
	mVectorPlayer.resize(NUM_PLAYERS); 
	Gerrero * FirstCharacter = new Gerrero(); 
	Valquiria * SecondPlayer = new Valquiria(); 
	Mago * ThirdPlayer = new Mago(); 
	Elfo * LastPlayer = new Elfo(); 

	mVectorPlayer[GERRERO] = FirstCharacter; 
	mVectorPlayer[VALQUIRIA] = SecondPlayer; 
	mVectorPlayer[MAGO] = ThirdPlayer; 
	mVectorPlayer[ELFO] = LastPlayer; 

	FirstCharacter->init(); 
	SecondPlayer->init();
	ThirdPlayer->init(); 
	LastPlayer->init(); 



}

void TypePlayerControler::updatePlayer(PlayerEnum player)
{
	mVectorPlayer[player]->update();
}

void TypePlayerControler::renderPlayer(PlayerEnum player)
{
	mVectorPlayer[player]->render(); 
}
