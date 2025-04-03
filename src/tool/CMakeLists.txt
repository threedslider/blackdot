set(HEADERS
Vector.hpp
Vector2.hpp
3D/Vertex.hpp
3D/Edge.hpp
3D/Face.hpp
)

set(SRCS
Vector.cc
Vector2.cc
3D/Vertex.cc
3D/Edge.cc
3D/Face.cc
)

add_library(tool ${SRCS} ${HEADERS})