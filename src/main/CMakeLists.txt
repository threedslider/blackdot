include_directories(../)

add_executable(Blackdot main.cc)

target_link_libraries(Blackdot tool mesh object graphic opengl32 glu32 glfw3 glfw_wrapper )
