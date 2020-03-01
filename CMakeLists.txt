cmake_minimum_required(VERSION 3.16)
project(cdemo VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)

# Fmt library
find_package(FMT REQUIRED)

# SDL2 core library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# SDL2_gpu extension library
find_package(SDL_GPU REQUIRED)
include_directories(${SDL_GPU_INCLUDE_DIR})

# OpenGL library
find_package(OPENGL REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/src")

file(GLOB SOURCE_FILES "src/*.cpp"
                       "src/System/*.cpp"
                       "src/System/Events/*.cpp"
                       "src/System/Display/*.cpp")

add_executable("${PROJECT_NAME}" ${SOURCE_FILES})
target_link_libraries("${PROJECT_NAME}" fmt::fmt
                                        ${SDL2_LIBRARY}
                                        ${SDL_GPU_LIBRARY}
                                        ${OPENGL_LIBRARIES})
