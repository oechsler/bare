#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace Bare::System
{

class Exception : public exception
{
    // Variables / properties
    string message;
    // END: Variables / properties

public:
    explicit Exception(string message);

    [[nodiscard]] const char *what() const noexcept override;
};

} // namespace Bare::System

#endif // EXCEPTION_HPP
