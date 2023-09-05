cmake_minimum_required(VERSION 3.10)

project(Snekk)

# Add the include directory to the include path
include_directories(include)

# Add all the source files in the src directory to a variable
file(GLOB SOURCES "src/*.c")

# Create an executable target from the source files
add_executable(Snekk ${SOURCES})
