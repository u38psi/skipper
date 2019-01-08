#include "../hdrs/enemyHndl.h"

void createEnemyRow(Texture *enemy, Window *window,
                    char *path, int xOff, int yOff,
                    int padding, float scale)
{
  int offset = 0;
  for (int i = 0; i <= sizeof(enemy); i++)
  {
    enemy[i].imgPath = path;
    enemy[i].scale = scale;
    createTexture(window, &enemy[1]);

    enemy[i].xpos = xOff+offset;
    enemy[i].ypos = yOff;
    offset += padding;

  }
}

void renderEnemyRow(Window *window, Texture *enemy)
{
  for (int i = 0; i <= sizeof(enemy); i++)
  {
    renderTexture(window, &enemy[i]);
  }
}
