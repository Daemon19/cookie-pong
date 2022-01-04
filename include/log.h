#pragma once

#include <string>

namespace cookie::log
{
    enum Level
    {
        kLevelInfo = 0,
        kLevelWarning,
        kLevelError
    };

    static Level log_level = kLevelInfo;

    void Info(const std::string &message);
    void Warn(const std::string &message);
    void Error(const std::string &message);
    // Log message ditambah dengan SDL_GetError()
    void SdlError(const std::string &message);

    inline void SetLevel(Level level) { log_level = level; }
}