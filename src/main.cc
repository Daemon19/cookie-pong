#include "cookie.h"
#include "entities.h"
#include <SDL2/SDL.h>

const int kWindowWidth = 800;
const int kWindowHeight = 600;

const SDL_Color kBackgroundColor{90, 44, 34, 255};
const SDL_Color kWhite{255, 255, 255, 0};

const int kPlayerCount = 2;
const int kPlayerWidth = 12;
const int kPlayerHeight = 120;
const int kPlayerXOff = 10;
const int kPlayerScoreOff = 60;

const int kBallWidth = 14;

const char *const kFontPath = "res/font/8bitOperatorPlusSC-Bold.ttf";

int main(int argc, char *argv[])
{

    cookie::Initializer initer;
    initer.InitSdl(SDL_INIT_VIDEO);
    initer.InitTtf();

    cookie::Font font(kFontPath, 50);

    cookie::Window window("Pong", kWindowWidth, kWindowHeight);

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

        SDL_SetRenderDrawColor(window.renderer(),
                               kBackgroundColor.r,
                               kBackgroundColor.g,
                               kBackgroundColor.b,
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

        for (int i = 0; i < kPlayerCount; i++)
        {
            cookie::Texture score_tex = font.CreateTexture(window, std::to_string(players[i].score()), kWhite);

            cookie::Rect score_rect(0, 0, score_tex.w(), score_tex.h());
            score_rect.set_centerx((i == 0) ? kPlayerScoreOff : kWindowWidth - kPlayerScoreOff);
            score_rect.set_centery(kPlayerScoreOff);

            SDL_Rect rect = score_rect;
            SDL_RenderCopy(window.renderer(), score_tex.sdl_tex(), NULL, &rect);
        }

        SDL_RenderPresent(window.renderer());
    }

    return 0;
}