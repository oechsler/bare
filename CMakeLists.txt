cmake_minimum_required(VERSION 3.16)
project(cdemo VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)

# Find Fmt library
find_package(FMT REQUIRED)

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# Find SDL2_gpu library
find_package(SDL_GPU REQUIRED)
include_directories(${SDL_GPU_INCLUDE_DIR})

# Find OpenGL library
find_package(OPENGL REQUIRED)

# Retrive all project header and source files
include_directories("${CMAKE_SOURCE_DIR}/src")

set(HEADER_FILES "src/System/Exception.hpp"
                 "src/System/Logging/Logger.hpp"
                 "src/System/Events/Dispatch.hpp"
                 "src/System/Events/Event.hpp"
                 "src/System/Events/Handler.hpp"
                 "src/System/Display/AspectRatio.hpp"
                 "src/System/Display/IWindow.hpp"
                 "src/System/Display/Window.hpp")

set(SOURCE_FILES "src/main.cpp"
                 "src/System/Exception.cpp"
                 "src/System/Events/Dispatch.cpp"
                 "src/System/Events/Event.cpp"
                 "src/System/Display/AspectRatio.cpp"
                 "src/System/Display/Window.cpp")


# Build the executable
add_executable("${PROJECT_NAME}" ${HEADER_FILES} ${SOURCE_FILES})
#target_compile_definitions("${PROJECT_NAME}" PRIVATE LOG_LEVEL=2)

# Link the executable against all retrived dependencies
target_link_libraries("${PROJECT_NAME}" fmt::fmt
                                        ${SDL2_LIBRARY}
                                        ${SDL_GPU_LIBRARY}
                                        ${OPENGL_LIBRARIES})
