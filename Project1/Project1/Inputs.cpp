#include "Inputs.h"

Inputs * Inputs::Instancia = NULL;


Inputs::Inputs()
{

	ripKey = false;
	
	teclas.push_back(W);//0
	teclas.push_back(A);//1
	teclas.push_back(S);//2
	teclas.push_back(D);//3
	teclas.push_back(I);//4
	teclas.push_back(M);//5
	teclas.push_back(R);//6
	teclas.push_back(downKey);//7
	teclas.push_back(upKey);//8
	teclas.push_back(SpaceKey);//9
	teclas.push_back(RightKey);//10
	teclas.push_back(Leftkey);//11 
	teclas.push_back(Q);//12
	
}


Inputs::~Inputs()
{
}

Inputs * Inputs::getInstance()
{

	if (Instancia == NULL)
	{
		Instancia = new Inputs();
	}

	return Instancia;
}

void Inputs::capturaTeclas()
{
	resetTeclas(); 
	
	SDL_Event capt_teclas; 

	while (SDL_PollEvent(&capt_teclas))
	{

			
			const Uint8 * state = SDL_GetKeyboardState(NULL);
			if (state[SDL_SCANCODE_ESCAPE])
			{
				changeRip();
			}
			if (state[SDL_SCANCODE_SPACE])
			{
				cambiaEstado(9, true);
			}
			if (state[SDL_SCANCODE_W])
			{
				cambiaEstado(0, true);
			}
			if (state[SDL_SCANCODE_A])
			{
				cambiaEstado(1, true);
			}
			if (state[SDL_SCANCODE_S])
			{
				cambiaEstado(2, true);
			}
			if (state[SDL_SCANCODE_D])
			{
				cambiaEstado(3, true);
			}
			if (state[SDL_SCANCODE_DOWN])
			{
				cambiaEstado(7, true);
			}
			if (state[SDL_SCANCODE_UP])
			{
				cambiaEstado(8, true);
			}
			if (state[SDL_SCANCODE_RIGHT])
			{
				cambiaEstado(10, true); 
			}
			if (state[SDL_SCANCODE_LEFT])
			{
				cambiaEstado(11, true);
			}
			if (state[SDL_SCANCODE_Q])
			{
				cambiaEstado(12, true);
			}


		switch (capt_teclas.type)
		{
		case SDL_QUIT:
						
			changeRip();

		break;
		}
	}
	
}

void Inputs::cambiaEstado(int estado , bool cambia)
{
	bool exit = false;
	int i = 0;
	for (int i = 0; i < teclas.size(); i++)
	{
		if (estado == i)
		{
			teclas[i] = cambia;
			//exit = true;

		}
	}
	
}


void Inputs::changeRip()
{

	ripKey = true;

}

bool Inputs::left()
{ 
	//11
	return teclas[11];
}

bool Inputs::right()
{
	//10
	return teclas[10];
}

bool Inputs::qKey()
{
	return teclas[12];
}

bool Inputs::wKey()
{
	return teclas[0];
}

bool Inputs::aKey()
{
	return teclas[1];
}

bool Inputs::sKey()
{
	return teclas[2];
}

bool Inputs::dKey()
{
	return teclas[3];
}


bool Inputs::meVoy()
{
	return ripKey;
}

bool Inputs::down()
{
	return teclas[7];
}

bool Inputs::up() 
{
	return teclas[8];
}

void Inputs::resetTeclas()
{
	for (int i = 0; i < teclas.size(); i++)
	{
		teclas[i] = false; 
	}
}

bool Inputs::space()
{
	return teclas[9];
}
