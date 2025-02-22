#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 512 / 2;
const int SCREEN_HEIGHT = 1280 / 2;
const string WINDOW_NAME = "JokerFav's screen";


void InitSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		cout << "Init failed due to an error: " << SDL_GetError() << endl;

	window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(window == NULL)
		cout << "Creating window failed: " << SDL_GetError() << endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer == NULL) 
		cout << "Creating renderer failed: " << SDL_GetError() << endl;

	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void QuitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Texture* load_Texture(string path, SDL_Renderer* &renderer)
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


int main(int argc, char* argv[])
{

	SDL_Window* window;
	SDL_Renderer* renderer;
	InitSDL(window, renderer);

	SDL_Texture* MapTexture = load_Texture("res/super-dungeon.jfif", renderer);
	SDL_Rect tiles[3][9];

	for(int row = 0; row < 3; ++row)
		for(int col = 0; col < 9; ++col)
			{
				tiles[row][col].x = col * 512;
				tiles[row][col].y = row * 1280;
				tiles[row][col].w = SCREEN_WIDTH * 2;
				tiles[row][col].h = SCREEN_HEIGHT * 2;
			}
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 9; ++j)
			{
				SDL_RenderCopy(renderer, MapTexture, &tiles[i][j], NULL);
				SDL_RenderPresent(renderer);
				SDL_Delay(100);
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderClear(renderer);
				SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
			}


	QuitSDL(window, renderer);
	return 0;
}