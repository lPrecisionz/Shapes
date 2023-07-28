cmake_minimum_required(VERSION 3.0.0)
project(Shapes VERSION 0.1.0 LANGUAGES C CXX)

# Find SDL2 package
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(Shapes ${SOURCES} ${HEADERS})

# Link SDL library
target_link_libraries(Shapes ${SDL2_LIBRARIES})