#pragma once

#include "Includes.h"

//! ResourceManager class
/*!
	Handles the load and management of the graphics in the game.
*/

class ResourceManager
{
public:

	static ResourceManager* getInstance();
	~ResourceManager();
	Uint32 getTextureId(const char* path); 	
	void removeTexure(const char * path);
	SDL_Texture * getTextureByID(Uint32 id);

	protected:
	
	ResourceManager();

private:



	static ResourceManager*	pInstance;
	std::map<std::string, Uint32> mIDMap;
	std::vector<SDL_Texture*> _vectorDeTexturas;
	
	Uint32	mFirstFreeSlot;


	float _posX, _posY; 

	SDL_Rect *src;
	SDL_Rect *destination;

	Uint32 addTexture(const char * path);// añade texturas al vector _vectorDeTexturas ;
	Uint32 UpdateFirstFreeSlot();// Actualiza quien es la primera posicion nula del vector_vectorDeTexturas; 
	
	
	
	

	
	
};
