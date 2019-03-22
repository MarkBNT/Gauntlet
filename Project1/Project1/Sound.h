#pragma once
#include "Includes.h"
class Sound
{
private:
	
	Sound();
	static Sound* instancia;
	std::string Carpeta = "Music/";
	std::vector<std::string> Musicfiles;
	std::vector<Mix_Chunk*> sonido; 
	void SetElements();

	

public:

	static Sound* getInstance();
	void loadMusic(int numberOfMusic, int chanel);
	void CloseMusic();
	void stopMusic(int numberOfMusic);
	~Sound();
};

