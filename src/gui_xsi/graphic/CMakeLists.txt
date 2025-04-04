set(HEADERS
Mouse.hpp
Viewport.hpp
ViewportSystem.hpp
)

set(SRCS
Viewport.cc
ViewportSystem.cc
)

add_library(graphic ${SRCS} ${HEADERS})