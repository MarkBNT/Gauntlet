#include "Includes.h"

int main(int archc, char* rgs[])
{

	Inputs *Teclas = Inputs::getInstance();// half  Completed
	Videos *Video = Videos::getInstance();// half completed
	Sound *Sonido = Sound::getInstance();//completed 
	SceneDirector *Escenas = SceneDirector::getInstance();
	
	bool Quit = false;
	bool Hola = false;
	
	Video->init(); 
	
	
	Escenas->changeScene(INTRO); 
	//Escenas->changeScene(PLAYERSELECTOR); 
	
	while (!Quit)
	{
		Teclas->capturaTeclas();
		Escenas->update(Escenas->getCurrentSceneEnum());
		
		
		Escenas->render(Escenas->getCurrentSceneEnum());
		
		
		Quit = Teclas->meVoy();
		
		
		
	}
	Video->quit();

	


	

	return Quit;

}






