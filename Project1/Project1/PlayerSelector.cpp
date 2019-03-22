#include "PlayerSelector.h"



PlayerSelector::PlayerSelector()
{
}


PlayerSelector::~PlayerSelector()
{
}

void PlayerSelector::init()
{
	std::cout << "Los personajes han sido inicializados \n";
	PersonajeSeleccionado.resize(4);
	_Personaje = 0;
	PersonajeSeleccionado[0] = true;
	
	 
	 
}

void PlayerSelector::update()
{
		if (_Personaje == 0)
		{
			PersonajeSeleccionado[0] = true; 
			PersonajeSeleccionado[1] = false; 
			PersonajeSeleccionado[2] = false; 
			PersonajeSeleccionado[3] =	false; 
		}
	
		if (Inputs::getInstance()->right() == true)
		{
			_Personaje++;
			if (_Personaje == 4)
			{
				_Personaje = 0;
			}
			if (_Personaje == 1)
			{
				PersonajeSeleccionado[0] = false;
				PersonajeSeleccionado[1] = true;
				PersonajeSeleccionado[2] = false;
				PersonajeSeleccionado[3] = false;
			}
			if (_Personaje == 2)
			{
				PersonajeSeleccionado[0] = false;
				PersonajeSeleccionado[1] = false;
				PersonajeSeleccionado[2] = true;
				PersonajeSeleccionado[3] = false;
			}
			if (_Personaje == 3)
			{
				PersonajeSeleccionado[0] = false;
				PersonajeSeleccionado[1] = false;
				PersonajeSeleccionado[2] = false;
				PersonajeSeleccionado[3] = true;
			}
		}

		if (Inputs::getInstance()->left() == true)
		{
			_Personaje--;
			if (_Personaje == -1)				{
				_Personaje = 3;
			}
			if (_Personaje == 1)
			{
				PersonajeSeleccionado[0] = false;
				PersonajeSeleccionado[1] = true;
				PersonajeSeleccionado[2] = false;
				PersonajeSeleccionado[3] = false;
			}
			if (_Personaje == 2)
			{
				PersonajeSeleccionado[0] = false;
				PersonajeSeleccionado[1] = false;
				PersonajeSeleccionado[2] = true;
				PersonajeSeleccionado[3] = false;
			}
			if (_Personaje == 3)
			{
				PersonajeSeleccionado[0] = false;
				PersonajeSeleccionado[1] = false;
				PersonajeSeleccionado[2] = false;
				PersonajeSeleccionado[3] = true;
			}
		}

	if ((Inputs::getInstance()->space() == true))
	{
		TypePlayerControler::getInstance()->setPlayer(_Personaje);
		Sound::getInstance()->stopMusic(-1); 
		
		SceneDirector::getInstance()->changeScene(INGAME);


	}
	if (Inputs::getInstance()->qKey() == true)
	{
		SceneDirector::getInstance()->changeScene(MAIN);

	}

}





void PlayerSelector::render()
{
	Videos::getInstance()->clearWindow(); 

	gerrero(PersonajeSeleccionado[0]);
	valquiria(PersonajeSeleccionado[1]); 
	mago(PersonajeSeleccionado[2]);
	elfo(PersonajeSeleccionado[3]); 

	Videos::getInstance()->update();
}

void PlayerSelector::gerrero(bool activo)
{
	
	Videos::getInstance()->Draw("./Graphics/Gerrero.png", 200, 300, (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 3), (SCREEN_HEIGHT / 2)-(SCREEN_HEIGHT/ 4 ) );
	if (activo == true)
	{
		Videos::getInstance()->Draw("./Graphics/CuadroDeSeleccion.png",200,300,(SCREEN_WIDTH / 2)- (SCREEN_WIDTH / 3) , (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4));
		 
	}
	else 
	{
		Videos::getInstance()->Draw("./Graphics/CuadroNoSeleccionado.png", 200,300, (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 3), (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4));
	}

}

void PlayerSelector::valquiria(bool activo)
{
	Videos::getInstance()->Draw("./Graphics/Valquiria.png", 200, 300, (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 6), (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4));
	if (activo == true)
	{
		Videos::getInstance()->Draw("./Graphics/CuadroDeSeleccion.png", 200, 300, (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 6), (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4));

	}
	else
	{
		Videos::getInstance()->Draw("./Graphics/CuadroNoSeleccionado.png", 200, 300, (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 6), (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4));
	}
}

void PlayerSelector::mago(bool activo)
{
	Videos::getInstance()->Draw("./Graphics/Mago.png", 200, 300, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4));
	if (activo == true)
	{
		Videos::getInstance()->Draw("./Graphics/CuadroDeSeleccion.png", 200, 300, (SCREEN_WIDTH / 2) , (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4));

	}
	else
	{
		Videos::getInstance()->Draw("./Graphics/CuadroNoSeleccionado.png", 200, 300, (SCREEN_WIDTH / 2) , (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4));
	}
}

void PlayerSelector::elfo(bool activo)
{
	Videos::getInstance()->Draw("./Graphics/Elfo.png", 200, 300, (SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 6), (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4)); 
	if (activo == true)
	{
		Videos::getInstance()->Draw("./Graphics/CuadroDeSeleccion.png", 200, 300, (SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 6), (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4));

	}
	else
	{
		Videos::getInstance()->Draw("./Graphics/CuadroNoSeleccionado.png", 200, 300, (SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 6), (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4));
	}
}

