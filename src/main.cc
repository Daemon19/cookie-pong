#include <SDL2/SDL.h>
#include <iostream>

const int kWindowWidth = 800;
const int kWindowHeight = 600;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "[ERROR] Gagal menginisialisasi SDL: " << SDL_GetError()
                  << std::endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Pong", 0, 0, kWindowWidth,
                                          kWindowHeight, 0);
    if (window == NULL)
    {
        std::cerr << "[ERROR] Gagal membuat window: " << SDL_GetError()
                  << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED |
                                                    SDL_RENDERER_PRESENTVSYNC);

    bool game_running = true;

    while (game_running)
    {
        SDL_Event e;

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                game_running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 150, 200, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}