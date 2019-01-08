#include "../hdrs/main.h"

int main(int argc, char *argv[])
{
	SDL_Event event;

	Window mainWin = {NULL, NULL,
		             		SDL_INIT_EVERYTHING,
										SDL_WINDOW_OPENGL,
										SDL_RENDERER_ACCELERATED,
										-1, 1024, 800, "Skippers struggle"};

	Texture skipper = {"sprites/img_skipper.png", 0.2f};
	Texture bullet = {"sprites/img_bullet.png", 0.15f};
	Texture donald1 = {"sprites/img_donald.png", 0.04f};
	Texture donald2 = {"sprites/img_donald2.png", 0.1f};

	initFlags(&mainWin);

	createWindow(&mainWin);
	createRenderer(&mainWin);

	createTexture(&mainWin, &skipper);
	createTexture(&mainWin, &bullet);
	createTexture(&mainWin, &donald1);
	createTexture(&mainWin, &donald2);

	skipper.xpos = (mainWin.width/2)-80;
	skipper.ypos = mainWin.height-(skipper.height*skipper.scale);

	game = 1;
	shot = 0;

	while(game)
	{

		SDL_RenderClear(mainWin.renderer);

		renderTexture(&mainWin, &skipper);

		renderEnemyRow(&donald1, &bullet, &mainWin, 6, 50, 60, 100);
		renderEnemyRow(&donald2, &bullet, &mainWin, 6, 70, 120, 100);
		renderEnemyRow(&donald2, &bullet, &mainWin, 6, 70, 180, 100);

		if (shot)
			renderTexture(&mainWin, &bullet);

		SDL_RenderPresent(mainWin.renderer);

		SDL_PollEvent(&event);
		if (SDL_QuitRequested())
			quit(&mainWin, 0);

		switch (event.type)
		{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case 0x0D:
						quit(&mainWin, 0);
						break;

					case 0x61:
						skipper.vel = -10;
						break;

					case 0x64:
						skipper.vel = 10;
						break;

					case 0x20:
						if (!shot)
						{
							bullet.xpos = skipper.xpos + 50;
							bullet.ypos = skipper.ypos - bullet.height*bullet.scale;
							shot = 1;
						}
						break;

					default: break;
				}
				break;

			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case 0x61:
						if (skipper.vel < 0)
							skipper.vel = 0;
						break;

					case 0x64:
						if (skipper.vel > 0)
							skipper.vel = 0;
						break;

					default: break;
				}
				break;

				default: break;

		}

		//UPDATE
		skipper.xpos += skipper.vel;

		if (shot && bullet.ypos > 0)
			bullet.ypos -= 15;
		else
			shot = 0;


		if (skipper.xpos <= 0 || skipper.xpos >= mainWin.width-(skipper.width*skipper.scale))
			skipper.xpos -= skipper.vel;

		SDL_Delay(1000/64);
	}

	SDL_DestroyTexture(skipper.texture);
	SDL_DestroyTexture(bullet.texture);

	return 0;

}
