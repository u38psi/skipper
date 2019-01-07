#include "../hdrs/textures.h"

void createTexture(SDL_Renderer *renderer, Texture *texture)
{
	texture->surface = IMG_Load(texture->imgPath);
	if (!texture->surface)
		error(1);

	texture->texture = SDL_CreateTextureFromSurface(renderer, texture->surface);
	if (!texture->texture)
		error(1);

	texture->dstR.x = texture->xpos;
	texture->dstR.y = texture->ypos;
	texture->dstR.w = texture->width;
	texture->dstR.h = texture->height;

	SDL_FreeSurface(texture->surface);

}

void renderTexture(SDL_Renderer *renderer, Texture *texture)
{
	if (SDL_RenderCopy(renderer, texture->texture, NULL, &texture->dstR))
		error(1);


}
