#pragma once
#include "Scene.h"
#include"Includes.h"

enum ScenesEnum{ INTRO, MAIN, OPCIONES, SAVE_LOAD, INGAME ,GAMEOVER, PLAYERSELECTOR,_LastScene};
#define NUM_SCENES _LastScene
class SceneDirector
{
public:
	~SceneDirector();
	static SceneDirector * getInstance(); 
	
	void init(); 
	void changeScene(ScenesEnum nextScene, bool reinit = true); 
	ScenesEnum getCurrentSceneEnum() {return mCurrentScene; };
	Scene *getCurrentScene() { return mVectorScene[mCurrentScene]; };
	void update(ScenesEnum scene); 
	void render(ScenesEnum scene);

protected: 
	SceneDirector();	
	static SceneDirector * Instancia; 
	std::vector<Scene*> mVectorScene; 
	ScenesEnum mCurrentScene; 
	

};

