#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <memory>
#include <typeinfo>
#include <cxxabi.h>
#include <fmt/format.h>
#include <fmt/chrono.h>
#include <fmt/color.h>
#include <boost/core/demangle.hpp>

#include "System/Exception.hpp"

using Bare::System::Exception;
using fmt::format;
using fmt::format_args;
using fmt::make_format_args;
using fmt::print;
using fmt::vformat;
using std::free;
using std::localtime;
using std::string;
using std::unique_ptr;
using boost::core::demangle;

#define LEVEL_DEBUG 0
#define LEVEL_INFO 1
#define LEVEL_WARN 2
#define LEVEL_ERROR 3
#define LEVEL_FATAL 4

#ifndef LOG_LEVEL
#define LOG_LEVEL LEVEL_DEBUG
#endif

namespace Bare::System::Logging
{

#define CHANNEL_DEBUG "DEBUG"
#define CHANNEL_INFO "\033[32mINFO\033[0m"
#define CHANNEL_WARN "\33[33mWARN\33[0m"
#define CHANNEL_ERROR "\33[31mERROR\33[0m"
#define CHANNEL_FATAL "\33[37;41mFATAL\33[0;0m"

template <typename T>
class Logger
{
    void log(const string &channel, const string &message, format_args args);

public:
    template <typename... Args>
    void logDebug(const string &message, const Args &... args);
    template <typename... Args>
    void logInformation(const string &message, const Args &... args);
    template <typename... Args>
    void logWarning(const string &message, const Args &... args);
    template <typename... Args>
    void logError(const string &message, const Args &... args);
    template <typename... Args>
    void logFatal(const string &message, const Args &... args);
};

template <typename T>
void Logger<T>::log(const string &channel, const string &message, format_args args)
{
    // Generate current timestamp
    auto now = time(nullptr);
    auto timeString = format("{:%H:%M:%S}", *localtime(&now));

    // Get the name of the logger's target
    auto targetName = typeid(T).name();
    auto targetString = demangle(targetName);

    // Finally generate log message
    auto messageString = format("[{0} {1}]({2}): {3}\n", channel, timeString, targetString, message);
    auto printString = vformat(messageString, args);

    // Print generated log message to stdout
    print(printString);

    // TODO: Add other print options for ex.: file, etc.
}

template <typename T>
template <typename... Args>
void Logger<T>::logDebug(const string &message, const Args &... args)
{
#if ! LOG_LEVEL > LEVEL_DEBUG
    log(CHANNEL_DEBUG, message, make_format_args(args...));
#endif
}

template <typename T>
template <typename... Args>
void Logger<T>::logInformation(const string &message, const Args &... args)
{
#if !(LOG_LEVEL > LEVEL_INFO)
    log(CHANNEL_INFO, message, make_format_args(args...));
#endif
}

template <typename T>
template <typename... Args>
void Logger<T>::logWarning(const string &message, const Args &... args)
{
#if !(LOG_LEVEL > LEVEL_WARN)
    log(CHANNEL_WARN, message, make_format_args(args...));
#endif
}

template <typename T>
template <typename... Args>
void Logger<T>::logError(const string &message, const Args &... args)
{
#if !(LOG_LEVEL > LEVEL_ERROR)
    log(CHANNEL_ERROR, message, make_format_args(args...));
#endif
}

template <typename T>
template <typename... Args>
void Logger<T>::logFatal(const string &message, const Args &... args)
{
#if LOG_LEVEL <= LEVEL_FATAL
    log(CHANNEL_FATAL, message, make_format_args(args...));

    // TODO: Evaluate if this solution makes sense
    throw Exception(message);
#endif
}

} // namespace Bare::System::Logging

#endif // LOGGER_HPP
