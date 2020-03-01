#include "Exception.hpp"

namespace Bare::System
{

Exception::Exception(const string &message)
    : message(message)
{
}

const char *Exception::what() const throw()
{
    return message.c_str();
}

} // namespace Bare::System
