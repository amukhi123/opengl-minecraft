cmake_minimum_required(VERSION 4.2)

project(opengl_minecraft VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

if("${CMAKE_GENERATOR}" STREQUAL "Ninja")
	set(CMAKE_EXPORT_COMPILE_COMMANDS on)
endif()

include_directories("include")
include_directories("lib/glad")
include_directories("lib/glfw/include")

add_subdirectory("lib/glfw")

set(SRC_FILES src/main.cpp)

file(GLOB_RECURSE ENGINE_FILES src/enigne/*.cpp include/engine/*.h)
file(GLOB_RECURSE GFX_FILES src/gfx/*.cpp include/gfx/*.h)
file(GLOB_RECURSE UTIL_FILES src/util/*.cpp include/util/*.h)
file(GLOB_RECURSE SHADER_FILES res/shaders/*.vs res/shaders/*.fs)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${ENGINE_FILES} ${GFX_FILES} ${UTIL_FILES} ${SHADER_FILES})

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} glfw)

if("${CMAKE_GENERATOR}" STREQUAL "Visual Studio 18 2026")
    # Only apply to Visual Studio (to create filters)
    source_group("src" FILES ${SRC_FILES})
    source_group("src\\gfx" FILES ${GFX_FILES})
    source_group("src\\engine" FILES ${ENGINE_FILES})
    source_group("src\\util" FILES ${UTIL_FILES})
    source_group("res\\shader" FILES ${SHADER_FILES})
    
    set_directory_properties(PROPERTIES VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()
