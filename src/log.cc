#include "log.h"
#include <iostream>

namespace cookie::log
{
    void Info(const std::string &message)
    {
        if (log_level <= kInfo)
            std::clog << "[INFO] " << message << std::endl;
    }

    void Warn(const std::string &message)
    {
        if (log_level <= kWarning)
            std::clog << "[WARNING] " << message << std::endl;
    }

    void Error(const std::string &message)
    {
        if (log_level <= kError)
            std::clog << "[ERROR] " << message << std::endl;
    }
}
