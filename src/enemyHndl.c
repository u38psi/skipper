#include "../hdrs/enemyHndl.h"

void renderRow(EnemyRow *row, int amount)
{
  row->texture->xpos = row->initXOff;
  row->texture->ypos = row->yOff;
  for (int i = 0; i < amount; i++)
  {

    renderTexture(row->window, row->texture);
    row->texture->xpos += row->xOff;
  }
}
