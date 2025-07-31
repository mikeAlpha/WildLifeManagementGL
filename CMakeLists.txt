cmake_minimum_required(VERSION 3.10)
project(WildLifeGameGL)

set(CMAKE_CXX_STANDARD 17)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# GLFW
add_subdirectory(libs/glfw)
include_directories(libs/glfw/include)

# GLAD
add_library(glad libs/glad/src/glad.c)
include_directories(
libs/glad/include
libs/glm/glm-master
)

# Source files
file(GLOB SRC_FILES src/*.cpp)

add_executable(WildLifeGameGL ${SRC_FILES})
target_link_libraries(WildLifeGameGL glad glfw ${OPENGL_gl_LIBRARY})