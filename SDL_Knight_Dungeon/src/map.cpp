#include "Painter.hpp"
using namespace std;


int main(int argc, char* argv[])
{
	Painter painter;
	SDL_Texture* MapTexture = painter.load_texture("res/super-dungeon.jfif");
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
			painter.draw_map(tiles[i][j], MapTexture);
	painter.QuitSDL();
	return 0;
}
