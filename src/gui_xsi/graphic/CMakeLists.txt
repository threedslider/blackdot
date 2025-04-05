set(HEADERS
Mouse.hpp
Viewport.hpp
ViewportSystem.hpp
)

set(SRCS
Mouse.cc
Viewport.cc
ViewportSystem.cc
)

add_library(graphic ${SRCS} ${HEADERS})