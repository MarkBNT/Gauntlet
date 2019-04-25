#include "Videos.h"

Videos* Videos::instancia = NULL;
ResourceManager	*Gestor = ResourceManager::getInstance();

Videos::Videos()
{


	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow("Gaunlet the remake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	//Control->getTextureId("./Graphics/");
	//Control->getTextureId("./Graphics/Cielo.png");
}


Videos::~Videos()
{
}

SDL_Window * Videos::SetWindow()
{
	return  window;
}

SDL_Renderer * Videos::SerRender()
{
	return  renderer;
}

void Videos::clearWindow()
{

	SDL_RenderClear(renderer); 
}






Videos * Videos::getInstance()
{
	if (instancia == NULL)
	{
		instancia = new Videos();
	}
	return instancia;
}

void Videos::init()
{

	
	setImages(); 

}
	

void Videos::update()
{
	

	SDL_RenderPresent(renderer);
	
}
void Videos::render()
{
	
}
void Videos::setImages()
{
	Gestor->getTextureId("./Graphics/Gauntlet.png"); 
	Gestor->getTextureId("./Graphics/Inicio.png"); 
	Gestor->getTextureId("./Graphics/SPlay.png"); 
	Gestor->getTextureId("./Graphics/Play.png"); 
	Gestor->getTextureId("./Graphics/SResume.png"); 
	Gestor->getTextureId("./Graphics/Resume.png"); 
	Gestor->getTextureId("./Graphics/SExit.png"); 
	Gestor->getTextureId("./Graphics/Exit.png"); 
	Gestor->getTextureId("./Graphics/Gerrero.png"); 
	Gestor->getTextureId("./Graphics/Valquiria.png"); 
	Gestor->getTextureId("./Graphics/Mago.png"); 
	Gestor->getTextureId("./Graphics/Elfo.png"); 
	Gestor->getTextureId("./Graphics/CuadroDeSeleccion.png"); 
	Gestor->getTextureId("./Graphics/CuadroNoSeleccionado.png"); 
	Gestor->getTextureId("./Graphics/Sinior.png"); 
	Gestor->getTextureId("./Graphics/entities.png"); 


}
void Videos::getImages()
{

}

void Videos::quit()
{
	Inputs::getInstance()->changeRip();
	SDL_DestroyWindow(window);

	
}

void Videos::Draw(const char * path, int w, int h, int x, int y)
{
	//Gestor->DrawIMG(path, x, y, h, w);


	SDL_Rect destination;
	destination.h = h;
	destination.w = w;
	destination.x = x;
	destination.y = y;


	SDL_Texture * LoadedTexure = Gestor->getTextureByID(Gestor->getTextureId(path));
	SDL_RenderCopy(renderer, LoadedTexure, src, &destination);


}

void Videos::drawPlayer(const char * path, int x, int y, int _posX, int _posY)
{
	SDL_Rect destination;
	destination.h = CUTY;
	destination.w = CUTX;
	destination.x = x;
	destination.y = y;

	SDL_Rect Cuter; 
	Cuter.h = CUTY + MARGEN; 
	Cuter.w = CUTX + MARGEN; 
	Cuter.x = _posX; 
	Cuter.y = _posY;

	/*src.x = _posX; 
	src.y = _posY;
	src.h = CUTX;
	src.w = CUTY;*/

	SDL_Texture * LoadedTexure = Gestor->getTextureByID(Gestor->getTextureId(path));
	SDL_RenderCopy(renderer, LoadedTexure, &Cuter, &destination); 

}

