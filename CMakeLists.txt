cmake_minimum_required(VERSION 3.28)

project(Blackdot)

set(CMAKE_CXX_STANDARD 20)

include_directories(../lib_blackdot/glfw/include)

link_directories(../lib_blackdot/glfw/lib/)

add_subdirectory(src)