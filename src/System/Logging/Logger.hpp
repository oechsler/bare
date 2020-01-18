#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <stdlib.h>
#include <string>
#include <typeinfo>
#include <cxxabi.h>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>

using std::cout;
using std::endl;
using std::free;
using std::localtime;
using std::put_time;
using std::string;
using std::stringstream;
using std::unique_ptr;
using std::chrono::system_clock;

namespace Bare::System::Logging
{

template <typename T>
class Logger
{
    static const char* demangle(const char *mangled);

    void log(const char *channel, const char *message);

public:
    virtual void logDebug(const char *message);
    virtual void logInformation(const char *message);
    virtual void logWarning(const char *message);
    virtual void logError(const char *message);
    virtual void logFatal(const char *message, int exitCode = 1);
};

#define CHANNEL_DEBUG "DEBUG"
#define CHANNEL_INFO "\033[32mINFO\033[0m"
#define CHANNEL_WARN "\33[33mWARN\33[0m"
#define CHANNEL_ERROR "\33[31mERROR\33[0m"
#define CHANNEL_FATAL "\33[37;41mFATAL\33[0;0m"

template<typename T>
void Logger<T>::log(const char* channel, const char *message)
{
    auto time = system_clock::to_time_t(system_clock::now());
    auto timeString = put_time(localtime(&time), "%H:%M:%S");

    auto target = demangle(typeid(T).name());

    cout << "[" << timeString << " " << channel << " (" << target << ")" << "]: " << message << endl;
}

template<typename T>
const char* Logger<T>::demangle(const char* mangled)
{
    int status;
    unique_ptr<char[], void (*)(void *)> result(abi::__cxa_demangle(mangled, 0, 0, &status), free);
    return result.get() ? result.get() : nullptr;
}

template<typename T>
void Logger<T>::logDebug(const char* message)
{
    log(CHANNEL_DEBUG, message);
}

template<typename T>
void Logger<T>::logInformation(const char* message)
{
    log(CHANNEL_INFO, message);
}

template<typename T>
void Logger<T>::logWarning(const char* message)
{
    log(CHANNEL_WARN, message);
}

template<typename T>
void Logger<T>::logError(const char* message)
{
    log(CHANNEL_ERROR, message);
}

template<typename T>
void Logger<T>::logFatal(const char* message, int exitCode)
{
    log(CHANNEL_FATAL, message);
    exit(exitCode);
}

} // namespace Bare::System::Logging

#endif // LOGGER_HPP
