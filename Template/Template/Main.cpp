#include <SDL3/SDL.h>       // SDL core: window, renderer, events, etc.
#include <SDL3/SDL_main.h>  // Fixes 'main' entry point for all platforms
#include "Main.h"

int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* window = SDL_CreateWindow("WINDOW", 800, 600, SDL_WINDOW_RESIZABLE);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

	float rectx = 0.0f;
	float recty = 200.0f;

	float speed = 200.0f;

	Uint64 lastTime = SDL_GetTicks();

	bool running = true;
	SDL_Event event; 

	while (running) {
		Uint64 currentTime = SDL_GetTicks();
		float deltaTime = (currentTime - lastTime) / 1000.0f;
		lastTime = currentTime;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) running = false;
			if (event.type == SDL_EVENT_KEY_DOWN)
				if (event.key.key == SDLK_ESCAPE) running = false;
		}
		rectx += speed * deltaTime;
		SDL_FRect rect = { rectx, recty, 100.0f, 200.0f };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}


	/*SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderPoint(renderer, 400.0f, 300.0f);	


	SDL_FPoint points[] = {
		{400.0f, 300.0f},
		{401.0f, 300.0f},
		{402.0f, 300.0f},
		{403.0f, 300.0f},
		{404.0f, 300.0f},
	};

	SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
	SDL_RenderPoints(renderer, points, 5);

	SDL_FPoint lines[] = {
		{400.0f, 0.0f},
		{400.0f, 600.0f },
		{800.0f, 300.0f },
		{0.0f, 300.0f },
	};

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderLines(renderer, lines, 4);

	SDL_FPoint square[] = {
		{400.0f, 400.0f},
		{600.0f, 400.0f},
		{600.0f, 600.0f},
		{400.0f, 600.0f},
	};

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderPoints(renderer, points, 5);*/



	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderLine(renderer, 0, 0, 800, 600);

	SDL_RenderLine(renderer, 800, 0, 0, 600);
	
	
	
	SDL_RenderPresent(renderer);	

	SDL_FRect rect = { 400.0f, 300.0f, 150.0f, 200.0f }; 
	SDL_RenderRect(renderer, &rect);
	/*SDL_Event event;
	bool running = true;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT)
				running = false;
			if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE)
				running = false;
		}
		
	}*/

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;

}