#include "util/logger.h"

#include <iostream>

UniquePtr<Logger> Logger::ms_Instance {nullptr};

Logger* Logger::GetInstance()
{
    if (!ms_Instance)
    {
        ms_Instance = UniquePtr<Logger>(new Logger());
    }
    
    return ms_Instance.get();
}

Logger::Logger() : m_LogLevel {LogLevel::Error}
{
}

void Logger::Log(const String& LogMessage, const LogLevel LogMessageLogLevel)
{
    if (m_LogLevel >= LogMessageLogLevel)
    {
        std::cout << PrintLogLevel(LogMessageLogLevel) << LogMessage << std::endl;
    }
}

void Logger::SetLogLevel(const LogLevel LogLevelToSet)
{
    m_LogLevel = LogLevelToSet;
}

String Logger::PrintLogLevel(const LogLevel LogLevelToPrint)
{
    switch (LogLevelToPrint)
    {
    case LogLevel::Debug:
        return "DEBUG: ";
    case LogLevel::Error:
        return "ERROR: ";
    case LogLevel::Minimal:
    default:
        return "MINIMAL: ";
    }
}
