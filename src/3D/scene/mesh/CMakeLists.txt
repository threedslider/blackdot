include_directories(../../../)

set(HEADERS
Mesh.hpp
)

set(SRCS
Mesh.cc
)

add_library(mesh ${SRCS} ${HEADERS})