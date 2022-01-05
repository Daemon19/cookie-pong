#include <SDL2/SDL.h>
#include <iostream>

#include "entities.h"
#include "log.h"
#include "window.h"

const int kWindowWidth = 800;
const int kWindowHeight = 600;

const int kPlayerCount = 2;
const int kPlayerWidth = 12;
const int kPlayerHeight = 120;
const int kPlayerXOff = 10;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cookie::log::SdlError("[ERROR] Gagal menginisialisasi SDL");
        return -1;
    }

    cookie::Window window("Pong", kWindowWidth, kWindowHeight);

    if (!window.Init())
    {
        SDL_Quit();
        return -1;
    }

    float tmp_player_y = (kWindowHeight - kPlayerHeight) / 2.0f;

    Player players[kPlayerCount] = {Player(kPlayerXOff, tmp_player_y,
                                           kPlayerWidth, kPlayerHeight),
                                    Player(kWindowWidth - kPlayerWidth - kPlayerXOff,
                                           tmp_player_y, kPlayerWidth, kPlayerHeight)};

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
            if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case (SDLK_w):
                    players[0].set_move_up(true);
                    break;

                case (SDLK_s):
                    players[0].set_move_down(true);
                    break;

                default:
                    break;
                }
            }
            if (e.type == SDL_KEYUP)
            {
                switch (e.key.keysym.sym)
                {
                case (SDLK_w):
                    players[0].set_move_up(false);
                    break;

                case (SDLK_s):
                    players[0].set_move_down(false);
                    break;

                default:
                    break;
                }
            }
        }

        SDL_SetRenderDrawColor(window.renderer(), 90, 44, 34, 255);
        SDL_RenderClear(window.renderer());

        for (Player &p : players)
        {
            p.Draw(window.renderer());
            p.Update();
            p.CheckBorder(kWindowWidth, kWindowHeight);
        }

        SDL_RenderPresent(window.renderer());
    }

    SDL_Quit();

    return 0;
}