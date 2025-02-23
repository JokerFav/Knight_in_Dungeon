#ifndef Painter_HPP
#define Painter_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 512 / 2;
const int SCREEN_HEIGHT = 1280 / 2;
const string WINDOW_NAME = "JokerFav's screen";

class Painter
{
	public:
			Painter();
			void before_draw();
			SDL_Texture* load_texture(string path);
			void QuitSDL();
			void draw_map(SDL_Rect &tile, SDL_Texture* &MapTexture);

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
};


#endif