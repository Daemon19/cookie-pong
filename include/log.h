#pragma once

#include <string>

namespace cookie::log
{
    enum Level
    {
        kInfo = 0,
        kWarning,
        kError
    };

    static Level log_level = kInfo;

    void Info(const std::string &message);
    void Warn(const std::string &message);
    void Error(const std::string &message);

    inline void set_level(Level level) { log_level = level; }
}