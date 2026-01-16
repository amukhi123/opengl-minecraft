cmake_minimum_required(VERSION 3.15)

project(opengl_minecraft VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

include_directories("include")
include_directories("lib/glad")
include_directories("lib/glfw/include")

add_subdirectory("lib/glfw")

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_compile_definitions(${PROJECT_NAME} PUBLIC GLAD_GL_IMPLEMENTATION=1)

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} glfw)
