#ifndef ENEMYHNDL_H
#define ENEMYHNDL_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "textures.h"
#include "init.h"
#include "main.h"

void renderEnemyRow(Texture *texture, Texture *collider, Window *window,
                    int size, int xOff, int yOff, int padding);

#endif
