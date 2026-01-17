#pragma once

#include "util/types.h"

enum class LogLevel : uint8
{
    Minimal,
    Error,
    Debug
};

class Logger
{
public:
    static Logger* GetInstance();

    Logger(const Logger& LoggerToCopy) = delete;
    Logger& operator=(const Logger& LoggerToCopy) = delete;
    
    void Log(const String& LogMessage, const LogLevel LogMessageLogLevel);
private:
    static UniquePtr<Logger> ms_Instance;
    
    LogLevel m_LogLevel;

    Logger();
    
    String PrintLogLevel(const LogLevel LogLevelToPrint);
};
