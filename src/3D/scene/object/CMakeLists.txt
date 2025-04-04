include_directories(../../../)

set(HEADERS
Object.hpp
ObjectSystem.hpp
)

set(SRCS
Object.cc
ObjectSystem.cc
)

add_library(object ${SRCS} ${HEADERS})