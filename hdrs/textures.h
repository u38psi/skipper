#ifndef TEXTURES_H
#define TEXTURES_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "error.h"

typedef struct Texture
{
	int xpos;
	int ypos;
	int width;
	int height;
	char *imgPath;
	SDL_Rect srcR;
	SDL_Rect dstR;
	SDL_Texture *texture;
	SDL_Surface *surface;

} Texture;

void createTexture(SDL_Renderer *renderer, Texture *texture);

#endif
