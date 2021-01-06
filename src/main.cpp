#include "System/Application.hpp"

using Bare::System::Application;

int main(int argc, char **argv)
{
    // You need to provide the IoC container yourself
    // since otherwise there will be no option for
    // injecting any custom services, etc.
    ContainerBuilder builder;

    // TODO: Make sure to register your main loop
    // as singleInstance to the IoC container

    // Create the application and and run it
    Application application(&builder);
    application.run();

    return 0;
}
