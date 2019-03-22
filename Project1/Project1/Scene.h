#pragma once
//#include"Includes.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();
	virtual void init();
	virtual void reinit(); 
	virtual void render()  {}; 
	virtual void update()  {}; 
	void setReInit(bool loaded = true) { mReinit = loaded; };
	bool mustReInit() { return mReinit; };

protected: 
	
	bool mReinit;
};

