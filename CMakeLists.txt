cmake_minimum_required(VERSION 3.16)
project(cdemo VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)

find_package(FMT REQUIRED)
find_package(HYPODERMIC REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL_GPU REQUIRED)
find_package(OPENGL REQUIRED)

set(HEADER_FILES "src/System/Exception.hpp"
                 "src/System/IApplication.hpp"
                 "src/System/Application.hpp"
                 "src/System/Logging/Logger.hpp"
                 "src/System/Events/IDispatch.hpp"
                 "src/System/Events/Dispatch.hpp"
                 "src/System/Events/Event.hpp"
                 "src/System/Events/Handler.hpp"
                 "src/System/Display/AspectRatio.hpp"
                 "src/System/Display/IWindow.hpp"
                 "src/System/Display/Window.hpp")

set(SOURCE_FILES "src/main.cpp"
                 "src/System/Exception.cpp"
                 "src/System/Application.cpp"
                 "src/System/Events/Dispatch.cpp"
                 "src/System/Events/Event.cpp"
                 "src/System/Display/AspectRatio.cpp"
                 "src/System/Display/Window.cpp")


# Build the executable
add_executable("${PROJECT_NAME}" ${HEADER_FILES} ${SOURCE_FILES})
#target_compile_definitions("${PROJECT_NAME}" PRIVATE LOG_LEVEL=2)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/src")

target_include_directories(${PROJECT_NAME} PRIVATE ${HYPODERMIC_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL_GPU_INCLUDE_DIR})

# Link the executable against all retrived dependencies
target_link_libraries(${PROJECT_NAME} fmt::fmt
                                      ${SDL2_LIBRARY}
                                      ${SDL_GPU_LIBRARY}
                                      ${OPENGL_LIBRARIES})
