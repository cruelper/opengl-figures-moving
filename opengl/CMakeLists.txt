cmake_minimum_required(VERSION 3.23)
project(opengl)

set(CMAKE_CXX_STANDARD 14)
set(OpenGlLinkers -lglut -lGLU -lGL -lglfw) # setting all the Glut libraries as one variable.


add_executable(opengl main.cpp buf.cpp)

target_link_libraries(opengl ${OpenGlLinkers}) # linking opengl libraries to the project