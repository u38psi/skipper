#include "../hdrs/main.h"

int main(int argc, char *argv[])
{

	char shot;

	SDL_Event event;

	Window mainWin = {NULL, NULL,
		             		SDL_INIT_EVERYTHING,
										SDL_WINDOW_OPENGL,
										SDL_RENDERER_ACCELERATED,
										-1, 1024, 800, "Skippers struggle"};

	Texture skipper = {"sprites/img_skipper.png", 0.2f};
	Texture donald1 = {"sprites/img_donald.png", 0.04f};
	Texture donald2 = {"sprites/img_donald2.png", 0.1f};
	Texture donald3 = {"sprites/img_donald3.png", 0.2f};
	Texture bullet = {"sprites/img_bullet.png", 0.15f};

	initFlags(&mainWin);

	createWindow(&mainWin);
	createRenderer(&mainWin);

	createTexture(&mainWin, &skipper);
	createTexture(&mainWin, &donald1);
	createTexture(&mainWin, &donald2);
	createTexture(&mainWin, &donald3);
	createTexture(&mainWin, &bullet);

	skipper.xpos = (mainWin.width/2)-80;
	skipper.ypos = mainWin.height-(skipper.height*skipper.scale);

	EnemyRow d1;
	d1.texture = &donald1;
	d1.window = &mainWin;
	d1.initXOff = 50;
	d1.xOff = 100;
	d1.yOff = 60;
	d1.x = donald1.width;
	d1.y = donald1.height;

	EnemyRow d2;
	d2.texture = &donald2;
	d2.window = &mainWin;
	d2.initXOff = 60;
	d2.xOff = 100;
	d2.yOff = 120;
	d2.x = donald2.width;
	d2.y = donald2.height;

	EnemyRow d3;
	d3.texture = &donald2;
	d3.window = &mainWin;
	d3.initXOff = 60;
	d3.xOff = 100;
	d3.yOff = 180;
	d3.x = donald2.width;
	d3.y = donald2.height;

	EnemyRow d4;
	d4.texture = &donald3;
	d4.window = &mainWin;
	d4.initXOff = 50;
	d4.xOff = 100;
	d4.yOff = 240;
	d4.x = donald3.width;
	d4.y = donald3.height;

	game = 1;
	shot = 0;

	while(game)
	{

		SDL_RenderClear(mainWin.renderer);

		renderTexture(&mainWin, &skipper);

		renderRow(&d1, 7, &bullet);
		renderRow(&d2, 7, &bullet);
		renderRow(&d3, 7, &bullet);
		renderRow(&d4, 7, &bullet);

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
	SDL_DestroyTexture(donald1.texture);
	SDL_DestroyTexture(donald2.texture);
	SDL_DestroyTexture(donald3.texture);
	SDL_DestroyTexture(bullet.texture);

	return 0;

}
