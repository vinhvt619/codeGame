#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include<string>
#include<string.h>
#include <C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL.h>
#include <C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2\SDL_image.h>
#include <C:\Users\Admin\Documents\Git Hub\codeGame\ass2\src\include\SDL2/SDL_timer.h>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main()
{
	// Initialize SDL components
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	// Game logic
	{
		bool running = true;

		// Continue looping and processing events until user exits
		while (running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					running = false;
				}
				else if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						running = false;
					}
				}
			}

			// Clear the window to black
			SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
			SDL_RenderClear(renderer);

			//
			// Rendering will happen here
			//

			// Present the backbuffer
			SDL_RenderPresent(renderer);
		}
	}

	// Cleanup
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}