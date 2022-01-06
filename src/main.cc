#include <SDL2/SDL.h>
#include <iostream>

#include "entities.h"
#include "log.h"
#include "window.h"

const int kWindowWidth = 800;
const int kWindowHeight = 600;

const SDL_Color kBackgroundColor{90, 44, 34, 255};

const int kPlayerCount = 2;
const int kPlayerWidth = 12;
const int kPlayerHeight = 120;
const int kPlayerXOff = 10;

const int kBallWidth = 14;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cookie::log::SdlError("Gagal menginisialisasi SDL");
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

    Ball ball((kWindowWidth - kBallWidth) / 2.0f,
              (kWindowHeight - kBallWidth) / 2.0f,
              kBallWidth, kBallWidth);

    Entity *entities[kPlayerCount + 1 /* ball */] = {&players[0], &players[1], &ball};

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

                case (SDLK_UP):
                    players[1].set_move_up(true);
                    break;

                case (SDLK_DOWN):
                    players[1].set_move_down(true);
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

                case (SDLK_UP):
                    players[1].set_move_up(false);
                    break;

                case (SDLK_DOWN):
                    players[1].set_move_down(false);
                    break;

                default:
                    break;
                }
            }
        }

        SDL_SetRenderDrawColor(window.renderer(), kBackgroundColor.r,
                               kBackgroundColor.g, kBackgroundColor.b,
                               kBackgroundColor.a);
        SDL_RenderClear(window.renderer());

        for (Entity *e : entities)
        {
            e->Draw(window.renderer());
            e->Update();
            e->CheckVerticalBorder(kWindowHeight);
        }

        ball.MoveAndCheckCollision(players, kPlayerCount);
        ball.CheckHorizontalBorder(kWindowWidth, players[0], players[1]);

        SDL_RenderPresent(window.renderer());
    }

    SDL_Quit();

    return 0;
}