#include "window.h"
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

    cookie::Window window("Pong", kWindowWidth, kWindowHeight);

    if (!window.Init())
    {
        SDL_Quit();
        return -1;
    }

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

        SDL_SetRenderDrawColor(window.renderer(), 0, 150, 200, 255);
        SDL_RenderClear(window.renderer());
        SDL_RenderPresent(window.renderer());
    }

    SDL_Quit();

    return 0;
}