#include "hdrs/textures.h"

void createTexture(SDL_Renderer *renderer, Texture *texture)
{
	texture->surface = IMG_Load(texture->imgPath);
	if (!texture->surface)
		error(1);
	
	texture->texture = SDL_CreateTextureFromSurface(renderer, texture->surface);
	if (!texture->texture)
		error(1);
	
	SDL_FreeSurface(texture->surface);

}
