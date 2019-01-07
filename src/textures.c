#include "../hdrs/textures.h"

void createTexture(Window *window, Texture *texture)
{
	texture->surface = IMG_Load(texture->imgPath);
	if (!texture->surface)
		error(1);

	texture->texture = SDL_CreateTextureFromSurface(window->renderer, texture->surface);
	if (!texture->texture)
		error(1);

	SDL_QueryTexture(texture->texture, NULL, NULL, &texture->width, &texture->height);

	SDL_FreeSurface(texture->surface);

}

void renderTexture(Window *window, Texture *texture)
{
	texture->dstR.x = texture->xpos;
	texture->dstR.y =	texture->ypos;
	texture->dstR.w = texture->width*texture->scale;
	texture->dstR.h = texture->height*texture->scale;

	if (SDL_RenderCopy(window->renderer, texture->texture, NULL, &texture->dstR))
		error(1);


}
