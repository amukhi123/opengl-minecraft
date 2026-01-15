cmake_minimum_required(VERSION 3.15)

project(opengl_minecraft)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

add_executable(${PROJECT_NAME} src/main.cpp)
