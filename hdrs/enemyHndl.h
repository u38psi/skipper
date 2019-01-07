#ifndef ENEMYHNDL_H
#define ENEMYHNDL_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "textures.h"

typedef struct EnemyRow
{
  Texture *texture;
  Window *window;
  int initXOff;
  int xOff, yOff;
  int x1, x2, y;
} EnemyRow;

void renderRow(EnemyRow *enemy, int amount, Texture *bullet);

#endif
