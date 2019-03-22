#include "Sound.h"

Sound* Sound::instancia = NULL;

Sound::Sound()
{
	
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_AllocateChannels(128);
	SetElements();
	
	
}


void Sound::SetElements()
{
	sonido.push_back(Mix_LoadWAV("./Music/Gauntlet_Intro.wav")); 
	/*sonido.push_back(Mix_LoadWAV("./Music/victory.wav"));
	sonido.push_back(Mix_LoadWAV("./Music/death.wav"));
	sonido.push_back(Mix_LoadWAV("./Music/gameover.wav"));
	sonido.push_back(Mix_LoadWAV("./Music/Monster-Snoring.wav"));
	sonido.push_back(Mix_LoadWAV("./Music/shock-wall.wav"));
	sonido.push_back(Mix_LoadWAV("./Music/step-human.wav"));
	sonido.push_back(Mix_LoadWAV("./Music/step-monster.wav"));
	sonido.push_back(Mix_LoadWAV("./Music/waterfall.wav"));*/
}

Sound * Sound::getInstance()
{
	if (instancia == NULL)
	{
		instancia = new Sound();
	}
	return instancia;
}

void Sound::loadMusic(int numberOfMusic,int chanel)
{
	
	for (int i = 0; i < sonido.size(); i++)
	{
		
		
		if (numberOfMusic == i)
		{
			
			Mix_PlayChannel(chanel, sonido[i], 0);
			
		}


	}
	

}

void Sound::CloseMusic()
{
	Mix_CloseAudio();
}

void Sound::stopMusic(int numberOfMusic)
{
	Mix_HaltChannel(numberOfMusic); 
}

Sound::~Sound()
{
}
