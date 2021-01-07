cmake_minimum_required(VERSION 3.16)
project(extern)

include(ExternalProject)

ExternalProject_Add(
        SDL2
        URL https://www.libsdl.org/tmp/SDL-2.0.13-14202.tar.gz
        URL_HASH MD5=f10328dc1724470433e3ca05a662d146
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/build/SDL2
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/build/SDL2
        INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
        CMAKE_ARGS -D CMAKE_INSTALL_PREFIX=<INSTALL_DIR>
        -D SDL_SHARED=OFF)

ExternalProject_Add(
        bgfx
        GIT_REPOSITORY https://github.com/pr0g/bgfx.cmake.git
        GIT_TAG main
        GIT_SHALLOW 1
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/build/bgfx
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/build/bgfx
        INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
        CMAKE_ARGS -D CMAKE_INSTALL_PREFIX=<INSTALL_DIR>
        -D BGFX_BUILD_EXAMPLES=OFF)

ExternalProject_Add(
        cmakefied
        GIT_REPOSITORY https://github.com/pr0g/cmakefied.git
        GIT_TAG main
        UPDATE_COMMAND bash <SOURCE_DIR>/git-clone.sh imgui
        SOURCE_SUBDIR ../imgui
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/build/imgui
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/build/imgui
        INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
        CMAKE_ARGS -D CMAKE_INSTALL_PREFIX=<INSTALL_DIR>)

ExternalProject_Add(
        boost
        URL https://dl.bintray.com/boostorg/release/1.75.0/source/boost_1_75_0.tar.bz2
        URL_HASH SHA256=953db31e016db7bb207f11432bef7df100516eeb746843fa0486a222e3fd49cb
        BUILD_IN_SOURCE 1
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/build/boost
        INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
        CONFIGURE_COMMAND ./bootstrap.sh --with-libraries=system,test --prefix=<INSTALL_DIR>
        BUILD_COMMAND ./b2 install runtime-link=static variant=release threading=multi
        INSTALL_COMMAND "")

ExternalProject_Add(
        Hypodermic
        GIT_REPOSITORY https://github.com/ybainier/Hypodermic.git
        GIT_TAG master
        GIT_SHALLOW 1
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/build/Hypodermic
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/build/Hypodermic
        INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
        CMAKE_ARGS -D CMAKE_INSTALL_PREFIX=<INSTALL_DIR>)

ExternalProject_Add(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master
        GIT_SHALLOW 1
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/build/fmt
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/build/fmt
        INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
        CMAKE_ARGS -D CMAKE_INSTALL_PREFIX=<INSTALL_DIR>)

ExternalProject_Add(
        nameof
        GIT_REPOSITORY https://github.com/Neargye/nameof
        GIT_TAG master
        GIT_SHALLOW 1
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/build/nameof
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/build/nameof
        INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
        CMAKE_ARGS -D CMAKE_INSTALL_PREFIX=<INSTALL_DIR>)
