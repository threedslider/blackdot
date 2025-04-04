include_directories(../)
include_directories(../../)

set(HEADERS
Editor.hpp
)

set(SRCS
Editor.cc
)

add_library(glfw_wrapper ${SRCS} ${HEADERS})