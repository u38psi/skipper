#include "../hdrs/main.h"

int main(int argc, char *argv[])
{
	Texture skipper = {1024/4, 784-150, 300, 150, "sprites/img_skipper.png"};

	Window mainWin = {NULL, NULL, SDL_INIT_EVERYTHING, 0, 0, -1, 1024, 784, "Skippers struggle"};

	initFlags(&mainWin);
	createWindow(&mainWin);
	createRenderer(&mainWin);
	createTexture(mainWin.renderer, &skipper);

	SDL_Event event;

	game = 1;

	while(game)
	{

		SDL_RenderClear(mainWin.renderer);
		renderTexture(mainWin.renderer, &skipper);
		SDL_RenderPresent(mainWin.renderer);

		SDL_PollEvent(&event);

		if (SDL_QuitRequested())
				quit(&mainWin, 0);

		switch (event.type)
		{
			if (SDL_QuitRequested())
				quit(&mainWin, 0);

			switch (event.type)
			{
				case SDL_KEYDOWN:

					switch (event.key.keysym.sym)
					{
						case 0x0D:
							quit(&mainWin, 0);

						default:
							break;
					}
			}
		}

		//Update


	}

	SDL_DestroyTexture(skipper.texture);

	return 0;

}
