#include "log.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

namespace cookie::log
{
    void Info(const std::string &message)
    {
        if (log_level <= kLevelInfo)
        {
            std::cerr << "[INFO] " << message << std::endl;
        }
    }

    void Warn(const std::string &message)
    {
        if (log_level <= kLevelWarning)
        {
            std::cerr << "[WARNING] " << message << std::endl;
        }
    }

    void Error(const std::string &message)
    {
        if (log_level <= kLevelError)
        {
            std::cerr << "[ERROR] " << message << std::endl;
        }
    }

    void SdlError(const std::string &message)
    {
        if (log_level <= kLevelError)
        {
            std::cerr << "[SDL ERROR] " << message << ": " << SDL_GetError()
                      << std::endl;
        }
    }
}