#include "Exception.hpp"

#include <utility>

namespace Bare::System
{

Exception::Exception(string message)
    : message(std::move(message))
{
}

const char *Exception::what() const noexcept
{
    return message.c_str();
}

} // namespace Bare::System
