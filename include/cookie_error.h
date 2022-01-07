#pragma once

#include <SDL2/SDL.h>
#include <stdexcept>
#include <string>

namespace cookie
{
    class SdlError : public std::runtime_error
    {
    public:
        SdlError(const std::string &message)
            : runtime_error(Format(message)) {}
        SdlError(const char *message)
            : runtime_error(Format(message)) {}

    private:
        std::string Format(const std::string &message)
        {
            return "[SDL ERROR] " + message + " : " + SDL_GetError();
        }
    };

    class CookieError : public std::runtime_error
    {
    public:
        CookieError(const std::string &message)
            : runtime_error(Format(message)) {}
        CookieError(const char *message)
            : runtime_error(Format(message)) {}

    private:
        std::string Format(const std::string &message)
        {
            return "[COOKIE ERROR] " + message;
        }
    };
}