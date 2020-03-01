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
    string message;

public:
    Exception(const string &message);

    virtual const char *what() const throw();
};

} // namespace Bare::System

#endif // EXCEPTION_HPP
