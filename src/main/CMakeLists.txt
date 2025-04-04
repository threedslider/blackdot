include_directories(../)

add_executable(Blackdot main.cc)

target_link_libraries(Blackdot tool mesh oject graphic glfw_wrapper glfw)
