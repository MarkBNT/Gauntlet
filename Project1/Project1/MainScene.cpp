#include "MainScene.h"

// =  Videos::getInstance(); 

MainScene::MainScene()
{

	
}


MainScene::~MainScene()
{
}

void MainScene::init()
{
	_UpDown = 0; 
	fTime = true; 
	std::cout << "Hello"<< std::endl; 
	whereIm.resize(3); 
	whereIm[0] = true; 
}
void MainScene::update()
{
	if (Inputs::getInstance()->down() == true)
	{
		_UpDown++; 
		if (_UpDown == 3)
		{
			_UpDown = 0;
		}
		if (_UpDown == 2)
		{
			whereIm[0] = false;
			whereIm[1] = false;
			whereIm[2] = true;
			
		}if (_UpDown == 1)
		{
			whereIm[0] = false;
			whereIm[1] = true;
			whereIm[2] = false;
			
		}
		if (_UpDown == 0)
		{
			whereIm[0] = true;
			whereIm[1] = false; 
			whereIm[2] = false; 
		
		}
	}
	if (Inputs::getInstance()->up() == true)
	{
		_UpDown--;
		if (_UpDown == -1)
		{
			_UpDown = 2;
		}
		if (_UpDown == 2)
		{
			whereIm[0] = false;
			whereIm[1] = false;
			whereIm[2] = true;

		}if (_UpDown == 1)
		{
			whereIm[0] = false;
			whereIm[1] = true;
			whereIm[2] = false;

		}
		if (_UpDown == 0)
		{
			whereIm[0] = true;
			whereIm[1] = false;
			whereIm[2] = false;

		}

	}

	if ((Inputs::getInstance()->space() == true) && (_UpDown == 2))
	{
		Videos::getInstance()->quit();
	}
	if ((Inputs::getInstance()->space() == true) && (_UpDown == 0))
	{

		SceneDirector::getInstance()->changeScene(PLAYERSELECTOR);
		
	}
	if (Inputs::getInstance()->qKey() == true)
	{
		SceneDirector::getInstance()->changeScene(INTRO);
	}
	

	
	
}

void MainScene::render()
{
	Videos::getInstance()->clearWindow();
	
	play(whereIm[0]);
	resume(whereIm[1]);
	exit(whereIm[2]);
	Videos::getInstance()->update(); 
}

void MainScene::play(bool activo)
{
	if (activo == true)
	{
		Videos::getInstance()->Draw("./Graphics/SPlay.png", 200, 100, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 7);

	}
	else
	{

		Videos::getInstance()->Draw("./Graphics/Play.png", 200, 100, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 7);

	}

}

void MainScene::resume(bool activo)
{
	if (activo == true)
	{

		Videos::getInstance()->Draw("./Graphics/SResume.png", 200, 100, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4);

	}
	else
	{

		Videos::getInstance()->Draw("./Graphics/Resume.png", 200, 100, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4);

	}


}


void MainScene::exit(bool activo)
{
	if (activo == true)
	{

		Videos::getInstance()->Draw("./Graphics/SExit.png", 200, 100, SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2));
	}
	else
	{

		Videos::getInstance()->Draw("./Graphics/Exit.png", 200, 100, SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2));
		
	}
}



