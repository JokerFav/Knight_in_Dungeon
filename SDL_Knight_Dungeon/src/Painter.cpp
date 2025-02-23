#include "Painter.hpp"
using namespace std;

Painter::Painter():window(NULL), renderer(NULL)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		cout << "Init failed due to an error: " << SDL_GetError() << endl;

	window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(window == NULL)
		cout << "Creating window failed: " << SDL_GetError() << endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer == NULL) 
		cout << "Creating renderer failed: " << SDL_GetError() << endl;
}

void Painter::before_draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

SDL_Texture* Painter::load_texture(string path)
{
	SDL_Texture* NewTexture = NULL;
	SDL_Surface* LoadedSurface = IMG_Load(path.c_str());
	if(LoadedSurface == NULL)
		cout << "Loading texture failed: " << IMG_GetError() << endl;
	else
	{
		NewTexture = SDL_CreateTextureFromSurface(renderer, LoadedSurface);
		if(NewTexture == NULL)
			cout << "Creating texture failed: " << SDL_GetError() << endl;
		SDL_FreeSurface(LoadedSurface);
	}
	return NewTexture;
}

void Painter::QuitSDL()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Painter::draw_map(SDL_Rect &tile, SDL_Texture* &MapTexture)
{
	Painter::before_draw();
	SDL_RenderCopy(renderer, MapTexture, &tile, NULL);
	SDL_RenderPresent(renderer);
	SDL_Delay(110);
}