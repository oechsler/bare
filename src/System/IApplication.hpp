#ifndef I_APPLICATION_HPP
#define I_APPLICATION_HPP

namespace Bare::System
{

class IApplication
{
public:
    virtual ~IApplication() = default;

    virtual void run() = 0;
};

} // namespace Bare::System

#endif // I_APPLICATION_HPP
