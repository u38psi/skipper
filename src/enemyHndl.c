#include "../hdrs/enemyHndl.h"

void renderEnemyRow(Texture *texture, Texture* collider, Window *window,
                    int size, int xOff, int yOff, int padding)
{
  for (int i = 0; i < size; i++)
  {
    texture->xpos = xOff;
    texture->ypos = yOff;
    if (collider->ypos <= texture->ypos+texture->height*texture->scale &&
        collider->xpos >= texture->xpos-texture->width*texture->scale &&
        collider->xpos <= texture->xpos+texture->width*texture->scale)
    {
      shot = 0;
      continue;
    }
    renderTexture(window, texture);
    xOff += padding;
  }

}
