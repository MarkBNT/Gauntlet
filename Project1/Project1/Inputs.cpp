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
	teclas.push_back(SpaceKey);//5
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

		switch (capt_teclas.type)
		{

		case SDL_KEYDOWN:
				capt_teclas.key.keysym.scancode;

			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				changeRip();
			}

			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_W)
			{
				std::cout << "Has Pulsado W" << std::endl;

				cambiaEstado(0, true);
								
			}

			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_A)
			{
				std::cout << "Has pulsado A" << std::endl;

				cambiaEstado(1, true);
			}

			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_S)
			{
				std::cout << "Has Pulsado S" << std::endl;

				cambiaEstado(2, true);
			}

			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_D)
			{
				std::cout << "Has Pulsado D" << std::endl;

				cambiaEstado(3, true);
			}	

			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_I)
			{
				std::cout << "Estas pulsando I" << std::endl; 

				cambiaEstado(4, true);
			}

			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_SPACE)
			{
				std::cout << "Estas pulsando Space" << std::endl;

				cambiaEstado(5, true);
			}

			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_R)
			{
				std::cout << "Estas pulsando R" << "\n";

				cambiaEstado(6, true);
			}			
			
			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_P)
			{
				

			}
			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_DOWN)
			{
				cambiaEstado(7, true); 
			}
			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_UP)
			{
				cambiaEstado(8, true); 
			}
			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_SPACE)
			{
				cambiaEstado(9, true);
				//ripKey = true;
			}
			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				cambiaEstado(10, true);
			}
			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_LEFT)
			{
				cambiaEstado(11, true); 
			}
			if (capt_teclas.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				cambiaEstado(12, true); 
			}

		break;
			   	

		case SDL_QUIT:
						
			ripKey = true;

		break;
		}

	}

}

void Inputs::cambiaEstado(int estado , bool cambia)
{
	bool exit = false;
	int i = 0;
	while (exit == false)
	{
		if (estado == i)
		{
			teclas[i] = cambia;
			exit = true;
			
		}
		
		i+=1;
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
