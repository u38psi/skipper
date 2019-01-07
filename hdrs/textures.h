#ifndef TEXTURES_H
#define TEXTURES_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "init.h"
#include "error.h"

typedef struct Texture
{
	char *imgPath;
	float scale;
	int xpos;
	int ypos;
	int width;
	int height;
	char vel;
	SDL_Rect dstR;
	SDL_Texture *texture;
	SDL_Surface *surface;

} Texture;

void createTexture(Window *window, Texture *texture);

void renderTexture(Window *window, Texture *texture);

#endif
