#include "ResourceManager.h"
Videos *Video = Videos::getInstance();
ResourceManager* ResourceManager::pInstance = NULL;

ResourceManager::~ResourceManager()
{
	
}
ResourceManager::ResourceManager()
{
	

}



ResourceManager * ResourceManager::getInstance()
{

	if (pInstance == NULL)
	{
		pInstance = new ResourceManager();
	}
	return pInstance;
}

Uint32 ResourceManager::UpdateFirstFreeSlot() 
{

	for (int i = 0; i < _vectorDeTexturas.size(); i++)
	{
		if (_vectorDeTexturas[i] == NULL)
		{
			mFirstFreeSlot = i; 
			return mFirstFreeSlot;
		}
	}
	return mFirstFreeSlot; 
}
Uint32 ResourceManager::addTexture(const char* path)
{
	

	SDL_Texture* texturaCargada = IMG_LoadTexture(Video->SerRender(), path);
	if (mFirstFreeSlot < _vectorDeTexturas.size())
	{
		Uint32 id = mFirstFreeSlot; 
		mFirstFreeSlot = static_cast< Uint32>(_vectorDeTexturas.size());
		_vectorDeTexturas[id] = texturaCargada; 
		return id; 
	}
	else
	{
		_vectorDeTexturas.push_back(texturaCargada); 
		mFirstFreeSlot = static_cast<Uint32>(_vectorDeTexturas.size());

		return  mFirstFreeSlot - 1; 
	}

}

Uint32 ResourceManager::getTextureId(const char * path)
{
	Uint32 id;
	std::map<std::string, Uint32>::iterator iterador = mIDMap.find(path);
	if (iterador == mIDMap.end())//si llega al final lo que buscamo no esta en el map; 
	{
		id = addTexture(path);
		mIDMap[path] = id;
	std::cout << "Cargando : " << path << "\n"; 
	}
	return mIDMap[path];
}

SDL_Texture * ResourceManager::getTextureByID(Uint32 id)
{
	return _vectorDeTexturas[id];
}


void ResourceManager::removeTexure(const char * path)
{
	std::map<std::string, Uint32>::iterator iterador = mIDMap.find(path); 
	if (iterador == mIDMap.end())
	{
		std::cout << "The file doesn't exist" << "\n" << std::endl;
	}
	else
	{
		_vectorDeTexturas[iterador->second];
		mIDMap.erase(path);
		UpdateFirstFreeSlot();
	}
}


