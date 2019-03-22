#include "SceneDirector.h"

//Scenas en el juego 
#include "intro.h"
#include "MainScene.h"
#include "OptionsScene.h"
#include "Save_Load.h"
#include "Game.h"
#include "GameOver.h"
#include "PlayerSelector.h"
//fin de las scenas del jueo
SceneDirector * SceneDirector::Instancia = NULL; 

SceneDirector::SceneDirector()
{
	init();

}

SceneDirector::~SceneDirector()
{
}

SceneDirector * SceneDirector::getInstance()
{
	if (Instancia == NULL)
	{
		Instancia = new SceneDirector; 
	}
	return Instancia; 
}
void SceneDirector::init()
{
	mVectorScene.resize(NUM_SCENES);
	intro * Entrada = new intro();
	MainScene *InitialScene = new MainScene(); 
	OptionsScene *Opciones = new OptionsScene();
	Save_Load * GuardaCarga = new Save_Load(); 
	Game * Juego = new Game(); 
	GameOver * Muerte = new GameOver(); 
	PlayerSelector * Seleccion = new PlayerSelector(); 
	   	 
	mVectorScene[INTRO] = Entrada;
	mVectorScene[MAIN] = InitialScene;
	mVectorScene[OPCIONES] = Opciones; 
	mVectorScene[SAVE_LOAD] = GuardaCarga; 
	mVectorScene[INGAME] = Juego; 
	mVectorScene[GAMEOVER] = Muerte; 
	mVectorScene[PLAYERSELECTOR] = Seleccion; 

	Entrada->init();
	InitialScene->init();
	Opciones->init(); 
	GuardaCarga->init(); 
	Juego->init(); 
	Muerte->init();
	Seleccion->init();
}

void SceneDirector::changeScene(ScenesEnum nextScene, bool reinit)
{
	mVectorScene[nextScene]->setReInit(reinit); 
	mCurrentScene = nextScene; 
}

void SceneDirector::update(ScenesEnum scene)
{
	mVectorScene[scene]->update(); 
}

void SceneDirector::render(ScenesEnum scene)
{

	mVectorScene[scene]->render(); 

}







