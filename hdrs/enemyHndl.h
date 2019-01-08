#ifndef ENEMYHNDL_H
#define ENEMYHNDL_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "textures.h"
#include "init.h"

void createEnemyRow(Texture *enemyclear, Window *window,
                    char *path, int xOff, int yOff,
                    int padding, float scale);

void renderEnemyRow(Window *window, Texture *enemy);

#endif
