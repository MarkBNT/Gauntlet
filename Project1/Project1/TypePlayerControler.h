#pragma once
#include "Characters.h"
#include "Includes.h"

enum PlayerEnum { GERRERO, VALQUIRIA, MAGO, ELFO, _lastPlayer };
#define NUM_PLAYERS _lastPlayer

class TypePlayerControler :
	public mundo
{
public:
	~TypePlayerControler();
	static TypePlayerControler* getInstance(); 
	void setPlayer(int plyer); 
	void init(); 
	
	void updatePlayer(PlayerEnum player); 
	void renderPlayer(PlayerEnum player); 
	PlayerEnum getCurrentPlayerEnum() { return mCurrentPlayer; }; 
	Characters *getCurrentPlayer() { return mVectorPlayer[mCurrentPlayer]; }; 
	int getPlayer(); 
	
protected: 
	void changePlayer(PlayerEnum playerType, bool reinit = true); 
	TypePlayerControler();
	static TypePlayerControler * Instancia; 
	PlayerEnum mCurrentPlayer; 
	std::vector<Characters*> mVectorPlayer; 
	int player; 

};

