cmake_minimum_required(VERSION 3.16)
project(bare VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/bin")

if (APPLE)
    find_library(FOUNDATION_LIB Foundation)
    find_library(AV_FOUNDATION_LIB AVFoundation)
    find_library(AUDIO_TOOLBOX_LIB AudioToolbox)
    find_library(CORE_AUDIO_LIB CoreAudio)
    find_library(CARBON_LIB Carbon)
    find_library(FORCE_FEEDBACK_LIB ForceFeedback)
    find_library(IO_KIT_LIB IOKit)
    find_library(COCOA_LIB Cocoa)
    find_library(CORE_VIDEO_LIB CoreVideo)
    find_library(QUARTZ_CORE_LIB QuartzCore)
    find_library(METAL_LIB Metal)
    find_library(ICONV_LIB iconv)
    set(SYSTEM_LIBS
            ${AUDIO_TOOLBOX_LIB}
            ${AV_FOUNDATION_LIB}
            ${FOUNDATION_LIB}
            ${CORE_AUDIO_LIB}
            ${CARBON_LIB}
            ${FORCE_FEEDBACK_LIB}
            ${IO_KIT_LIB}
            ${COCOA_LIB}
            ${CORE_VIDEO_LIB}
            ${QUARTZ_CORE_LIB}
            ${METAL_LIB}
            ${ICONV_LIB})

    message("Gathered Apple specific Frameworks for Bare")
endif (APPLE)

set(HEADER_FILES src/System/Exception.hpp
        src/System/IApplication.hpp
        src/System/Application.hpp
        src/System/Logging/Logger.hpp
        src/System/Events/IDispatch.hpp
        src/System/Events/Dispatch.hpp
        src/System/Events/Event.hpp
        src/System/Events/Handler.hpp
        src/System/Display/AspectRatio.hpp
        src/System/Display/IWindow.hpp
        src/System/Display/SdlWindow.hpp
        src/System/Renderer/IRenderer.hpp
        src/System/Renderer/BgfxRenderer.hpp
        src/System/Display/IContextHandle.hpp
        src/System/Display/SdlContextHandle.hpp)

set(SOURCE_FILES src/main.cpp
        src/System/Exception.cpp
        src/System/Application.cpp
        src/System/Events/Dispatch.cpp
        src/System/Events/Event.cpp
        src/System/Display/AspectRatio.cpp
        src/System/Display/SdlWindow.cpp
        src/System/Renderer/BgfxRenderer.cpp
        src/System/Display/SdlContextHandle.cpp)


# Build the executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
#target_compile_definitions(${PROJECT_NAME} PRIVATE LOG_LEVEL=2)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/extern/include)
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/extern/lib)
file(GLOB_RECURSE EXTERN_LIBS ${CMAKE_SOURCE_DIR}/extern/lib/*.a)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link the executable against all retrieved dependencies
target_link_libraries(${PROJECT_NAME}
        ${EXTERN_LIBS}
        ${SYSTEM_LIBS})
